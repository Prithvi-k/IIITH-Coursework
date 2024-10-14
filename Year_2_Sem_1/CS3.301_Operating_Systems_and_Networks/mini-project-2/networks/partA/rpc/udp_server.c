#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

struct udp_client
{
    int sockfd;
    struct sockaddr_in address;
    char *choice;
};

typedef struct udp_client udp_client;

int rockpaperscissors(char c1, char c2)
{
    c1 = tolower((unsigned char)c1);
    c2 = tolower((unsigned char)c2);

    if (c1 == c2)
    {
        return 0;
    }
    else if ((c1 == 'r' && c2 == 's') || (c1 == 's' && c2 == 'p') || (c1 == 'p' && c2 == 'r'))
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int main(char argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <port1> <port2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int PORT1 = atoi(argv[1]);
    int PORT2 = atoi(argv[2]);

    int sockfd1, sockfd2;
    struct sockaddr_in server_addr1, server_addr2, client_addr, client_addr2;
    char buffer[1024], buffer2[1024];

    sockfd1 = socket(AF_INET, SOCK_DGRAM, 0);
    sockfd2 = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd1 < 0 || sockfd2 < 0)
    {
        perror("Socket creation failed");
        close(sockfd1);
        close(sockfd2);
        exit(EXIT_FAILURE);
    }

    memset(&server_addr1, 0, sizeof(server_addr1));
    memset(&server_addr2, 0, sizeof(server_addr2));
    memset(&client_addr, 0, sizeof(client_addr));
    memset(&client_addr2, 0, sizeof(client_addr2));

    server_addr1.sin_family = AF_INET;
    server_addr1.sin_addr.s_addr = INADDR_ANY;
    server_addr1.sin_port = htons(PORT1);

    server_addr2.sin_family = AF_INET;
    server_addr2.sin_addr.s_addr = INADDR_ANY;
    server_addr2.sin_port = htons(PORT2);

    // Bind the sockets to their respective ports
    if (bind(sockfd1, (const struct sockaddr *)&server_addr1, sizeof(server_addr1)) < 0)
    {
        perror("Binding failed for port 1");
        close(sockfd1);
        exit(EXIT_FAILURE);
    }

    if (bind(sockfd2, (const struct sockaddr *)&server_addr2, sizeof(server_addr2)) < 0)
    {
        perror("Binding failed for port 2");
        close(sockfd1);
        close(sockfd2);
        exit(EXIT_FAILURE);
    }

    // Get a dummy message from the clients to establish connection

    int len = sizeof(client_addr), len2 = sizeof(client_addr2);

    int n = recvfrom(sockfd1, (char *)buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &len);
    buffer[n] = '\0';

    int n2 = recvfrom(sockfd2, (char *)buffer2, sizeof(buffer), 0, (struct sockaddr *)&client_addr2, &len2);
    buffer2[n2] = '\0';

    printf("Server listening on ports %d and %d\n", PORT1, PORT2);

    if (sendto(sockfd1, "You are Player 1\n", strlen("You are Player 1\n"), 0, (const struct sockaddr *)&client_addr, sizeof(client_addr)) < 0)
    {
        perror("sendto");
        close(sockfd1);
        close(sockfd2);
        exit(EXIT_FAILURE);
    }

    if (sendto(sockfd2, "You are Player 2\n", strlen("You are Player 2\n"), 0, (const struct sockaddr *)&client_addr2, sizeof(client_addr2)) < 0)
    {
        perror("sendto");
        close(sockfd1);
        close(sockfd2);
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        int len = sizeof(client_addr), len2 = sizeof(client_addr2);

        int n = recvfrom(sockfd1, (char *)buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &len);
        buffer[n] = '\0';

        n = recvfrom(sockfd2, (char *)buffer2, sizeof(buffer), 0, (struct sockaddr *)&client_addr2, &len2);
        buffer2[n] = '\0';
        if (strcmp(buffer, "y") == 0 && strcmp(buffer2, "y") == 0)
        {
            if (sendto(sockfd1, "Next Round", strlen("Next Round"), 0, (const struct sockaddr *)&client_addr, len) < 0)
            {
                perror("sendto");
                close(sockfd1);
                close(sockfd2);
                exit(EXIT_FAILURE);
            }
            if (sendto(sockfd2, "Next Round", strlen("Next Round"), 0, (const struct sockaddr *)&client_addr2, len2) < 0)
            {
                perror("sendto");
                close(sockfd1);
                close(sockfd2);
                exit(EXIT_FAILURE);
            }
            printf("Next round!\n");
            continue;
        }

        printf("Received message from client 1: %s\n", buffer);
        printf("Received message from client 2: %s\n", buffer2);

        if (strcmp(buffer, "n") == 0)
        {
            printf("Client 1 quit.\n");
            if (sendto(sockfd2, "1 quit", strlen("1 quit"), 0, (const struct sockaddr *)&client_addr2, len2) < 0)
            {
                perror("sendto");
                close(sockfd1);
                close(sockfd2);
                exit(EXIT_FAILURE);
            }
            close(sockfd1);
            close(sockfd2);
            exit(EXIT_SUCCESS);
        }

        if (strcmp(buffer2, "n") == 0)
        {
            printf("Client 2 quit.\n");
            if (sendto(sockfd1, "2 quit", strlen("2 quit"), 0, (const struct sockaddr *)&client_addr, len) < 0)
            {
                perror("sendto");
                close(sockfd1);
                close(sockfd2);
                exit(EXIT_FAILURE);
            }

            close(sockfd1);
            close(sockfd2);
            exit(EXIT_SUCCESS);
        }

        int result = rockpaperscissors(buffer[0], buffer2[0]);
        char msg[BUFFER_SIZE * 2];
        if (result == 0)
        {
            printf("Draw!\n");
            sprintf(msg, "\x1b[90mDraw!\x1b[0m\n");
        }
        else if (result == 1)
        {
            printf("Player 1 wins!\n");
            sprintf(msg, "\x1b[33mPlayer 1 wins! (P1: %c vs P2: %c)\x1b[0m\n", buffer[0], buffer2[0]);
        }
        else if (result == 2)
        {
            printf("Player 2 wins!\n");
            sprintf(msg, "\x1b[33mPlayer 2 wins! (P2: %c vs P1: %c)\x1b[0m\n", buffer[0], buffer2[0]);
        }

        if (sendto(sockfd1, (const char *)msg, strlen(msg), 0, (const struct sockaddr *)&client_addr, len) < 0)
        {
            perror("sendto");
            close(sockfd1);
            close(sockfd2);
            exit(EXIT_FAILURE);
        }
        if (sendto(sockfd2, (const char *)msg, strlen(msg), 0, (const struct sockaddr *)&client_addr2, len2) < 0)
        {
            perror("sendto");
            close(sockfd1);
            close(sockfd2);
            exit(EXIT_FAILURE);
        }
    }
    close(sockfd1);
    close(sockfd2);
    return 0;
}
