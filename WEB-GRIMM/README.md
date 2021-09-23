<!----------
title: "Entwicklung von Webanwendungen"
date: "Semester 5"
keywords: [Entwicklung von Webanwendungen, Webbasierte Anwendungen, PRO, DHGE, Semester 5]
---------->

Entwicklung von Webanwendungen
==============================

<!-- md2apkg ignore-card -->

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Inhaltsverzeichnis**

- [Entwicklung von Webanwendungen](#entwicklung-von-webanwendungen)
- [Prüfungsleistung](#prüfungsleistung)
- [Geschichte des Internets](#geschichte-des-internets)
- [Technologien](#technologien)
  - [Was ist eine Webanwendung?](#was-ist-eine-webanwendung)
  - [Client-Technologien](#client-technologien)
  - [Server](#server)
  - [HTML](#html)
    - [HTML-Syntax](#html-syntax)
    - [HTML 5](#html-5)
      - [Bilder](#bilder)
      - [Listen](#listen)
      - [Tabellen](#tabellen)
      - [Zeilenumbrüche](#zeilenumbrüche)
  - [CSS](#css)
  - [JS](#js)
- [PHP und Datenbanken](#php-und-datenbanken)
- [Moderne Webentwicklung mit Frameworks](#moderne-webentwicklung-mit-frameworks)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Prüfungsleistung

- Klausur über behandelte Themen

# Geschichte des Internets

<!-- md2apkg ignore-card -->

- 1958 Gründung Advanced Research Projects Agency
- 1969 ARPAnet vernetzt 4 Großrechner in Kalifornien und Utah
- 1972 37 Einrichtungen in USA angeschlossen
- 1974 Entwicklung TCP, später TCP/IP
- 1975 erste elektronische Diskussionsgruppe
- 1978 USENET, unabhängig von ARPAnet
- 1981 188 Rechner mit ca. 500,000 Nutzern im Internet
- 1986 Top Level Domains werden ins Leben gerufen
- 1988 erste deutsche Internetprovider Eunet und Xlink
- 1989 Timothy Berners-Lee entwickelt ersten "Browser" WorldWideWeb
- 1991 Berners-Lee veröffentlicht HTML sowie die erste WWW-Seite
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
- Nutzung des Hypertext Transfer Protocol (Http)
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
- NodeJS
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

#### Bilder

- Attribute:
  - ismap: serverseitige Image Map, bei Klick werden Mauskoordinaten an Server gesendet
  - usemap: in Verbindung mit Map-Tag
- Map-Tag:
  - ``<map name="NAME">``
  - in Verbindung mit ``<img usemap ...>``
  - Definition einer verweissensitiven Fläche, die mit Sprungziel verknüpft ist

Beispiel mit ``usemap``:

```html
<section>
  <h1>Verweissensitiv</h1>
    <img src="bild.jpg"
    alt="Bild"
    usemap="#bild1"
    >
</section>

<map name="bild1">
  <area shape="circle" coords="402,209,13" href="https://www.dhge.de" title="DHGE"><!--coords: x, y, radius-->
```

#### Listen

- es gibt sortierte (``ol``), unsortierte (``ul``) und Beschreibungs-Listen (``dl``)
- Listenelemente tragen das ``li``-Tag
- geordnete Listen
  - nummeriert
  - ``start``-Attribut gibt Startwert für Nummerierung an
  - ``reversed``-Atttribut für umgekehrte Zählrichtung
  - ``type``-Tag für die Art der Aufzählungszeichen (arabisch, römisch, ...)
- ungeordnete Listen:
  - Reihenfolge nicht wichtig
  - ``type``-Attribut deprecated
- Beschreibungsliste
  - zweiteilig: Listenelement besteht aus ``dt`` (description term) und ``dd`` (description description)
  - wird z.B. für Glossare verwendet
  - zu einem ``dt`` können mehrere ``dd`` gehören

Beispiel für Listen:

```html
<ul>
  <li>Listenpunkt 1</li>
  <li>Listenpunkt 2</li>
  <li>Listenpunkt 3</li>
</ul>
```

Beispiel für Beschreibungslisten:

```html
<dl>
  <dt>DDR</dt>
  <dd>Deutsche Demokratische Republik</dd>
  <dd lang="en">Double Data Rate</dd>
  <dd lang="en">Data Direction Register</dd>
  <dt>BRD</dt>
  <dd>Bundesrepublik Deutschland</dd>
</dl>
```

#### Tabellen

- strukturierte Datensammlung
- Anwendug in z.B. Kalender, Stundenpläne, Fahrpläne, ...
- Tag ``<table>``
  - Zeile mit ``<tr>``
  - Zelle / TBD
- ``<thead>``: Tabellenkopf
- ``<tfoot>``: Tabellenfuß
- ``<tbody>``
- ``<caption>``: Beschriftung oder Überschrift, außerhalb der Tabelle
  - muss unmittelbar hinter dem ``<table>``-Tag folgen
- TBD

#### Zeilenumbrüche

- werden erzwungen mit ``<br>``

Beispiel Tabelle:

```html
<table>
  <thead>
    <tr>
      <th>Zeit</th>
      <th>Fach</th>
      <th>Dozent</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>08:00 - 09:30</th>
      <td>Web</td>
      <td>Herr Grimm</td>
    </tr>
    <tr>
      <th>09:45 - 11:15</th>
      <td>SysEnt</td>
      <td>Herr Günther</td>
    </tr>
  </tbody>
  <tfoot>
    <tr><td colspan="3">Woche vom 20.09. bis 24.04.</td></tr>
</table>
```

## CSS

## JS

# PHP und Datenbanken

# Moderne Webentwicklung mit Frameworks
