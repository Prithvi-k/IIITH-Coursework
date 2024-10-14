#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int UDP_PORT = atoi(argv[1]);

    int sockfd;
    struct sockaddr_in server_addr;
    char buf[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(UDP_PORT);
    inet_pton(AF_INET, argv[1], &(server_addr.sin_addr));

    printf("Connected to server.\n");

    // Send a dummy message to the server to get the game started
    if (sendto(sockfd, "dummy", sizeof("dummy"), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("sendto");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    memset(buf, 0, sizeof(buf));
    socklen_t addrlen = sizeof(server_addr);
    if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&server_addr, &addrlen) < 0)
    {
        perror("recvfrom");
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

            if (sendto(sockfd, &c, sizeof(c), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
            {
                perror("sendto");
                close(sockfd);
                exit(EXIT_FAILURE);
            }

            if (c == 'q')
            {
                printf("Quitting...\n");
                break;
            }
            else if (c == 'n')
            {
                printf("Thanks for playing!\n");
                break;
            }

            memset(buf, 0, sizeof(buf));
            if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&server_addr, &addrlen) < 0)
            {
                perror("recvfrom");
                close(sockfd);
                exit(EXIT_FAILURE);
            }

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

        if (sendto(sockfd, &c, sizeof(c), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        {
            perror("sendto");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        memset(buf, 0, sizeof(buf));
        if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&server_addr, &addrlen) < 0)
        {
            perror("recvfrom");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        printf("[RESPONSE] %s", buf);
    }

    close(sockfd);

    return 0;
}
