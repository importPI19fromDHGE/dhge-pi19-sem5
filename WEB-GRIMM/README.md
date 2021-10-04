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
      - [Formulare](#formulare)
        - [Formular-Elemente](#formular-elemente)
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

- 1958: Gründung Advanced Research Projects Agency
- 1969: ARPAnet vernetzt 4 Großrechner in Kalifornien und Utah
- 1972: 37 Einrichtungen in USA angeschlossen
- 1974: Entwicklung TCP, später TCP/IP
- 1975: erste elektronische Diskussionsgruppe
- 1978: USENET, unabhängig von ARPAnet
- 1981: 188 Rechner mit ca. 500,000 Nutzern im Internet
- 1986: Top Level Domains werden ins Leben gerufen
- 1988: erste deutsche Internetprovider Eunet und Xlink
- 1989: Timothy Berners-Lee entwickelt ersten "Browser" WorldWideWeb
- 1991: Berners-Lee veröffentlicht HTML sowie die erste WWW-Seite
- 1992: 1 Mio. Rechner im Internet
- 1996: mehr als 16 Mio.
- 1998: Gründung von Google, mehr als 36 Mio.
- 2001: Wikipedia geht online
- 2003: über 50% der Deutschen hat Internet
- 2005: Youtube geht ins Netz
  - $\rightarrow$ erstmals von Web 2.0 gesprochen (Inhalte kommen primär von den Nutzern)

# Technologien

## Was ist eine Webanwendung?

- Web = World Wide Web $\rightarrow$ Teil des Internets
- Client-Server-Anwendung (Client = Browser)
- Pattformunabhängig, keine zusätzliche Installation
- Nutzung des Hypertext Transfer Protocol (`http`)
- Interaktion mit dem Nutzer

## Client-Technologien

- HTML 5 $\rightarrow$ Beschreibung der Struktur der Webseiten
- CSS 3 $\rightarrow$ Formatierung / Aussehen
- Java-/ECMA-Script $\rightarrow$ Interaktion
- DOM/Ajax $\rightarrow$ Manipulation des Seiteninhalts
- Flash $\rightarrow$ obsolet
- JSON, XML(SVG, MathML, RSS, GraphML, ...) $\rightarrow$ Datenaustausch

## Server

- PHP
- NodeJS
- Ruby (on Rails)
- Java
- ASP.NET
- ColdFusion

## HTML

- 1991 publiziert durch Entwickler Burners-Lee
- verbreitet sich rasend schnell als ~~"Programmiersprache"~~ (Auszeichnungssprache) des Internets
- letzte Version: HTML 5.2 (14. Dezember 2017)
- Arbeitsentwurf für 5.3 seit 18. Oktober 2018

### HTML-Syntax

- Auszeichnung von Textelementen durch Tags
- ``<tag>Text</tag>``
- Öffnendes Tag $\rightarrow$ schließendes Tag $\rightarrow$ dazwischen Body
- schließende Tags können in einigen Fällen entfallen (z.B. `<img/>`)
- Tags können Attribute enthalten ``<tag attribut="Wert">body</tag>``

Beispiel-Skelett:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="x-ua-compatible" content="ie=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <meta name="author" content="anonymous" />
    <meta name="description" content="404 - not found" />
    <title></title>
    <link rel="stylesheet" href="css/main.css" />
    <link rel="icon" href="images/favicon.png" />
  </head>

  <body>
    <!-- insert comment here -->
    <script src="js/scripts.js"></script>
  </body>
</html>
```

### HTML 5

- Schwerpunkt auf Gliederung der Seite $\rightarrow$ bessere Übersicht bei vielen Elementen
  - ``<header></header>`` $\rightarrow$ Logo und Überschrift
  - ``<nav></nav>`` $\rightarrow$ Navigationsbereich
  - ``<main></main>`` $\rightarrow$ Hauptinhalt der Seite
  - ``<article></article>`` $\rightarrow$ eigener Abschnitt mit header, Überschrift und footer
  - ``<section></section>`` $\rightarrow$ ein Abschnitt
  - ``<footer></footer>`` $\rightarrow$ Fußzeile
  - ``<aside></aside>`` $\rightarrow$ Fußnoten, Randnotizen
- Suchmaschinen werten den Inhalt der Seite besser aus (mehr Semantik in der Syntax)
- Screenreader können flüssiger lesen
- weitere Neuerungen für Multimedia, Formulare

#### Bilder

- Attribute:
  - `ismap`: serverseitige Image Map, bei Klick werden Mauskoordinaten an Server gesendet
  - `usemap`: in Verbindung mit Map-Tag
- Map-Tag:
  - ``<map name="NAME">``
  - in Verbindung mit ``<img usemap ...>``
  - Definition einer verweissensitiven Fläche, die mit Sprungziel verknüpft ist
- TBD: responsive Bilder

Beispiel mit ``usemap``:

```html
<section>
  <h1>Verweissensitiv</h1>
  <img src="bild.jpg" alt="Bild" usemap="#bild1">
</section>

<map name="bild1">
  <area shape="circle" coords="402,209,13" href="https://www.dhge.de" title="DHGE"><!--coords: x, y, radius-->
</map>
```

> Gute Services für Beispielbilder:
>
> - [https://via.placeholder.com/500x300](https://via.placeholder.com/300x100)
> - [https://placekitten.com/500/300](https://placekitten.com/500/300)
> - [https://baconmockup.com/500/300](https://baconmockup.com/500/300/)
> - [https://placekeanu.com/500/250](https://placekeanu.com/500/250)

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
  - ``type``-Attribut (deprecated)
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
  - Zelle mit ``<td>``
  - Kopfzelle mit ``<th>``
    - ``scope``-Attribut gibt an, ob es sich um einen Zeilen- oder Spalten-Kopf handelt
- ``<thead>``: Tabellenkopf
- ``<tfoot>``: Tabellenfuß
- ``<tbody>``
- ``<caption>``: Beschriftung oder Überschrift, außerhalb der Tabelle
  - muss unmittelbar hinter dem ``<table>``-Tag folgen
- Es gibt Attribute für ``<td>``, um Zellen zu verbinden:
  - ``colspan`` verbindet Spalten
  - ``rowspan`` verbindet Zeilen
  - ``colgroup`` gruppiert Spalten
  - weitere Formatierung sollte mit CSS vorgenommen werden

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
    <tr><td colspan="3">Woche vom 20.09. bis 26.09.</td></tr>
</table>
```

#### Zeilenumbrüche

- werden erzwungen mit ``<br>``
- Browser wird bei Leerzeichen einen Zeilenumbruch einfügen, wenn notwendig
- ``<wbr>``: Word Break - unsichtbare Markierung, wo der Browser ggf. einen Zeilenumbruch einfügen kann
- ``&shy;``: wie ``<wbr>``, fügt aber einen Bindestrich ein

#### Formulare

- elementar für Webanwendungen $\rightarrow$ ermöglichen Nutzerinteraktion durch Verarbeitung von Eingaben
- standardisiertes Mittel zur Erfassung, Ansicht und Aufbereitung von Daten die zur Verarbeitung an einen Webserver gesendet werden
- besonderer Wert ist auf Zugänglichkeit und Benutzerfreundlichkeit zu legen
- Tag: `form` mit Attributen:
  - `action`: welches Dokument bei submit die Daten verarbeitet
  - `id`: eindeutige Bezeichnung des Formulars
  - `method`: `POST` (Parameter im `http`-Header) oder `GET` (Parameter in der URI)
  - `name`: Name des Formulars für das auswertende Programm
  - `accept-charset`: Zeichenkodierung
  - `target`: Zielfenster
  - `autocomplete`: Autovervollständigung aktivieren/deaktivieren
  - `novalidate`: nicht auf Vollständigkeit prüfen (Plausibilität)

##### Formular-Elemente

- `label` (Beschriftung)
- `input` (Eingabefeld)
  - Attribute: `name`, `maxlength`, `minlength`, `required`, `pattern`, `value`, `placeholder`, ...
    - `type` = `text`, `search`, `password`, `tel`, `url`, `email`, `number` (mit `min`, `max`, `step`), `range`
- `textare` (mehrzeiliges Textfeld)
- `button` (Button, Schalter)
- `select` (Auswahllisten)
  - `option` (Auswahloption)
  - `optgroup` (verschachtelte Auswahllisten)
  - `fieldset` (Gruppierung)

```html
<form id="bsp" name="Beispiel" action="index.html" method="post">
  <label for="name1">Name:
    <input id="name1" type="text" name="name" maxlength="20" minlength="3" required>
  </label>
  <label for="suchfeld">Suche:
    <input id="suchfeld" type="search" list="suchliste">
    <datalist id="suchliste">
      <option value="1">HTML</option>
      <option value="2">CSS</option>
      <option value="3">JS</option>
      <option value="4">Perl</option>
    </datalist>
  </label>
  <label for="alter">Alter:
      <input type="number" id="alter" name="alter" min="0">
  </label>
  <br>
    <label for="tage">Tage:
      <input type="range" id="tage" name="Tage" min="5" max="42" step="1" value="6">
  </label>
  <br>
  <label for="sturi">Studienrichtung:
    <fieldset id="sturi">
      <label for="pi">PI
        <input type="radio" name="mussGleichSein" id="pi" value="1">
      </label>
      <label for="wi">WI
        <input type="radio" name="mussGleichSein" id="wi" value="2">
      </label>
      <label for="ti">TI
        <input type="radio" name="mussGleichSein" id="ti" value="3">
      </label>
  </label>
  <br>
    <label for="sonder">Sonderheiten:
    <fieldset id="sonder">
      <label for="polster">Polsterstuhl
        <input type="checkbox" name="sonder" id="polster" value="1">
      </label>
      <label for="steckdose">Steckdose
        <input type="checkbox" name="sonder" id="steckdose" value="2">
      </label>
      <label for="loge">Privatloge
        <input type="checkbox" name="sonder" id="loge" value="3">
      </label>
  </label>
  <label for="farbe">Wähle eine Farbe:
    <input type="color" id="farbe" name="hintergrund">
  </label>
</form>
```

## CSS

## JS

# PHP und Datenbanken

# Moderne Webentwicklung mit Frameworks
