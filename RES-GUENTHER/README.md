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

- [Systemprogrammierung](#systemprogrammierung)
  - [Lernziele/Themenschwerpunkte](#lernzielethemenschwerpunkte)
  - [Parallele Programmierung](#parallele-programmierung)
    - [Prozesssteuerung](#prozesssteuerung)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

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
