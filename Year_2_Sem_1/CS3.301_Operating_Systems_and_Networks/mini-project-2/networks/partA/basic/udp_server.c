#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TCP_PORT 8000
#define BUFFER_SIZE 1024

int main()
{
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
    server_addr.sin_port = htons(TCP_PORT);
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
    printf("Received: %s", buffer);
    buffer[received_bytes - 1] = '\0';

    char reply[BUFFER_SIZE * 2];
    sprintf(reply, "Server received: `%s`\n", buffer);
    if (sendto(server_socket_fd, reply, strlen(reply), 0, (struct sockaddr *)&client_addr, client_addr_len) < 0)
    {
        perror("sendto");
        exit(1);
    }

    printf("Sent: %s", reply);
    close(server_socket_fd);
    return 0;
}