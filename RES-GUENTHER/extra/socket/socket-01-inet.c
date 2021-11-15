/*
Schreiben Sie nun ein Programm (socket-01.c), welches einen Client und
einen Server realisiert (Client/Server Differenzierung per Parameterübergabe)
- Senden Sie vom Client eine Nachricht (z.B. „Hi Server“) an den Server
- Nutzen Sie die entsprechenden Systemaufrufe, insbesondere Sockets
- Verwenden Sie UDP
- Lassen Sie den Server die empfangene Nachricht ausgeben
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 3400
#define BUFSIZE 1024

int main(int argc, char *argv[]){
	int sockfd;
	char buffer[BUFSIZE];
	struct sockaddr_in servaddr, cliaddr;

	// Socket erstellen
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	// Server-Socket konfigurieren
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);

	if(argc == 2 && strcmp(argv[1], "server") == 0) {
		// Server-Socket an Port binden
		if(bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ){
			perror("bind failed");
			exit(EXIT_FAILURE);
		}

		printf("Hallo, ich bin der Server.\n");

		int len = sizeof(cliaddr);

		int n = recvfrom(sockfd, (char *)buffer, BUFSIZE, 0, (struct sockaddr *) &cliaddr, &len);
		buffer[n] = '\0';
		printf("Nachricht vom Client: %s\n", buffer);
	}else{
		char *msg = "Hallo Server!";
		// Nachricht an Server-Socket senden
		sendto(sockfd, (const char *) msg, strlen(msg), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));
		printf("Nachricht gesendet.\n");
	}

	return 0;
}
