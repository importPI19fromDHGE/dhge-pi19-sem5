/*
	Zweck: Pipes ausprobieren
	Kommunikation zwischen Vater und Kind:
		K -> V: "Nein"
		V -> K: "Doch"
		K -> V: "Oh"
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
	// Zwei Pipes deklarieren
	//   pc = parent to child
	//   cp = child to parent
	int fdpc[2];
	int fdcp[2];

	if(pipe(fdpc) == -1 || pipe(fdcp) == -1){
		printf("pipe error\n");
		exit(EXIT_FAILURE);
	}

	// Kind-Prozess abspalten
	pid_t pid = fork();

	if(pid==-1){
		printf("fork error\n");
		exit(EXIT_FAILURE);
	}

	if(pid == 0){ // Kindprozess
		close(fdpc[1]); // nicht benötigtes Schreib-Ende der PC-Pipe schließen
		close(fdcp[0]); // nicht benötigtes Lese-Ende der CP-Pipe schließen

		// Nachricht an Vater-Prozess senden
		char msg[] = "Nein\n";
		write(fdcp[1], msg, strlen(msg));

		// Pipe auslesen -> in Buffer speichern und ausgeben
		char buf = '\0';
		while(buf != '\n' && read(fdpc[0], &buf, 1) > 0) printf("%c", buf); // Doch

		// Nachricht an Vater-Prozess senden
		char msg2[] = "Oh\n";
		write(fdcp[1], msg2, strlen(msg2));

		close(fdpc[0]); // PC-Pipe schließen (Lese-Ende)
		close(fdcp[1]); // CP-Pipe schließen (Schreib-Ende)
	}else{ // Vaterprozess
		close(fdpc[0]); // nicht benötigtes Lese-Ende der PC-Pipe schließen
		close(fdcp[1]); // nicht benötigtes Schreib-Ende der CP-Pipe schließen

		// Buffer zum Auslesen der Pipe
		char buf = '\0';
		// Pipe auslesen -> in Buffer speichern und ausgeben (bis \n)
		while(buf != '\n' && read(fdcp[0], &buf, 1) > 0) printf("%c", buf); // Nein

		// Nachricht an Kind-Prozess senden
		char msg[] = "Doch\n";
		write(fdpc[1], msg, strlen(msg));

		// Buffer zurücksetzen
		buf = '\0';

		// Pipe auslesen -> in Buffer speichern und ausgeben (bis \n)
		while(buf != '\n' && read(fdcp[0], &buf, 1) > 0 && buf != '\t') printf("%c", buf); // Oh

		close(fdpc[1]); // CP-Pipe schließen (Lese-Ende)
		close(fdcp[0]); // CP-Pipe schließen (Schreib-Ende)
	}

	fflush(stdout);
	return 0;
}
