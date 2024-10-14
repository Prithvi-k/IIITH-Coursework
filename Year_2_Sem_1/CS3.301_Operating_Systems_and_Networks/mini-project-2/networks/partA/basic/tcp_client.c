#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TCP_PORT 8081
#define BUFFER_SIZE 1024

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    char buf[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(TCP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        char c;
        memset(buf, 0, sizeof(buf));
        printf("Do you want to send a message? (y/n/q to quit)\n");
        scanf(" %c", &c);
        getchar();
        if (c == 'y')
        {
            printf("Enter a message: ");
            fgets(buf, sizeof(buf), stdin);
            if (send(sockfd, buf, strlen(buf), 0) < 0)
            {
                perror("send");
                exit(EXIT_FAILURE);
            }
        }
        else if (c == 'n')
        {
            printf("Goodbye!\n");
            break;
        }
        else if (c == 'q')
        {
            strcpy(buf, "END");
            if (send(sockfd, buf, strlen(buf), 0) < 0)
            {
                perror("send");
                exit(EXIT_FAILURE);
            }
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid input!\n");
        }

        memset(buf, 0, sizeof(buf));
        if (recv(sockfd, buf, sizeof(buf), 0) < 0)
        {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        printf("[RESPONSE] %s", buf);
    }
    close(sockfd);
    return 0;
}
