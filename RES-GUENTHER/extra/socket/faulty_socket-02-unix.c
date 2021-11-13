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

#define SOCKET_NAME_S "serv234.socket"
#define SOCKET_NAME_C "client123.socket"
int main(int argc, char *argv[])
{
    printf("start \n");
    fflush(stdout);
    bool isServer=false;
    if  (argc>1 && strcmp(argv[1],"server")==0){
        isServer=true;
    }
    struct sockaddr_un caddr, saddr;
    char message[2000];
    int struct_length=0;
    printf("str %d\n",struct_length);
    memset(message, '\0', sizeof(message));

    int socketint;
    printf("init \n");
    fflush(stdout);

    socketint = socket(AF_UNIX, SOCK_DGRAM,0);
    if(socketint < 0){
        printf("Error while creating socket\n");
        fprintf(stderr, "error %s", strerror(errno));
        return -1;
    }

    //server
    saddr.sun_family = AF_UNIX;
    caddr.sun_family = AF_UNIX;
  //  unlink(SOCKET_NAME);
    strncpy(saddr.sun_path, SOCKET_NAME_S, sizeof(saddr.sun_path) - 1);
    strncpy(caddr.sun_path, SOCKET_NAME_C, sizeof(caddr.sun_path) - 1);

    printf("So \n");
    fflush(stdout);
    if (isServer){
        printf("Server \n");


        if(bind(socketint, (struct sockaddr*)&saddr, sizeof(saddr)) < 0){
            printf("Couldn't bind to the port\n");
            return -1;
        }
        struct_length = sizeof(caddr);
        printf("struct length %d\n",struct_length);
        //struct_length ist hier 110
        if (recvfrom(socketint, (char *)message, sizeof(message), 0,(struct sockaddr*)&caddr,(socklen_t*) &struct_length) < 0){
            printf("Couldn't receive\n");
            return -1;
        }else{
            printf("Msg from client: %s\n", message);
            printf("struct length %d\n",struct_length);
            //struct_length ist hier 0
            sleep(3);
            struct_length = sizeof(caddr);
            if(sendto(socketint, (const char *)"Hallo C", strlen("Hallo C"), 0,(const struct sockaddr*)&caddr, struct_length) < 0){
                printf("Server Unable to send message\n");
                fprintf(stderr, "error %s", strerror(errno));
                fprintf(stderr, "error %d\n", errno);
                goto end;
                return -1;
                }
            }
    }
    //Client
    else{
      //  sprintf(message,"Hallo Server");
       // printf("%s \n",message);
       // fflush(stdout);
        struct_length = sizeof(saddr);
        if(sendto(socketint, (const char *)"Hallo S", strlen("Hallo S"), 0,(const struct sockaddr*)&saddr, struct_length) < 0){
            printf("Unable to send message\n");
            fprintf(stderr, "error %s\n", strerror(errno));
            return -1;
        }else{
        struct_length = sizeof(saddr);
        if (recvfrom(socketint, (char *)message, sizeof(message), 0,(struct sockaddr*)&saddr, (socklen_t*) &struct_length) < 0){
            printf("Couldn't receive\n");
            return -1;
        }
        printf("Msg from Server: %s\n", message);
        }
    }
end:
    sleep(2);
    close(socketint);
    unlink(SOCKET_NAME_C);
    unlink(SOCKET_NAME_S);
    exit(EXIT_SUCCESS);
}
