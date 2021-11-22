<!----------
title: "Lernkontrollfragen Systemprogrammierung / Verteilte Systeme"
date: "Semester 5"
keywords: [Systemprogrammierung, Verteilte Systeme, RES, DHGE, Semester 5]
---------->

Lernkontrollfragen Systemprogrammierung / Verteilte Systeme
========================================

<!-- md2apkg ignore-card -->

# Lernkontrollfragen

## Wiederholungsfragen zu Beginn der Veranstaltung

<!-- md2apkg ignore-card -->

Zu Beginn wird gefragt, aus welchen Inhalten der letzten Veranstaltungen Klausurfragen konstruiert werden können.
Erfahrungsgemäß ist das am Ende ein großer Teil der Klausur.

### Mit make Kerne auslasten

Parameter `-j`

### Was ist ein Deadlock?

- **Allgemein**
  - Situation, in der sich beide Alternativen eines Dilemmas gegenseitig blockieren **oder**
  - in der die Handlungspartner nicht zu Kompromissen zur Lösung einer solchen Situation bereit sind, wodurch die Situation ausweglos wird.
- **Informatik**
  - ausweglose Situation, bei dem sich mehrere Prozesse gegenseitig blockieren, weil sie auf die Freigabe von Betriebsmitteln warten, die ein anderer beteiligter Prozess bereits exklusiv belegt hat

### Wie kann ich einen Deadlock verhindern/auflösen

- Reboot
- Auf Ressource verzichten (Signale an Prozess senden)
- Prozess killen
- ggf. auch über Pipes (Implementierung notwendig)
- Sockets benutzen ♻️ <!-- na mal sehen ob das in LaTeX und anki probleme macht -->

## Philosophenproblem nacherzählen und erklären

- Denken oder Essen; 5 Philosophen mit 5 Stäbchen an rundem Tisch
- Nicht genug Ressourcen für alle
- gleichzeitiger Zugriff
- Deadlock kann entstehen

### Gedankenspiele Anzahl Philosophen/Anzahl Stäbchen 5/2, 10/10, 10/5 beantworten können

...

### Haupteigenschaft fork-Prozesse

PID - Prozess ID zu Identifikation
<!-- Max hier ergänzen wenn du magst ### Eigenschaften eines Prozesses -->

### Rückgabekategorien fork

```txt
>0: die PID des Kindprozesses
0: es wurde eben geforkt und wir sind das Kind
-1: Fehler
```

## Differenzierung zwischen Vater- und Kind-Prozess

- Rückgabewert `fork()` im Vater ist `getpid()` vom Kind
- Rückgabewert `fork()` im Kind ist `0`
- `getppid()` vom Kind ist `getpid()` vom Vater
- `getppid()` vom Vater ist die aufrufende Shell

### Was passiert, wenn man in Schleifen forkt

- Kinder forken ebenfalls
- Prozesse vermehren sich potentiell

### Wozu Semaphoren

- Deadlock vermeiden, exklusiven Zugriff auf Ressourcen verwalten; Programmabarbeitung übergreifend verwalten
- Kritischer Abschnitt - 2 Prozesse greifen auf gleiche Ressource zu; gleichzeitiger Zugriff führt zu unvorhersehbaren Ergebnissen
- Daher Interprozesskommunikation notwendig

### Semaphoren unterscheiden

- Binäre Semaphoren: Phasen Frei/Blockiert
-  Zählende Semaphoren: Anzahl Ressourcen verwaltbar

### Semaphoren benutzen

- Deklaration
- Initialisierung
- Verwendung (Operation)

### Wann werden Semaphoren- Operationen aufgerufen

- P - Vor dem kritischen Abschnitt LOCK - Ressourcen blockieren
- V - Nach dem kritischen Abschnitt UNLOCK - Ressourcen freigeben

### Rückgabewerte Fork

- Was gibt fork zurück, wenn Kind nicht gestartet hat?
  - `-1`
- `fork()` gibt `23` zurück - was ist passiert?
  - Kind hat PID `23`, wir sind Vater.
- `fork()` gibt `0` zurück.
  - Wir sind Kindprozess eines Fork.

### Zweck pipe

IPC Prozess A $\rightarrow$ B

### Wie kommt der Kanal zwischen Prozess A und B zustande, inbesondere mit fork()?

<!-- Antwort Studi: vgl. Sockets (File) -->

- ``fork()`` kopiert auch File-Deskriptoren, somit haben beide Prozesse einen Pipe-Kanal, insofern die Pipe vor dem Forken definiert wurde
- Kernel buffert das Geschriebene solange, bis es gelesen wird.

### Was passiert, wenn ich forke?

- Ab `fork()` entsteht Kindprozess
- gesamter Speicher des Prozesses, inklusive Filedeskriptoren (auch Pipes), Variablen, etc. werden kopiert
- Nicht kopiert werden: PID<!-- DUH -->

$\rightarrow$ Prozesse, die verwandt sind, können über vor `fork()` angelegte Pipes kommunizieren.

### Welche Operationen auf einer Pipe kennen Sie? Beschreiben Sie deren Funktion

- `write(pipefd[1],buffer)`
  - Write: Aus Programmbuffer auf die Pipe schreiben, in den Kernelbuffer
- `read(pipefd[0],buffer)`
  - Read: Aus Kernelbuffer in Programmbuffer schreiben; aus Sicht des Programms von Pipe lesen

### Wie können Sie bidirektionale IPC ermöglichen?

- Pipe umdrehen <!-- LOL -->, ggf. mit Zugriffskonzept (Semaphore)
- 2 Pipes verwenden
- Socket benutzen

### Was bedeutet `close` generell / bei Pipe?

- Der Filedeskriptor wird gelöscht und steht nicht mehr zur Verfügung
- Dadurch ist das dahinterliegende File (everything is a file) nicht mehr trivial erreichbar
  - Es sei denn ein Prozess hat das File jetzt gerade noch geöffnet.

Bei Pipes:

- Seite einer Pipe schließen
  - Schreibseite schließen: EOF senden

<!-- **PIDs differieren stark, was ist passiert?**  -->

<!-- #### Was passiert, wenn der Wertebereich für PIDs erschöpft ist? (2 Möglichkeiten) TODO -->

### Was ist passiert, wenn PID vom Kind < PID Vater

- PID Tabelle war voll, es wurden freigegebene kleinere PID genutzt

### Wie können sie sich die PID von Prozessen (in einem C-Programm/auf dem Terminal) anzeigen lassen?

- `htop` / anderer Taskmanager für Betriebssystem, alle Prozesse
- `ps`
- `getpid()` für ein Programm

### Wer/was definiert/ist kritischer Abschnitt?

- Es ist ein Codebereich, der nur in einer definierten Anzahl von Prozessen gleichzeitig zur Verfügung steht (stehen sollte)
- realisiert durch Zugriffskonzepte, Semaphoren, andere Sperrkonzepte
- Entwickler müssen im Programm dafür Sorge tragen und den kritischen Abschnitt definieren

### Nennen Sie zwei Arten der IPC

- Pipes
- Sockets

### Unterschied Pipe Socket

- Pipes
  - Unix-Domaine exklusiv, d.h. gleiches Rechensystem
  - unidirektional
- Socket
  - Unix/Internetdomäne
  - bidirektional
