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
#define BUFSIZE 1024 // Größe des Buffers für Nachrichten

int main(int argc, char *argv[]){
	int sockfd;
	char buffer[BUFSIZE];
	struct sockaddr_in servaddr, cliaddr;

	// Socket erstellen und auf Fehler prüfen
	// Mögliche Fehler: Speicherfehler, Socket schon vorhanden, keine Rechte
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	// Server-Socket konfigurieren über struct
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY; // erlaube jede incoming message (von jedem Interface)
	servaddr.sin_port = htons(PORT); // Port (konvertiere von host zu network byte order)

	// Paramter prüfen -> Soll ein Server gestartet werden?
	if(argc == 2 && strcmp(argv[1], "server") == 0) {
		// Server-Socket an Port binden und auf Fehler prüfen
		if(bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ){
			perror("bind failed");
			exit(EXIT_FAILURE);
		}
		// Debug-Ausgabe für Konsole
		printf("Hallo, ich bin der Server.\n");

		int len = sizeof(cliaddr);

		// warte, bis Client eine Nachricht sendet; Schreibe sie in den Buffer
		int n = recvfrom(sockfd, (char *)buffer, BUFSIZE, 0, (struct sockaddr *) &cliaddr, &len);
		// Nachricht im Buffer als String terminieren
		buffer[n] = '\0';
		// Nachricht auf Konsole ausgeben
		printf("Nachricht vom Client: %s\n", buffer);
	}else{
		char *msg = "Hallo Server!";
		// sende den Inhalt von msg an den Server (schreibe ihn in den Socket)
		sendto(sockfd, (const char *) msg, strlen(msg), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));
		printf("Nachricht gesendet.\n");
	}

	return 0;
}
