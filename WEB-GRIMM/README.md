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

- [Prüfungsleistung](#pr%C3%BCfungsleistung)
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
      - [Zeilenumbrüche](#zeilenumbr%C3%BCche)
      - [Formulare](#formulare)
      - [Formular-Elemente](#formular-elemente)
    - [Universal Attribute](#universal-attribute)
    - [Positionierungselemente](#positionierungselemente)
  - [CSS](#css)
    - [Syntax](#syntax)
    - [Farben](#farben)
    - [Einheiten](#einheiten)
    - [Selektoren](#selektoren)
      - [Kombinierte Selektoren](#kombinierte-selektoren)
      - [Pseudoselektoren](#pseudoselektoren)
    - [Berechnungen](#berechnungen)
    - [Attributselektoren](#attributselektoren)
    - [Beispiel-CSS](#beispiel-css)
    - [Flex-Container](#flex-container)
    - [Grid-Container](#grid-container)
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
    <meta name="color-scheme" content="light dark">
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

#### Formular-Elemente

- `label` (Beschriftung)
- `input` (Eingabefeld)
  - Attribute: `name`, `maxlength`, `minlength`, `required`, `pattern`, `value`, `placeholder`, ...
    - `type` = `text`, `search`, `password`, `tel`, `url`, `email`, `number` (mit `min`, `max`, `step`), `range`
- `textarea` (mehrzeiliges Textfeld)
- `button` (Button, Schalter)
- `select` (Auswahllisten)
  - `option` (Auswahloption)
  - `optgroup` (verschachtelte Auswahllisten)
  - `fieldset` (Gruppierung)

```html
<form id="bsp" name="Beispiel" action="index.html" method="post" enctype="multipart/form-data">
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
  <fieldset>
    <legend>Studienrichtung</legend>
    <label for="pi">PI
      <input type="radio" name="mussGleichSein" id="pi" value="1">
    </label>
    <label for="wi">WI
      <input type="radio" name="mussGleichSein" id="wi" value="2">
    </label>
    <label for="ti">TI
      <input type="radio" name="mussGleichSein" id="ti" value="3">
    </label>
  </fieldset>
  <br>
  <fieldset>
    <legend>Sonderheiten</legend>
    <label for="polster">Polsterstuhl
      <input type="checkbox" name="sonder" id="polster" value="1">
    </label>
    <label for="steckdose">Steckdose
      <input type="checkbox" name="sonder" id="steckdose" value="2">
    </label>
    <label for="loge">Privatloge
      <input type="checkbox" name="sonder" id="loge" value="3">
    </label>
  </fieldset>
  <label for="farbe">Wähle eine Farbe:
    <input type="color" id="farbe" name="hintergrund">
  </label>
  <label for="passbild">Passbild:
    <input type="file" id="passbild" name="passbild" accept="image/*" multiple>
    <!-- enctype="multipart/form-data" nötig, sonst wird nur der Dateiname übertragen -->
  </label>
  <label for="gebDat">Geburtsdatum:
    <input type="date" id="gebDat" name="gebDat">
  </label>
  <label for="essen">Essen:
    <select id="essen" name="essen">
      <option>alles</option>
      <option>vegetarisch</option>
      <option>vegan</option>
    </select>
  </label>
  <br><br>
  <label for="anmerkungen">Anmerkungen:
    <textarea cols="80" rows="15" name="anmerkungen" id="anm">
      Ich bin eine Textbox
    </textarea>
  </label>
  <br><br>
  <input type="submit" value="Absenden" name="senden">
  <input type="reset" value="Zurücksetzen" name="löschen">
</form>
```

### Universal Attribute

- `id`: eindeutiger Identifikator für Elemente (als Link, CSS-Selektor)
- `class`: Kennzeichnung zusammengehöriger Elemente (CSS-Selektor)
- `accesskey`: Taste zum Anspringen des Elementes
- `contenteditable`: Inhalt kann verändert werden
- `dir`: ltr/rtl-Layout
- `hidden`: Element wird ausgeblendet
- `draggable`: Element kann gedragt werden
- `dropzone`
- `lang`: Sprache festlegen
- `style`: inline CSS (meiden!)
- `tabindex`: Tab-Reihenfolge
- `title`: Elementenbeschreibung $\rightarrow$ Tooltip

### Positionierungselemente

- HTML-Elemente sind entweder Blöcke oder inline
  - Blöcke erzeugen Newline
- alle HTML-Elemente werden von Boxen umgeben (innen nach außen)
  - Content
  - Padding
  - Border
  - Margin

## CSS

- **C**ascading **S**tyle **S**heet
- Trennung der Darstellung vom Inhalt

**Einbindung**

- inline CSS (`style="..."`)
- `<style></style>` im HTML
- externes CSS einbinden (`<link rel="stylesheet" type="text/css" href="style.css">` im ``<head>``)

### Syntax

- Eigenschaften werden in Regelsätzen gespeichert
- arbeitet anhand von Selektoren
- case-sensitiv
- Kommentare: ``/*...*/``

```css
selector{
  property: value;
}
```

### Farben

**RGB-Farbmodell**

- hex: `#ff7f50`
- dezimal: `rgb(0,128,0)`
- prozentual: `rgb(60%, 20%, 40%)`

> Alphakanal auch möglich: `#ff7f50ff`, `rgba(0,128,0,42)`, ...

**HSL-Farbmodell**

- **h**ue, **s**aturation, **l**ightness
- `hsl(200,100%,50%)`, `hsla(200,100%,50%,1)`

### Einheiten

- Ganz- oder Fließkommazahlen (Dezimalzeichen ist der Punkt)
- Maßeinheit direkt direkt nach der Zahl (ohne Leerzeichen)
- Physische Maße: Zoll (`in`), Zentimeter (`cm`), Pixel (`px`)
- relative Längenmaße:
  - `em`: Schriftgröße des Elements
  - `ex`: Größe von x
  - `vw`/`vh`: Prozent der Viewportbreite/-höhe (Anzeigebereich)
  - `vmin`/`vmax`: minimales/maximales Maß des Viewports
  - `%`: Prozentual im Verhältnis zum übergeordnetem Element
- Winkelmaße: Grad (`deg`), Radiant (`rad`)
- Zeit: Sekunden (`s`), Millisekunden (`ms`)

### Selektoren

- Typselektor: HTML-Element (`body`, `h1`, `p`, `li`, ...) $\rightarrow$ wirken für alle Elemente diesen Typs
- Universalselektor: `*`
- Klassenselektor: `.` als Prefix (`.column`, `.btn`, ...) $\rightarrow$ wirken für alle Elemente mit bestimmten Klassen-Attribut
- ID-Selektor: `#` als Prefix (`#header`, `#footer`, ...) $\rightarrow$ wirkt für ein Element mit einer bestimmten ID

> Wichtig: **Cascading** $\rightarrow$ spezifischere Selektoren überschreiben Unspezifischere (`*` < `typ` < `.class` < `#id` < inline CSS)
> für gleichrangige Selektoren gilt: das zuletzt definierte überschreibt das zuerst definierte

#### Kombinierte Selektoren

- Verbundselektoren: `*.class`, `h2#title.classA.classB`
- Nachfahrenkombinator: `p em{...}` (alle untergeordneten Elemente, unabhängig von der Tiefe)
- Kindkombinator: `ul > li{...}` (nur direkte Kindelemente)
- Nachbarkombinator: `h1 + p{...}` (direkter Nachfolger)
- Geschwisterkombinator `h1 ~ p{...}` (für Element auf gleicher Ebene)

#### Pseudoselektoren

**Pseudoklassen:** beziehen sich auf Eigenschaften der HTML-Element

- `:empty`, `:first-child`, `:last-child`, `:nth-child()`
- `:hover`, `:link`, `:visited`, `:active`, `:focus`
- `:disabled`, `:enabled`, `:checked`
- `:valid`, `:invalid`, `:optional`, `:in-range`, `:out-of-range`
- nicht alle Pseudo-Klassen funktionieren mit allen Elementen!

**Pseudoelemente**

- `::first-line`, `::first-letter`
- `::before`, `::after`
- `::backdrop`
- `::selection`, `::placeholder`, `::marker`

### Berechnungen

- für ``nth-child()`` können Folgen berechnet werden
- Syntax: ``An+B``, wobei A und B zu ersetzen sind
- Beispiel: ``tr:nth-child(2n+1)`` wählt jede zweite Tabellenzeile, und zwar die ungeraden
  - es gibt auch ``even`` und ``odd``
- Dokumentation: [Mozilla](https://developer.mozilla.org/en-US/docs/Web/CSS/:nth-child)

### Attributselektoren

- Syntax: `[Attributname=Wert]` oder `[Attribut]`
- Beispiel: `p[andre]{}` wählt alle `<p>`-Tags, die das André-Attribut haben (also `<p andre>`)
- `^=`: beginnt mit
- `$=`: endet mit
- `*=`: enthält genauen Wert
- `~=`: enthält genauen Wert (mit Leerzeichen getrennt, vgl. class)
- `|=`: enthält genauen Wert oder mit Wert beginnend gefolgt von "-" (mit Leerzeichen getrennten, vgl. class)
- "OR"-Verknüpfung im HTML: `<p andre="andre klaus grimm">`
- [siehe MSDN für bessere Erklärungen](https://developer.mozilla.org/de/docs/Web/CSS/Attribute_selectors#%C3%BCbersicht)

### Beispiel-CSS

<!-- md2apkg ignore-card -->
<!--🤮-->

```css
* {
  font-family: Verdana, sans-serif;
}
h2 {
  color: rgb(5, 80, 51);
}
#main-title {
  background-color: darkslategray;
  color: floralwhite;
  padding: .5em;
  border-radius: .8em .8em 0 0;
  margin-bottom: 1cm;
}
#main-foot {
  border: solid 2px darkslategray;
  border-radius: 0 0 .8em .8em;
  padding: 1em;

  flex-direction: row;
}
#mein-kontakt {
  position: absolute;
  top: 1em;
  left: 20px;
}
#flex-container {
  display: flex;
  flex-direction: row;
  justify-content: space-evenly; /*horizontale Ausrichtung*/
  flex-wrap: wrap; /*Der Bandscheibenvorfall*/
  align-items: center;
  height: 20vh;
  width: 70vw;
  border: 1px solid black;
}
```

### Flex-Container

### Grid-Container

- können HTML als Raster formatieren

```css
.grid-container {
  display: grid;
  grid-template-columns: 1fr 2fr 1fr; /*Anzahl der Spalten in Fractions, Platz wird aufgeteilt*/
  grid-template-rows: 1fr 2fr 1fr;
  justify-content: center;
  height: 40vh;
  width: 80vw;
  margin: 0 auto;
}
```

## JS

# PHP und Datenbanken

# Moderne Webentwicklung mit Frameworks

<!--Haha, LOL-->
