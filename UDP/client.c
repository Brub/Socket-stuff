#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

  char *hello = "Hello from client";

  struct sockaddr_in servaddr = {0};
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(12345);
  servaddr.sin_addr.s_addr = INADDR_ANY;

  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  if (sockfd == -1) {
    perror("Failed to create socket");
    exit(EXIT_FAILURE);
  }

  int len = sendto(sockfd, (const char *)hello, strlen(hello), 0,
                   (const struct sockaddr *)&servaddr, sizeof(servaddr));
  if (len == -1) {
    perror("Failed to send");
  }

  close(sockfd);

  return 0;
}