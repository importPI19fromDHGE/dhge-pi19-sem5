<!----------
title: "Entwicklung von Webanwendungen"
date: "Semester 5"
keywords: [Entwicklung von Webanwendungen, Webbasierte Anwendungen, PRO, DHGE, Semester 5]
---------->

Entwicklung von Webanwendungen
==============================

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Inhaltsverzeichnis**

- [Geschichte des Internets](#geschichte-des-internets)
- [Technologien](#technologien)
  - [Was ist eine Webanwendung?](#was-ist-eine-webanwendung)
  - [Client-Technologien](#client-technologien)
  - [Server](#server)
  - [HTML](#html)
    - [HTML-Syntax](#html-syntax)
    - [HTML 5](#html-5)
  - [CSS](#css)
  - [JS](#js)
- [PHP und Datenbanken](#php-und-datenbanken)
- [Moderne Webentwicklung mit Frameworks](#moderne-webentwicklung-mit-frameworks)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Geschichte des Internets

- 1958 Gründung Advanced Research Projects Agency
- 1969 ARPAnet vernetzt 4 Großrechner in Kalifornien und Utah
- 1972 37 Einrichtungen in USA angeschlossen
- 1974 Entwicklung TCP, später TCP/IP
- 1975 erste elektronische Diskussionsgruppe
- 1978 USENET, unabhängig von ARPAnet
- 1981 188 Rechner mit ca. 500,000 Nutzern im Internet
- 1986 Top Level Domains werden ins Leben gerufen
- 1988 erste deutsche Internetprovider Eunet und Xlink
- 1989 Timothy Berners-Lee entwickelt ersten "Browser"
- 1991 Berners-Lee veröffentlicht WWW im Internet sowie HTML
- 1992 1 Mio. Rechner im Internet
- 1996 mehr als 16 Mio.
- 1998 Gründung von Google, mehr als 36 Mio.
- 2001 Wikipedia geht online
- 2003 über 50% der Deutschen hat Internet
- 2005 Youtube geht ins Netz
  - $\rightarrow$ erstmals von Web 2.0 gesprochen

# Technologien

## Was ist eine Webanwendung?

- Web = World Wide Web $\rightarrow$ Teil des Internets
- Client-Server-Anwendung (Client = Browser)
- Pattformunabhängig, keine zusätzliche Installation
- Nutzung des http-Protokolls
- Interaktion mit dem Nutzer

## Client-Technologien

- HTML 5 $\rightarrow$ Beschreibung der Struktur der Webseiten
- CSS 3 $\rightarrow$ Formatierung / Aussehen
- Java-/ECMA-Script $\rightarrow$ Interaktion
- DOM/Ajax $\rightarrow$ Manipulation des Seiteninhalts
- Flash $\rightarrow$ obsolet
- XML $\rightarrow$ Datenaustausch (SVG, MathML, RSS, GraphML)

## Server

- PHP
- Ruby (on Rails)
- Java Applet
- ASP.NET
- ColdFusion

## HTML

- 1991 publiziert durch Entwickler Burners-Lee
- verbreitet sich rasend schnell als "Programmiersprache" des Internets
- letzte Version: HTML 5.2 (14. Dezember 2017)
- Arbeitsentwurf für 5.3 seit 18. Oktober 2018

### HTML-Syntax

- Auszeichnung von Textelementen durch Tags
- ``<tag>Text</tag>```
- Öffnendes Tag $\rightarrow$ schließendes Tag $\rightarrow$ dazwischen Body
- schließende Tags können in einigen Fällen entfallen
- Tags können Attritube enthalten ```<tag attribut="Wert">body</tag>```

Beispiel-Skelett:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="x-ua-compatible" content="ie=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />

    <title></title>
    <link rel="stylesheet" href="css/main.css" />
    <link rel="icon" href="images/favicon.png" />
  </head>

  <body>
    <script src="js/scripts.js"></script>
  </body>
</html>
```

### HTML 5

- Schwerpunkt auf Gliederung der Seite
- ```<header></header>``` $\rightarrow$ Logo und Überschrift
- ```<nav></nav>``` $\rightarrow$ Navigationsbereich
- ```<main></main>``` $\rightarrow$ Hauptinhalt der Seite
- ```<article></article>``` $\rightarrow$ eigener Abschnitt mit header, Überschrift und footer
- ```<section></section>``` $\rightarrow$ ein Abschnitt
- ```<footer></footer>``` $\rightarrow$ Fußzeile
- ```<aside></aside>``` $\rightarrow$ Fußnoten, Randnotizen
- bessere Übersicht bei vielen Elementen
- Suchmaschinen werten den Inhalt der Seite besser aus
- Screenreader können flüssiger lesen
- weiter Neuerungen für Multimedia, Formulare

192.168.71.6

## CSS

## JS

# PHP und Datenbanken

# Moderne Webentwicklung mit Frameworks