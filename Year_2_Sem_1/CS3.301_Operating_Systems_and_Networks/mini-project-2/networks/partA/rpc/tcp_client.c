#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// #define TCP_PORT 8081
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int TCP_PORT = atoi(argv[1]);

    int sockfd;
    struct sockaddr_in server_addr;
    char buf[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(TCP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0)
    {
        perror("recv");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("[RESPONSE] %s", buf);

    int not_first_iteration = 0;

    while (1)
    {
        if (not_first_iteration)
        {
            printf("Play again? (y/n): ");
            char c = '\0';
            while (c != 'y' && c != 'n' && c != 'q')
            {
                scanf(" %c", &c);
                getchar();
                c = tolower((unsigned char)c);
                if (c != 'y' && c != 'n' && c != 'q')
                {
                    printf("Invalid input. Try again.\n");
                }
            }

            if (send(sockfd, &c, sizeof(c), 0) < 0)
            {
                perror("send");
                close(sockfd);
                exit(EXIT_FAILURE);
            }

            memset(buf, 0, sizeof(buf));

            if (recv(sockfd, buf, sizeof(buf), 0) < 0)
            {
                perror("recv");
                close(sockfd);
                exit(EXIT_FAILURE);
            }

            // printf("[RESPONSE FOR NEXT ROUND] %s", buf);

            if (strstr(buf, "ok"))
            {
                printf("\x1b[32mServer accepted, next round\x1b[0m\n");
            }
            else if (strstr(buf, "quit"))
            {
                printf("\x1b[31mPlayer %c is quitting\x1b[0m\n", buf[0]);
                break;
            }
        }
        else
        {
            not_first_iteration = 1;
        }

        char c = '\0';
        while (c != 'r' && c != 'p' && c != 's')
        {
            printf("Your move (r, p, s): ");
            scanf(" %c", &c);
            getchar();
            c = tolower((unsigned char)c);
            if (c != 'r' && c != 'p' && c != 's')
            {
                printf("Invalid move. Try again.\n");
            }
        }

        if (send(sockfd, &c, sizeof(c), 0) < 0)
        {
            perror("send");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        memset(buf, 0, sizeof(buf));
        if (recv(sockfd, buf, sizeof(buf), 0) < 0)
        {
            perror("recv");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        printf("[RESPONSE] %s", buf);
    }
    close(sockfd);
    return 0;
}
