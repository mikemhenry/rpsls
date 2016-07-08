#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAXRCVLEN 500
#define PORTNUM 2300

int main() {
  char buffer[MAXRCVLEN]; /* +1 so we can add null terminator */
  int len, mysocket;
  struct sockaddr_in dest;

  mysocket = socket(AF_INET, SOCK_STREAM, 0);

  memset(&dest, 0, sizeof(dest)); /* zero the struct */
  dest.sin_family = AF_INET;
  dest.sin_addr.s_addr = htonl(
      INADDR_LOOPBACK); /* set destination IP number - localhost, 127.0.0.1*/
  dest.sin_port = htons(PORTNUM); /* set destination port number */

  connect(mysocket, (struct sockaddr *)&dest, sizeof(struct sockaddr));

  len = recv(mysocket, buffer, MAXRCVLEN, 0);

  /* We have to null terminate the received data
   * ourselves */

  printf("Received %s (%d bytes).\n", buffer, len);

  close(mysocket);
  //return EXIT_SUCCESS;

  char *msg = "Hello World !\n\0";

  struct sockaddr_in dest_dest; /* socket info about the machine connecting to us */
  struct sockaddr_in serv; /* socket info about our server */
  int mysocket_dest;            /* socket used to listen for incoming connections */
  socklen_t socksize = sizeof(struct sockaddr_in);

  memset(&serv, 0,
         sizeof(serv));      /* zero the struct before filling the fields */
  serv.sin_family = AF_INET; /* set the type of connection to TCP/IP */
  serv.sin_addr.s_addr =
      htonl(INADDR_ANY);          /* set our address to any interface */
  serv.sin_port = htons(PORTNUM); /* set the server port number */

  mysocket_dest = socket(AF_INET, SOCK_STREAM, 0);

  /* bind serv information to mysocket */
  bind(mysocket_dest, (struct sockaddr *)&serv, sizeof(struct sockaddr));

  /* start listening, allowing a queue of up to 1 pending connection */
  listen(mysocket_dest, 1);
  int consocket = accept(mysocket_dest, (struct sockaddr *)&dest_dest, &socksize);

  while (consocket) {
    printf("Incoming connection from %s - sending welcome\n",
           inet_ntoa(dest_dest.sin_addr));
    send(consocket, msg, strlen(msg), 0);
    close(consocket);
    consocket = accept(mysocket_dest, (struct sockaddr *)&dest_dest, &socksize);
  }

  close(mysocket_dest);
  return EXIT_SUCCESS;
}
