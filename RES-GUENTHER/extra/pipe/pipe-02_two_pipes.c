/*Zweck: Pipes ausprobieren
	Nachricht von Vater-Prozess zu Kind-Prozess senden.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
	int pipepc[2];
	int pipecp[2];

	if(pipe(pipepc) == -1 || pipe(pipecp) == -1){
		printf("pipe error\n");
		exit(EXIT_FAILURE);
	}

	pid_t pid = fork();

	if(pid==-1){
		printf("fork error\n");
		exit(EXIT_FAILURE);
	}

	setbuf(stdout, NULL);

	if(pid == 0){ // Kindprozess
		close(pipepc[1]); // nicht benötigtes Schreib-Ende der PC-Pipe schließen
		close(pipecp[0]); // nicht benötigtes Lese-Ende der CP-Pipe schließen

		// Pipe auslesen -> in Buffer speichern und ausgeben
		char buf;
		while(read(pipepc[0], &buf, 1) > 0) printf("%c", buf);

		char msg[] = "Ich bin dein Sohn\n";
		write(pipecp[1], msg, strlen(msg));

		close(pipepc[0]); // PC-Pipe schließen
		close(pipecp[1]); // CP-Pipe schließen -> EOF marker
	}else{ // Vaterprozess
		close(pipepc[0]); // nicht benötigtes Lese-Ende der PC-Pipe schließen
		close(pipecp[1]); // nicht benötigtes Schreib-Ende der CP-Pipe schließen

		char msg[] = "Ich bin dein Vater\n";
		write(pipepc[1], msg, strlen(msg));
		close(pipepc[1]); // PC-Pipe schließen -> EOF marker

		// Pipe auslesen -> in Buffer speichern und ausgeben
		char buf;
		while(read(pipecp[0], &buf, 1) > 0) printf("%c", buf);

		close(pipepc[0]); // CP-Pipe schließen
	}

	fflush(stdout);
	return 0;
}

