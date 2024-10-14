#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>

// #define TCP_PORT 8081
#define BUFFER_SIZE 1024

struct tcp_client
{
    int sockfd;
    struct sockaddr_in address;
    char *choice;
};

typedef struct tcp_client tcp_client;

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

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <port1> <port2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int TCP_PORT1 = atoi(argv[1]);
    int TCP_PORT2 = atoi(argv[2]);

    int server_sockfd1, server_sockfd2;
    struct sockaddr_in server_addr1, server_addr2;
    int addrlen1 = sizeof(server_addr1);
    int addrlen2 = sizeof(server_addr2);

    char buf[BUFFER_SIZE];

    // 1st client
    server_sockfd1 = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd1 < 0)
    {
        perror("socket");
        close(server_sockfd1);
        exit(EXIT_FAILURE);
    }

    server_addr1.sin_family = AF_INET;
    server_addr1.sin_port = htons(TCP_PORT1);
    server_addr1.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sockfd1, (struct sockaddr *)&server_addr1, sizeof(server_addr1)) < 0)
    {
        perror("bind");
        close(server_sockfd1);
        close(server_sockfd2);
        exit(EXIT_FAILURE);
    }

    if (listen(server_sockfd1, 5) < 0)
    {
        perror("listen");
        close(server_sockfd1);
        close(server_sockfd2);
        exit(EXIT_FAILURE);
    }

    // 2nd client
    server_sockfd2 = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd2 < 0)
    {
        perror("socket");
        close(server_sockfd1);
        close(server_sockfd2);
        exit(EXIT_FAILURE);
    }

    server_addr2.sin_family = AF_INET;
    server_addr2.sin_port = htons(TCP_PORT2);
    server_addr2.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sockfd2, (struct sockaddr *)&server_addr2, sizeof(server_addr2)) < 0)
    {
        perror("bind");
        close(server_sockfd1);
        close(server_sockfd2);
        exit(EXIT_FAILURE);
    }

    if (listen(server_sockfd2, 5) < 0)
    {
        perror("listen");
        close(server_sockfd1);
        close(server_sockfd2);
        exit(EXIT_FAILURE);
    }

    tcp_client clients[2];

    for (int i = 0; i < 2; i++)
    {
        int sockfd;
        int addrlen;
        struct sockaddr_in addr;

        if (i == 0)
        {
            sockfd = accept(server_sockfd1, (struct sockaddr *)&addr, (socklen_t *)&addrlen1);
        }
        else
        {
            sockfd = accept(server_sockfd2, (struct sockaddr *)&addr, (socklen_t *)&addrlen2);
        }

        clients[i].sockfd = sockfd;
        clients[i].choice = malloc(sizeof(char));

        if (clients[i].sockfd < 0)
        {
            perror("accept");
            close(server_sockfd1);
            close(server_sockfd2);
            exit(EXIT_FAILURE);
        }

        char response[50];
        sprintf(response, "You are player %d\n", i + 1);
        if (send(clients[i].sockfd, response, strlen(response), 0) < 0)
        {
            perror("send");
            close(server_sockfd1);
            close(server_sockfd2);
            exit(EXIT_FAILURE);
        }

        printf("Player %d connected. Address: %s, Port: %d\n", i + 1, inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
    }

    int not_first_iter = 0, end_flag = 0;

    while (1)
    {
        if (not_first_iter != 0)
        {
            printf("Waiting for response\n");
            char msg[50];
            for (int i = 0; i < 2; i++)
            {
                char response[50];
                if (recv(clients[i].sockfd, response, sizeof(response), 0) < 0)
                {
                    perror("recv_ask");
                    close(server_sockfd1);
                    close(server_sockfd2);
                    exit(EXIT_FAILURE);
                }

                response[1] = '\0';
                response[0] = tolower((unsigned char)response[0]);

                if (strcmp(response, "y") == 0)
                {
                    printf("Player %d wants to play again\n", i + 1);
                }
                else if (strcmp(response, "n") == 0 || strcmp(response, "q") == 0)
                {
                    printf("Player %d wants to quit\n", i + 1);
                    end_flag = i + 1;
                }
            }

            if (end_flag != 0)
            {
                sprintf(msg, "%d quit\n", end_flag);
            }
            else
            {
                sprintf(msg, "ok");
            }

            for (int i = 0; i < 2; i++)
            {
                if (send(clients[i].sockfd, msg, strlen(msg), 0) < 0)
                {
                    perror("send");
                    close(server_sockfd1);
                    close(server_sockfd2);
                    exit(EXIT_FAILURE);
                }
                if (end_flag != 0)
                {
                    close(clients[i].sockfd);
                }
            }

            if (end_flag != 0)
            {
                exit(EXIT_SUCCESS);
            }
        }

        not_first_iter++;
        char **choices = malloc(sizeof(char *) * 2);
        for (int i = 0; i < 2; i++)
        {
            choices[i] = malloc(sizeof(char) * 10);
        }

        for (int i = 0; i < 2; i++)
        {
            memset(clients[i].choice, 0, sizeof(clients[i].choice));
            if (recv(clients[i].sockfd, clients[i].choice, sizeof(clients[i].choice), 0) < 0)
            {
                perror("recv");
                close(server_sockfd1);
                close(server_sockfd2);
                exit(EXIT_FAILURE);
            }

            if (clients[i].choice[0] == 'r')
            {
                strcpy(choices[i], "Rock");
                choices[i][4] = '\0';
                printf("Player %d choice: %s\n", i + 1, choices[i]);
            }
            else if (clients[i].choice[0] == 'p')
            {
                strcpy(choices[i], "Paper");
                choices[i][5] = '\0';
                printf("Player %d choice: %s\n", i + 1, choices[i]);
            }
            else if (clients[i].choice[0] == 's')
            {
                strcpy(choices[i], "Scissors");
                choices[i][8] = '\0';
                printf("Player %d choice: %s\n", i + 1, choices[i]);
            }
            else
            {
                // Should never happen
                printf("Player %d choice: Invalid\n", i + 1);
            }
        }

        char msg[BUFFER_SIZE * 2];
        int result = rockpaperscissors(*clients[0].choice, *clients[1].choice);
        if (result == 0)
        {
            printf("Draw!\n");
            sprintf(msg, "\x1b[90mDraw! (Both selected %s)\x1b[0m\n", choices[0]);
        }
        else if (result == 1)
        {
            printf("Player 1 wins!\n");
            sprintf(msg, "\x1b[33mPlayer 1 wins! (P1: %s vs P2: %s)\x1b[0m\n", choices[0], choices[1]);
        }
        else if (result == 2)
        {
            printf("Player 2 wins!\n");
            sprintf(msg, "\x1b[33mPlayer 2 wins! (P2: %s vs P1: %s)\x1b[0m\n", choices[1], choices[0]);
        }

        for (int i = 0; i < 2; i++)
        {
            if (send(clients[i].sockfd, msg, strlen(msg), 0) < 0)
            {
                perror("send");
                close(server_sockfd1);
                close(server_sockfd2);
                exit(EXIT_FAILURE);
            }
        }
    }
    close(server_sockfd1);
    close(server_sockfd2);
    return 0;
}
