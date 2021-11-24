#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 6000
#define IP "127.0.0.1"


static bool isServer=false;
static int connectiontype=IPPROTO_UDP;
struct sockaddr_in saddr, caddr;
char message[2000];
static int socketint;
static int struct_length;

int server(){

    printf("Server \n");

    if(bind(socketint, (struct sockaddr*)&saddr, sizeof(saddr)) < 0){
        printf("Couldn't bind to the port\n");
        return -1;
    }
    struct_length = sizeof(caddr);
    printf("Waiting for first Client message\n");
    if (recvfrom(socketint, (char *)message, sizeof(message), 0,(struct sockaddr*)&caddr, &struct_length) < 0){
        printf("Couldn't receive\n");
        return -1;
    }else{
        printf("### Msg from client: %s", message);
        fflush(stdout);
        //printf("struct length %d\n",struct_length);
        //struct_length ist hier 0
    }
    printf("Caddr saved, Have fun chatting!\n");
    pid_t cpid=fork();
    if (cpid==0){
        for(;;){
            struct_length = sizeof(caddr);
            if (recvfrom(socketint, (char *)message, sizeof(message), 0,(struct sockaddr*)&caddr, &struct_length) < 0){
                printf("Couldn't receive\n");
                return -1;
            }else{
                printf("### Msg from client: %s", message);
                fflush(stdout);
                memset(message, 0, sizeof(message));
                //printf("struct length %d\n",struct_length);
                //struct_length ist hier 0
            }
        }
    }else{
        for(;;){
            memset(message, 0, sizeof(message));
            struct_length = sizeof(caddr);
            //printf("input\n");
            fgets(message,sizeof(message),stdin);
            if(sendto(socketint, (const char *)message, strlen(message), 0,(const struct sockaddr*)&caddr, struct_length) < 0){
                printf("Server Unable to send message\n");
                fprintf(stderr, "error %s", strerror(errno));
                fprintf(stderr, "error %d\n", errno);
                return -1;
            }
        }
    }
}

int client(){
    pid_t cpid=fork();
    if (cpid==0){
        for(;;){
            memset(message, '\0', sizeof(message));
            struct_length = sizeof(caddr);
            //printf("input: ");
            fgets(message,sizeof(message),stdin);
            if(sendto(socketint, (const char *)message, strlen(message), 0,(const struct sockaddr*)&saddr, struct_length) < 0){
                printf("Unable to send message\n");
                fprintf(stderr, "error %d", errno);
                return -1;
            }
        }
    }else{
        for(;;){
            struct_length = sizeof(saddr);
            memset(message, 0, sizeof(message));
            if (recvfrom(socketint, (char *)message, sizeof(message), 0,(struct sockaddr*)&saddr, (socklen_t*) &struct_length) < 0){
                printf("Couldn't receive\n");
                return -1;
            }
        printf("### Msg from Server: %s", message);
        fflush(stdout);
        }
    }
}

int main(int argc, char *argv[])
{
    /*usage
     * Server:
     * ./socket server
     * Client:
     * ./socket
     *
     * not implemented yet:
     * ./socket IP
     * ./socket IP connectiontype
     * ./socket server IP
     * ./socket server IP connectiontype
     * */
    if  (argc>1 && strcmp(argv[1],"server")==0){
        isServer=true;
        if(argc>=3){
            //ip = argv[3]
        }
        if(argc==4){
            //connectiontype=strcmp(argv[4],"TCP")==0 ? IPPROTO_TCP : IPPROTO_UDP;
        }
    }else{ //Client
        if(argc>=2){
            //ip = argv[2]
        }
        if(argc==3){
            //connectiontype=strcmp(argv[3],"TCP")==0 ? IPPROTO_TCP : IPPROTO_UDP;
        }
    }

    memset(message, '\0', sizeof(message));
    socketint = socket(AF_INET, SOCK_DGRAM,connectiontype);
    if(socketint < 0){
        printf("Error while creating socket\n");
        fprintf(stderr, "error %s", strerror(errno));
        return -1;
    }
    saddr.sin_family = AF_INET; // IPv4
    inet_aton(IP, &saddr.sin_addr);
    saddr.sin_port = htons(PORT);

    //server
    if (isServer){
        server();
    }
    //Client
    else{
        client();

    }
    sleep(1);
    close(socketint);
    exit(EXIT_SUCCESS);
}
