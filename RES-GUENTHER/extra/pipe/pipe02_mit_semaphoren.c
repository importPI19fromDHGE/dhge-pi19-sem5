/*
 * Zweck des Programms:
 * demonstriert die Funktion von Pipes zur Interprozesskommunikation, indem der Vaterprozess dem Kindprozess eine Konstante MSGKIND ("Chrrr Chrrr").
 * Mithilfe einer Pipe. Der Kindprozess gibt diese Zeichenkette aus. Anschließend gibt der Kindprozess
 * Zusätzlich werden Semaphoren verwendet, damit garantiert zuerst geschrieben und dann gelesen wird.
 */

#include <stdio.h> // inkludiert Standard-Ein-Ausgabe
#include <sys/unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h> // Sys-V Semaphoren
#include <sys/stat.h>
#include <sys/wait.h>

#define BUFSIZE 80
#define MSGKIND "Chrrr Chrrr"
#define MSGVATER "Nooooooooo!"

#define KEY1 0x1FC4F
#define KEY2 0x1FC50
#define PERM 0611 // Schreibrechte nur für Besitzer

// static bei globalen Variablen, Funktionen, ...: Sichtbarkeit auf Übersetzungseinheit beschränkt
static struct sembuf semaphore; //struct sembuf wird statically als semaphore zugewiesen
int semid1; //ID der verwendeten Semaphore
int semid2;

static int init_semaphore(int* semid, key_t key); // initialisiert Semaphore und speichert in semid1
static void sema_operation(const int* semid, short op); // sperrt oder entsperrt die Semaphore, genauer gesagt zieht sie eine Res. ab oder fügt sie wieder hinzu

int main() {
    int pipefd[2]; // deklariert Pipe-Array für pipe()
    char buf[BUFSIZE]; // deklariert Puffervariable und reserviert dessen Speicher auf dem Stack (vielleicht nicht meine beste Idee)
    int msgsize1 = strlen(MSGKIND); // die Größe der Nachricht brauchen wir mehrfach - abspeichern!
    int msgsize2 = strlen(MSGVATER);
    if ((msgsize1 > BUFSIZE - 1) || (msgsize2 > BUFSIZE - 1)) { // Sicherheitsgurt: es wird abgebrochen, falls der Puffer zu klein ist, um die Nachricht zu speichern
                             // (wir haben zwar Speicherschutz im OS, aber müssen das ja nicht herausfordern)
        perror("Nachrichtengröße überschreitet Puffergröße: kann nicht fortfahren!\n");
        return(EXIT_FAILURE);
    }

    if (init_semaphore(&semid1, KEY1) != 0) { // brich ab, wenn das Initialisieren der Semaphore 1 fehlgeschlagen ist
        return EXIT_FAILURE;
    }

    if (init_semaphore(&semid2, KEY2) != 0) { // brich ab, wenn das Initialisieren der Semaphore 2 fehlgeschlagen ist
        return EXIT_FAILURE;
    }

    if (pipe(pipefd) == -1) { // brich ab, wenn das Erstellen der Pipe fehlgeschlagen ist
        perror("Fehler beim Erzeugen der Pipe\n");
        return(EXIT_FAILURE);
    }

    switch (fork()) { // Fork hat drei Rückgabetypen...
        case -1: // Fehler
            perror("Fehler beim Forken\n");
            return(EXIT_FAILURE);
        case 0: // wir sind das Kind
            sema_operation(&semid1, -1); // versucht, Semaphore zu sperren, bevor gelesen wird, um sicherzustellen, dass auch schon geschrieben wurde
            read(pipefd[0], buf, msgsize1); // Die Pipe wird am lesenden Ende "[0]" geöffnet und schreibt msgsize1 Bytes in buf
            buf[msgsize1] = '\0'; // Setze String-Terminator, damit kein Bitsalat aus dem un-initialisierten Puffer mitgelesen wird
            printf("%s\n", buf); // schreibt den Puffer auf stdout

            // Rollenwechsel

            write(pipefd[1], MSGVATER, msgsize2);
            //sleep(1);
            sema_operation(&semid2, 1);

            break;
        default: // >0 d.h. wir sind der Vater
            write(pipefd[1], MSGKIND, msgsize1); // öffnet Pipe am schreibenden Ende und liest msgsize1 Bytes in die Pipe ein.
            sema_operation(&semid1, 1); // gibt Semaphore frei, nachdem geschrieben wurde

            // Rollenwechsel

            sema_operation(&semid2, -1); // versucht, 2. Semaphore zu sperren, damit das Kind in Ruhe schreiben kann
            read(pipefd[0], buf, msgsize2);
            buf[msgsize2] = '\0';
            printf("%s\n", buf);
            fflush(stdout);

    }

    // Schließt beide Enden des Rohres (mit Panzertape, das hält!)
    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}

static int init_semaphore(int* semid, key_t key) {
    *semid = semget(key, 0, IPC_PRIVATE); // öffnet Semaphore mit unserem KEY1, nsems=0
    if (*semid < 0) { // öffnen fehlgeschlagen, weil wahrscheinlich keine solche Semaphore existiert --> eine neue erstellen
        umask(0);
        *semid = semget(key, 1, IPC_CREAT | IPC_EXCL | PERM); // erzeugt neue Semaphore
        if (*semid < 0) { // Fehlerprüfung
            perror("CRIT: Konnte Semaphore nicht erzeugen\n");
            return 1;
        }
        if (semctl(*semid, 0, SETVAL, (int) 0) == -1) { // sperrt Semaphore initial
            perror("CRIT: Konnte Anfangswert der Semaphore nicht setzen\n");
            return 1;
        }
    }
    return 0;
}

static void sema_operation(const int* semid, short op) { // war im Tutorial int statt void, aber hätte immer nur 1 zurückgegeben. Tsk.
    semaphore.sem_op = op;
    semaphore.sem_flg = SEM_UNDO; // Wenn der letzte Prozess verschwindet, wird die Semaphore freigegeben
    if (semop(*semid, &semaphore, 1) == -1) { // führt auf Semaphore semid1 die Operationen sem_op in semaphore (ggf. Array) aus. 1 (nsops) ist die Array-Größe
        perror("CRIT: Fehler bei einer Semaphorenoperation");
        exit(EXIT_FAILURE);
    }
}
