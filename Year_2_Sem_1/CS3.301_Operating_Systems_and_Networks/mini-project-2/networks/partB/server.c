#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

struct packet
{
    int seq_no;
    char *data;
};

typedef struct packet packet;

int main(char argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int UDP_PORT = atoi(argv[1]);

    int server_socket_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    server_socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket_fd < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(UDP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost

    if (bind(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    socklen_t client_addr_len = sizeof(client_addr);
    int received_bytes = recvfrom(server_socket_fd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_len);
    if (received_bytes < 0)
    {
        perror("recvfrom");
        exit(1);
    }
    // printf("[RECEIVED]: %s, %ld, %d\n", buffer, strlen(buffer), received_bytes);

    int chunk_size, num_chunks;
    sscanf(buffer, "%d-%d", &chunk_size, &num_chunks);
    printf("[TRANSMISSION DETAILS]: %d chunks of size %d bytes\n", num_chunks, chunk_size);

    packet **arr = (packet **)malloc(num_chunks * sizeof(packet *));

    for (int i = 0; i < num_chunks; i++)
    {
        packet *p = (packet *)malloc(sizeof(packet));
        p->data = (char *)malloc(chunk_size + 2);
        char *buffer_store = (char *)malloc(chunk_size + 10);
        received_bytes = recvfrom(server_socket_fd, buffer_store, sizeof(buffer_store), 0, (struct sockaddr *)&client_addr, &client_addr_len);
        if (received_bytes < 0)
        {
            perror("recvfrom");
            exit(1);
        }
        buffer_store[strlen(buffer_store)] = '\0';
        sscanf(buffer_store, "%d_%s", &p->seq_no, p->data);
        // printf("[RECEIVED]: %d, ~%s~\n", p->seq_no, p->data);

        arr[p->seq_no] = p;

        // Send ACK
        if (sendto(server_socket_fd, &p->seq_no, sizeof(p->seq_no), 0, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0)
        {
            perror("sendto");
            exit(1);
        }
    }

    char *string = (char *)malloc((num_chunks * chunk_size) + 1);
    string[0] = '\0';
    for (int i = 0; i < num_chunks; i++)
    {
        packet *p = arr[i];
        // printf("[RECEIVED]: %d, `%s`\n", p->seq_no, p->data);
        if (strstr(p->data, "`") != NULL)
        {
            for (int i = 0; i < strlen(p->data); i++)
            {
                if (p->data[i] == '`')
                {
                    p->data[i] = ' ';
                }
            }

            // printf("[RECEIVED - Modified]: %d, ~%s~\n", p->seq_no, p->data);
        }
        strcat(string, p->data);
    }
    printf("[RECEIVED]: %s\n", string);

    close(server_socket_fd);
    return 0;
}