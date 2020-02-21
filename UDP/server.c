#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  char buffer[50] = {0};

  //
  struct sockaddr_in servaddr = {0};
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(12345);
  servaddr.sin_addr.s_addr = INADDR_ANY;

  //
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("Failed to create socket");
    exit(EXIT_FAILURE);
  }

  //
  int rc = bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));
  if (rc == -1) {
    perror("Failed to bind");
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  socklen_t len = 0;

  int n = recvfrom(sockfd, (char *)buffer, 50, MSG_WAITALL, 0, &len);
  buffer[n] = '\n';
  printf("%s", buffer);

  // close the socket
  close(sockfd);
  return 0;
}