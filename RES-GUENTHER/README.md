<!----------
title: "Systemprogrammierung / Verteilte Systeme"
date: "Semester 5"
keywords: [Systemprogrammierung, Verteilte Systeme, RES, DHGE, Semester 5]
---------->

Systemprogrammierung / Verteilte Systeme
========================================

<!-- md2apkg ignore-card -->

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Inhaltsverzeichnis**

- [Klausur](#klausur)
  - [Wiederholungsfragen zu Beginn der Veranstaltung](#wiederholungsfragen-zu-beginn-der-veranstaltung)
    - [PIA 27/10/21](#pia-271021)
      - [Mit make Kerne auslasten](#mit-make-kerne-auslasten)
      - [Was sind Deadlocks und wie können Sie behoben werden](#was-sind-deadlocks-und-wie-k%C3%B6nnen-sie-behoben-werden)
    - [Philosophenproblem nacherzählen und erklären](#philosophenproblem-nacherz%C3%A4hlen-und-erkl%C3%A4ren)
      - [Gedankenspiele Anzahl Philosophen/Anzahl Stäbchen 5/2, 10/10, 10/5 beantworten können](#gedankenspiele-anzahl-philosophenanzahl-st%C3%A4bchen-52-1010-105-beantworten-k%C3%B6nnen)
    - [PIA 02/11/21](#pia-021121)
      - [Was ist fork](#was-ist-fork)
      - [Haupteigenschaft fork-Prozesse](#haupteigenschaft-fork-prozesse)
      - [Differenzieren zwischen Vater- und Kindprozess](#differenzieren-zwischen-vater--und-kindprozess)
      - [Rückgabekategorien fork](#r%C3%BCckgabekategorien-fork)
      - [Was passiert, wenn man in Schleifen forkt](#was-passiert-wenn-man-in-schleifen-forkt)
    - [PIA 03/11/21](#pia-031121)
      - [Wozu Semaphoren](#wozu-semaphoren)
      - [Semaphoren unterscheiden](#semaphoren-unterscheiden)
      - [Semaphoren benutzen](#semaphoren-benutzen)
      - [Wann werden Semaphoren- Operationen aufgerufen](#wann-werden-semaphoren--operationen-aufgerufen)
    - [Was ist ein Fork?](#was-ist-ein-fork)
    - [Welche Rückgabewerte hat fork()](#welche-r%C3%BCckgabewerte-hat-fork)
    - [Eigenschaften eines Prozesses](#eigenschaften-eines-prozesses)
    - [Differenzierung zwischen Vater- und Kind-Prozess](#differenzierung-zwischen-vater--und-kind-prozess)
    - [Was passiert, wenn man in Schleifen forkt](#was-passiert-wenn-man-in-schleifen-forkt-1)
- [Systemprogrammierung](#systemprogrammierung)
  - [Lernziele/Themenschwerpunkte](#lernzielethemenschwerpunkte)
  - [Literaturempfehlung](#literaturempfehlung)
  - [Parallele Programmierung](#parallele-programmierung)
    - [Prozesssteuerung](#prozesssteuerung)
    - [Systemaufruf fork()](#systemaufruf-fork)
    - [Semaphore](#semaphore)
    - [Interprozesskommunikation](#interprozesskommunikation)
      - [Pipes](#pipes)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Klausur

<!-- md2apkg ignore-card -->

## Wiederholungsfragen zu Beginn der Veranstaltung

<!-- md2apkg ignore-card -->

Zu Beginn wird gefragt, aus welchen Inhalten der letzten Veranstaltungen Klausurfragen konstruiert werden können.
Erfahrungsgemäß ist das am Ende ein großer Teil der Klausur.

### PIA 27/10/21

<!-- md2apkg ignore-card -->

#### Mit make Kerne auslasten

Parameter -j

#### Was sind Deadlocks und wie können Sie behoben werden

...

### Philosophenproblem nacherzählen und erklären

Nicht genug Ressourcen, Deadlock kann entstehen

#### Gedankenspiele Anzahl Philosophen/Anzahl Stäbchen 5/2, 10/10, 10/5 beantworten können

...

### PIA 02/11/21

<!-- md2apkg ignore-card -->

#### Was ist fork

(nicht die englische Übersetzung)
Benedict: Prozese aufspalten, Vater, Kind Prozess

#### Haupteigenschaft fork-Prozesse

PID - Prozess ID zu Identifikation
<!-- Max hier ergänzen wenn du magst ### Eigenschaften eines Prozesses -->

#### Differenzieren zwischen Vater- und Kindprozess

Kindprozess mit getppid() -> Ist die getpid() des Vaters
PID des Prozess in getppid wiederfinden

#### Rückgabekategorien fork

```
>0: die PID des Kindprozesses
0: es wurde eben geforkt und wir sind das Kind
-1: Fehler
```

### Differenzierung zwischen Vater- und Kind-Prozess

Rückgabewert fork() im Vater ist getpid() vom Kind
Rückgabewert fork() im Kind ist 0
getppid() vom Kind ist getpid() vom Vater
getppid() vom Vater ist die aufrufende Shell

#### Was passiert, wenn man in Schleifen forkt

- Kinder forken ebenfalls
- Prozesse vermehren sich potentiell

### PIA 03/11/21

#### Wozu Semaphoren

Deadlock vermeiden, exklusiven Zugriff auf Ressourcen verwalten; Programmabarbeitung übergreifend verwalten
Kritischer Abschnitt - 2 Prozesse greifen auf gleiche Ressource zu; gleichzeitiger Zugriff führt zu unvorhersehbaren Ergebnissen
Daher Interprozesskommunikation notwendig

#### Semaphoren unterscheiden

Binäre Semaphoren - Zählende Semaphoren
Phasen Frei/Blockiert - Anzahl Ressourcen verwaltbar

#### Semaphoren benutzen

Deklaration
Initialisierung
Verwendung (Operation)

#### Wann werden Semaphoren- Operationen aufgerufen

P - Vor dem kritischen Abschnitt LOCK
V - Nach dem kritischen Abschnitt UNLOCK

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

- *Rohre* zwischen Prozessen, in denen Nachrichten transportiert werden können
- nur in eine Richtung
- Pipes können nur zwischen Prozessen mit gemeinsamen Vorfahren eingerichtet werden
- Ablauf:
  - Vaterprozess erzeugt Pipe
  - Vaterprozess erzeugt Sohnprozess mit `fork()`
  - Sohnprozess erbt Pipe
- Programmierung:
  - inkludierung von `sys/unistd.h`
  - `int pipe(int fd[2])`
    - `fd[0]` zum Lesen
    - `fd[1]` zum Schreiben
  - Lese-Operation: `read()`
    - wurden alle Leseseiten einer Pipe bereits gelesen, liefert `read()` EOF
  - Schreib-Operation: `write()`
  - Schließ-Operation: `close()`
