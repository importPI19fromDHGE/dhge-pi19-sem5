/* Dieses File ist keine valide Lösung für socket-01-unix.c
Es ist als Exkurs in die AF_UNIX Sockets zur IPC zu verstehen.
siehe PR #87, lange Diskussion, weitere Infos
*/
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <errno.h>

#define SOCKET_NAME "/tmp/23045r934bgwer4g.socket"
int main(int argc, char *argv[])
{
    printf("start \n");
    fflush(stdout);
    // if argument 1 == "server", we are the server
    bool isServer=false;
    if  (argc>1 && strcmp(argv[1],"server")==0){
        isServer=true;
    }
    // this struct manages our socket
    struct sockaddr_un addr;
    // the buffer we write data to
    char message[2000];
    int struct_length = sizeof(addr);

    // clear message buffer
    memset(message, '\0', sizeof(message));

    // socket ID that is generated, when socket is created
    int socketint;
    printf("init \n");
    fflush(stdout);

    // create a dgram socket in the unix domain
    socketint = socket(AF_UNIX, SOCK_DGRAM,0);
    if(socketint < 0){
        printf("Error while creating socket\n");
        fprintf(stderr, "error %s", strerror(errno));
        return -1;
    }
    // define socket type
    addr.sun_family = AF_UNIX;

    // set socket filename/path
    strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);
    printf("So \n");
    fflush(stdout);
    // server
    if (isServer){
        printf("Server \n");

        // bind the socket
        if(bind(socketint, (struct sockaddr*)&addr, sizeof(addr)) < 0){
            printf("Couldn't bind to the port\n");
            return -1;
        }
        int struct_length = sizeof(addr);
        // wait for a message to arrive and write it to the message buffer
        if (recvfrom(socketint, (char *)message, sizeof(message), 0,(struct sockaddr*)&addr, &struct_length) < 0){
            printf("Couldn't receive\n");
            return -1;
        }
        printf("Msg from client: %s\n", message);
        close(socketint);
    }
    // client
    else{
        sprintf(message,"Hallo Server");
        printf("%s \n",message);
        fflush(stdout);

        // write the contents of the message buffer to the socket, effectively sending it
        if(sendto(socketint, (const char *)message, strlen(message), 0,(const struct sockaddr*)&addr, struct_length) < 0){
            printf("Unable to send message\n");
            fprintf(stderr, "error %d", errno);
            return -1;
        }
    }
    close(socketint);
    unlink(SOCKET_NAME);
    exit(EXIT_SUCCESS);

}
