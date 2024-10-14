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
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    char buf[BUFFER_SIZE];

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(TCP_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sockfd, 5) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);

    if (client_sockfd < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Client connected. Address: %s, Port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1)
    {
        char c;
        memset(buf, 0, sizeof(buf));
        if (recv(client_sockfd, buf, sizeof(buf), 0) < 0)
        {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        if (strcmp(buf, "END") == 0)
        {
            printf("Client disconnected.\n");
            break;
        }
        
        printf("Message received from client: %s", buf);

        char msg[BUFFER_SIZE * 2];

        sprintf(msg, "Server received message: `%s`", buf);

        if (send(client_sockfd, msg, strlen(msg), 0) < 0)
        {
            perror("send");
            exit(EXIT_FAILURE);
        }
    }

    close(client_sockfd);
    close(server_sockfd);

    return 0;
}
