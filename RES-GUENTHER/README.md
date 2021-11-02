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
- [Systemprogrammierung](#systemprogrammierung)
  - [Lernziele/Themenschwerpunkte](#lernzielethemenschwerpunkte)
  - [Literaturempfehlung](#literaturempfehlung)
  - [Parallele Programmierung](#parallele-programmierung)
    - [Prozesssteuerung](#prozesssteuerung)
    - [Systemaufruf fork()](#systemaufruf-fork)

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

### Prozesssteuerung

**Mehrere Prozesse starten:**

- im Hintergrund ausführen: `.\anton &` `.\berta &`
- Prozesse anzeigen: `jobs -l`, `top`, `htop`, `ps`

### Systemaufruf fork()

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


