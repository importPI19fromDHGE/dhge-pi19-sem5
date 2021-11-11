/*
pipe-01.c zeig eine Kommunikation zwischen zwei Prozessen, wobei der Vater-Prozess dem Kind-Prozess eine Nachricht schickt,
die dann auf STDOUT ausgegeben wird.
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h> // Standard Ein- und Ausgabe
#include <stdlib.h> // EXIT_FAILURE, EXIT_SUCCESS etc.
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2]; // declare a read-write pipe
    pid_t cpid; // declare a variable for our child PID
    char buf; // buffer where we'll write our message


    cpid = fork(); // create child process
    if (cpid < 0) { // handle process creation error
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) { // child reads pipe
        close(pipefd[1]); // close write pipe, we don't need it in the child process
        while (read(pipefd[0], &buf, 1) > 0) // read from pipe until we receive EOF
            write(STDOUT_FILENO, &buf, 1); // output to stdout
        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]); // close the read-pipe
        _exit(EXIT_SUCCESS); // exit from child process
    } else { // parent writes pipe
        close(pipefd[0]); // close read pipe, we don't need it in the parent process
        write(pipefd[1], "Ich bin dein Vater!", strlen("Ich bin dein Vater!"));
        close(pipefd[1]); // reader will see EOF
        wait(NULL); // wait for child
        exit(EXIT_SUCCESS); // exit from parent process
    }

    return 0;
}
