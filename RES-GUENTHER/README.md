<!----------
title: "Systemprogrammierung / Verteilte Systeme"
date: "Semester 5"
keywords: [Systemprogrammierung, Verteilte Systeme, RES, DHGE, Semester 5]
---------->

# Systemprogrammierung / Verteilte Systeme

<!-- md2apkg ignore-card -->

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->

**Inhaltsverzeichnis**

- [Klausur](#klausur)
- [Systemprogrammierung](#systemprogrammierung)
  - [Lernziele/Themenschwerpunkte](#lernzielethemenschwerpunkte)
  - [Literaturempfehlung](#literaturempfehlung)
  - [Parallele Programmierung](#parallele-programmierung)
    - [Prozesssteuerung](#prozesssteuerung)
    - [Systemaufruf fork()](#systemaufruf-fork)
    - [Semaphore](#semaphore)
    - [Interprozesskommunikation](#interprozesskommunikation)
      - [Pipes](#pipes)
      - [Sockets](#sockets)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Klausur

<!-- md2apkg ignore-card -->

- 60 min, keine Hilfsmittel
- Multiple Choice Fragen möglich
- nur behandelter Stoff
- kein Programmcode
- Fragen zu bestehendem Code

<!--newpage-->

# Systemprogrammierung

## Lernziele/Themenschwerpunkte

<!-- md2apkg ignore-card -->

- Probleme und Lösungen bei parallelem Ressourcenzugriff kennen
  - z.B. Deadlock, Seiteneffekte, Semaphore, atomare Operationen, kritischer Abschnitt
- Parallele Programme lesen und verstehen können
  - z.B. Prozessse
- Interprozess-Kommunikations-Mechanismen
  - z.B. Pipes, Sockets
- Konzepte der systemnahen Programmierung
  - z.B. Signale
- Praktische Realisierung dieser Konzepte am Beispiel von Unix/Linux umsetzen können
- Problematischen Code hinsichtlich parallelem Zugriff erkennen
- Die Fähigkeit erwerben, eigenständig Parallelitäts- und Kommunikationskonstrukte auszuwählen und zu implementieren

> Prüfungsleistung: Klausur (ohne Hilfsmittel)

## Literaturempfehlung

<!-- md2apkg ignore-card -->

- Tanenbaum, A.S. "Moderne Betriebssysteme"
- Peter Mandl: "Grundkurs Betriebssysteme"
- Vogt, C.: "Betriebssysteme"
- Glatz, E.: "Betriebssysteme"

## Parallele Programmierung

- gleichzeitige Abarbeitung von Aufgaben
- Motivation: Zeit sparen $\rightarrow$ eine große Aufgabe wird zur selben Zeit in mehreren kleinen erledigt
- Ausnutzung der Hardware: Multicore-Prozessoren, verteilte Rechnerkerne

> **Fünf-Philosophen-Problem**
>
> [siehe Wikipedia](https://de.wikipedia.org/wiki/Philosophenproblem)
>
> Es können immer nur maximal zwei Philosophen gleichzeitig speisen

- Code, der Deadlocks oder Race Conditions verursachen kann, wird **"kritischer Code"** / kritischer Pfad genannt
- kritische Abschnitte müssen vom Programmierer definiert werden

### Prozesssteuerung

**Mehrere Prozesse starten:**

- im Hintergrund ausführen: `.\anton &` `.\berta &`
- Prozesse anzeigen: `jobs -l`, `top`, `htop`, `ps`

### Systemaufruf fork()

**Klausurrelevant**

- Zweck: es wird eine exakte Kopie des Aufrufers als Kindprozess erzeugt
- Kindprozess übernimmt Code, Daten inkl. Befehlszähler, Dateideskriptoren, ...

**Auswertung des Rückgabewerts**

- 3 mögliche Rückgabewerte
  - `>0`: die PID des Kindprozesses
  - `0`: es wurde eben geforkt und wir sind das Kind
  - `-1`: Fehler

```C
#include<stdio.h>
#include<unistd.h>

int main()
{
    fork();
    getpid(); // MY PID
    getppid(); //Parent PID
    childpid=fork(); //..
    printf("Hallo, ich bin ein Prozess!\n");
    fflush(stdout);
    return 0;
}
```

### Semaphore

[weiterführende Informationen](https://openbook.rheinwerk-verlag.de/linux_unix_programmierung/Kap09-004.htm)

- Vorgehenssynchronisation zwischen mehreren Prozessen
- sperrt z.B. kritische Codebereiche
  - binär: darf / darf nicht benutzen
  - zählend: x Prozesse dürfen, darüber nicht
- System-V Semaphoren haben drei Funktionen:
  - `semget()`: Erzeugt eine neue Semaphore oder öffnet eine vorhandene
  - `semctl()`: manipuliert Semaphorenmengen
  - `semop()`: führt eine Reihe Operationen auf einem Set Semaphoren aus
- zwei Operationen:
  - P-Operation: "Passieren": regelt Betreten kritischen Codes
  - V-Operation: "Verlassen": regelt Verlassen kritischen Codes
- Programmierung: Semaphoren müssen deklariert, initialisiert und dann verwendet werden

### Interprozesskommunikation

- Motivation: Verhinderung von
  - gleichzeitigen Schreibzugriffen
  - Verhungern von Prozessen
  - Deadlocks

#### Pipes

- _Rohre_ zwischen Prozessen, in denen Nachrichten transportiert werden können
- nur in eine Richtung
- Pipes können nur zwischen Prozessen mit gemeinsamen Vorfahren eingerichtet werden
- Ablauf:
  - Vaterprozess erzeugt Pipe
  - Vaterprozess erzeugt Sohnprozess mit `fork()`
  - Sohnprozess erbt Pipe
- Programmierung:

  - Inkludierung von `sys/unistd.h`
  - `int pipe(int fd[2])`
    - `fd[0]` zum Lesen
    - `fd[1]` zum Schreiben
  - Lese-Operation: `read()`
    - wurden alle Leseseiten einer Pipe bereits gelesen, liefert `read()` EOF
  - Schreib-Operation: `write()`
  - Schließ-Operation: `close()`
<details>
  <summary>Beispielprogramm "Nein, doch, oh!"</summary>

  ```c++
  /// \brief This program creates two pipes and forks a child process to print out "Nein! Doch! Oh!".
  /// \details The PARENT process uses the pipe1 to read the messages to the child process and uses the pipe2 to write the messages from the child process.
  ///          The CHILD process uses the pipe1 to write the messages from the parent process and uses the pipe2 to read the messages to the parent process.

  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <string.h>

  static const int FORK_CHILD_PID = 0;
  static const int FORK_ERROR_PID = -1;

  static const int PIPE_ERROR = -1;
  static const int PIPE_SIZE = 2;
  static const int PIPE_READ_INDEX = 0;
  static const int PIPE_WRITE_INDEX = 1;

  static const char *PARENT_MESSAGE_1 = "Nein!\n";
  static const char *PARENT_MESSAGE_2 = "Oh!\n";
  static const char *CHILD_MESSAGE_1 = "Doch!\n";

  void createPipe(int pipeFileDescriptor[]);
  void sendPipeMessage(int pipeFileDescriptor[], const char *message);
  void receivePipeMessage(int pipeFileDescriptor[], char *message);

  /// @brief Creates a pipe and checks if it was created successfully.
  /// @param pipeFileDescriptor The pipe file descriptor.
  void createPipe(int pipeFileDescriptor[])
  {
      if (pipe(pipeFileDescriptor) == PIPE_ERROR)
      {
          perror("Pipe creation failed");
          exit(EXIT_FAILURE);
      }
  }

  /// @brief Sends a message through a pipe.
  /// @param pipeFileDescriptor The pipe file descriptor. Assumed that the write end (index = 1) is open.
  /// @param message The message to send.
  void sendPipeMessage(int pipeFileDescriptor[], const char *message)
  {
      const ssize_t bytesWritten = write(pipeFileDescriptor[PIPE_WRITE_INDEX], message, strlen(message));
      if (bytesWritten == -1)
      {
          perror("Write failed");
          exit(EXIT_FAILURE);
      }
  }

  /// @brief Receives a message through a pipe.
  /// @param pipeFileDescriptor The pipe file descriptor. Assumed that the read end (index = 0) is open.
  /// @param message The message to receive.
  void receivePipeMessage(int pipeFileDescriptor[], char *message)
  {
      const ssize_t bytesRead = read(pipeFileDescriptor[PIPE_READ_INDEX], message, strlen(message));
      if (bytesRead == -1)
      {
          perror("Read failed");
          exit(EXIT_FAILURE);
      }

      // Null-terminate the received message
      message[bytesRead] = '\0';
  }

  int main()
  {
      int pipeFileDescriptor1[PIPE_SIZE];
      int pipeFileDescriptor2[PIPE_SIZE];

      createPipe(pipeFileDescriptor1);
      createPipe(pipeFileDescriptor2);

      const pid_t childPid = fork();

      if (childPid == FORK_ERROR_PID)
      {
          perror("Fork failed");
          exit(EXIT_FAILURE);
      }
      // in a child process
      else if (childPid == FORK_CHILD_PID)
      {
          printf("Bin das Kind: %d\n", getpid());

          // Close unused read end
          close(pipeFileDescriptor1[PIPE_READ_INDEX]);
          // Close unused write end
          close(pipeFileDescriptor2[PIPE_WRITE_INDEX]);

          char incoming_message[strlen(PARENT_MESSAGE_1)];
          receivePipeMessage(pipeFileDescriptor2, incoming_message);
          printf("Vom Vater: %s", incoming_message);

          sendPipeMessage(pipeFileDescriptor1, CHILD_MESSAGE_1);

          char incoming_message2[strlen(PARENT_MESSAGE_2)];
          receivePipeMessage(pipeFileDescriptor2, incoming_message2);
          printf("Vom Vater: %s", incoming_message2);

          // Close write end
          close(pipeFileDescriptor1[PIPE_WRITE_INDEX]);
          // Close read end
          close(pipeFileDescriptor2[PIPE_READ_INDEX]);
      }
      // in a parent process
      else if (childPid > FORK_CHILD_PID)
      {
          printf("Bin der Vater: %d\n", getpid());

          // Close unused write end
          close(pipeFileDescriptor1[PIPE_WRITE_INDEX]);
          // Close unused read end
          close(pipeFileDescriptor2[PIPE_READ_INDEX]);

          sendPipeMessage(pipeFileDescriptor2, PARENT_MESSAGE_1);

          char incoming_message[strlen(CHILD_MESSAGE_1)];
          receivePipeMessage(pipeFileDescriptor1, incoming_message);
          printf("Vom Kind: %s", incoming_message);

          sendPipeMessage(pipeFileDescriptor2, PARENT_MESSAGE_2);

          // Close read end
          close(pipeFileDescriptor1[PIPE_READ_INDEX]);
          // Close write end
          close(pipeFileDescriptor2[PIPE_WRITE_INDEX]);
      }
      else
      {
          perror("Fork failed");
          exit(EXIT_FAILURE);
      }

      return EXIT_SUCCESS;
  }
  ```
</details>

#### Sockets

- IPC auf lokalem Rechner (Unix-Domäne) oder über das Internet (Internet-Domäne)
- Ein Port ist eine Spezifikation zur Addressierung eines Prozesses auf einem Host
