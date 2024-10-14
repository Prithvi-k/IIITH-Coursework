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
    int sockfd;
    struct sockaddr_in udp_address;
    char *string = "Hello, World!\n", buffer[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("Error opening socket");
        exit(1);
    }

    memset(&udp_address, 0, sizeof(udp_address));
    udp_address.sin_family = AF_INET;
    udp_address.sin_port = htons(TCP_PORT);
    udp_address.sin_addr.s_addr = INADDR_ANY;

    n = sendto(sockfd, string, strlen(string), 0, (struct sockaddr *)&udp_address, sizeof(udp_address));
    if (n < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    printf("[SENT] %s", string);

    int udp_address_len = sizeof(udp_address);
    n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&udp_address, &udp_address_len);
    if (n == -1)
    {
        perror("Error receiving message");
        exit(1);
    }

    buffer[n] = '\0';
    printf("[RESPONSE] %s", buffer);

    close(sockfd);
    return 0;
}