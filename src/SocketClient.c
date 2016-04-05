/*
 ============================================================================
 Name        : Client.c
 Author      : Ivan Klymchuk
 Version     : 1.0
 Copyright   : Feel free to use
 Description : Client for socket server
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
//add 2 additional libs for socket
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

/*
 * Two type of socket: request - response
 * Client - server architecture
 */
int main(int argc, char *argv[]) {

    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == -1) {
        puts("Bad response");
    } else {

    struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(48999);
        server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(socket_desc, (struct sockaddr *) &server, sizeof(server));

    char * message = argv[1];

    send(socket_desc, message, strlen(message), 0);

    char server_response[40960];
    recv(socket_desc, server_response, 40960, 0);

    puts(server_response);
    close(socket_desc);

    return EXIT_SUCCESS;
    }
}
