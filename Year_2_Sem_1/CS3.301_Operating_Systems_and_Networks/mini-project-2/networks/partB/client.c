#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024

typedef struct packet packet;

struct packet
{
    int seq_no;
    time_t start_time;
    char *data;
    packet *next;
};

int check_if_node_exists(packet *head, int seq_no)
{
    packet *temp = head->next;
    while (temp != NULL)
    {
        if (temp->seq_no == seq_no)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void add_node(packet *head, int seq_no, char *data)
{
    if (check_if_node_exists(head, seq_no))
    {
        printf("Node with seq_no %d already exists!\n", seq_no);
        return;
    }
    packet *new_node = (packet *)malloc(sizeof(packet));
    new_node->seq_no = seq_no;
    new_node->data = data;
    new_node->start_time = time(NULL);
    new_node->next = NULL;

    packet *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

int check_transmission(packet *head)
{
    packet *temp = head->next;
    while (temp != NULL)
    {
        if (time(NULL) - temp->start_time > 1)
        {
            printf("Timeout occurred! Resending chunk %d\n", temp->seq_no);
            temp->start_time = time(NULL);
            return temp->seq_no;
        }
        temp = temp->next;
    }
    return -1;
}

void remove_node(packet *head, int seq_no)
{
    packet *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->seq_no == seq_no)
        {
            packet *to_delete = temp->next;
            packet *temp_2 = to_delete->next;
            temp->next = temp_2;
            free(to_delete);
            return;
        }
        temp = temp->next;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int UDP_PORT = atoi(argv[1]);

    int sockfd;
    struct sockaddr_in udp_address;
    char *string, buffer[BUFFER_SIZE];
    string = (char *)malloc(BUFFER_SIZE);
    int n;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("Error opening socket");
        exit(1);
    }

    int flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

    printf("Enter a string: ");
    scanf("%[^\n]%*c", string);

    // Split string into chunks of fixed size
    int chunk_size = 4;
    int num_chunks = strlen(string) / chunk_size;
    // printf("strlen(string) = %ld\n", strlen(string));
    if (strlen(string) % chunk_size != 0)
    {
        num_chunks++;
    }

    printf("Sending %d chunks of size %d\n", num_chunks, chunk_size);

    memset(&udp_address, 0, sizeof(udp_address));
    udp_address.sin_family = AF_INET;
    udp_address.sin_port = htons(UDP_PORT);
    udp_address.sin_addr.s_addr = INADDR_ANY;

    // Send server the number of chunks and chunk size
    char num_chunks_str[10];
    sprintf(num_chunks_str, "%d-%d", chunk_size, num_chunks);
    // printf("Sending: %s\n", num_chunks_str);
    n = sendto(sockfd, num_chunks_str, strlen(num_chunks_str), 0, (struct sockaddr *)&udp_address, sizeof(udp_address));
    if (n < 0)
    {
        perror("Error sending message: num_chunks_str");
        exit(1);
    }

    int total_chunks_sent = 0, *check_arr = (int *)malloc(num_chunks * sizeof(int));

    for (int i = 0; i < num_chunks; i++)
    {
        check_arr[i] = 0;
    }

    packet *head = (packet *)malloc(sizeof(packet));
    head->seq_no = -1;
    head->start_time = 0;
    head->data = NULL;
    head->next = NULL;

    int i = 0, check_transmission_status = 0;

    while (total_chunks_sent < num_chunks)
    {
        if (i != 0)
        {
            check_transmission_status = check_transmission(head);
            if (check_transmission_status != -1)
            {
                i = check_transmission_status;
            }
        }

        if (check_arr[i] == 1)
        {
            i++;
            continue;
        }

        int num_digits = 1;
        int temp_i = i;
        while (temp_i >= 10)
        {
            temp_i /= 10;
            num_digits++;
        }

        // Allocate memory for the chunk including space for the number_str
        char *chunk = (char *)malloc(chunk_size + num_digits + 3);

        // Convert the integer i to a string (number_str)
        char number_str[num_digits + 1];
        snprintf(number_str, num_digits + 1, "%d", i);

        // Place the number_str and '_' in the chunk
        int index = 0;
        for (int j = 0; j < num_digits; j++)
        {
            chunk[index++] = number_str[j];
        }
        chunk[index++] = '_';

        // Copy the string content to the chunk
        for (int j = 0; j < chunk_size; j++)
        {
            chunk[index++] = string[(i * chunk_size) + j];
        }

        // Replace spaces with '`'
        for (int i = 0; i < (chunk_size + num_digits + 1); i++)
        {
            if (chunk[i] == ' ')
            {
                chunk[i] = '`';
            }
        }

        // printf("Sending %d - [%s]", i, chunk);
        n = sendto(sockfd, chunk, strlen(chunk), 0, (struct sockaddr *)&udp_address, sizeof(udp_address));
        if (n < 0)
        {
            perror("Error sending message: chunk");
            exit(1);
        }

        add_node(head, i, chunk);
        struct timeval timeout_for_select;
        timeout_for_select.tv_sec = 1; // Set seconds to 1 for a 1-second delay
        timeout_for_select.tv_usec = 0;

        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        int select_status = select(sockfd + 1, &readfds, NULL, NULL, &timeout_for_select);

        if (select_status == -1)
        {
            perror("Error in select");
            exit(1);
        }
        else if (select_status == 0)
        {
            // Do nothing
        }
        else
        {
            // Receive response
            int udp_address_len = sizeof(udp_address), chunk_num;
            n = recvfrom(sockfd, &chunk_num, sizeof(chunk_num), 0, (struct sockaddr *)&udp_address, &udp_address_len);
            if (n < 0)
            {
                perror("Error receiving message");
                exit(1);
            }
            printf("[ACK] %d\n", chunk_num);

            remove_node(head, chunk_num);
            check_arr[chunk_num] = 1;
            total_chunks_sent++;
        }
        i++;

        i = i % num_chunks;
    }
    close(sockfd);
    return 0;
}