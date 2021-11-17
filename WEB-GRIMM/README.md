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
    - [HTML-Struktur](#html-struktur)
    - [Text-Formatierung](#text-formatierung)
    - [Hyperlinks](#hyperlinks)
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
    - [Media-Queries](#media-queries)
  - [JS](#js)
    - [Fancy-Input Beispiel](#fancy-input-beispiel)
- [PHP und Datenbanken](#php-und-datenbanken)
  - [Datenbankschnittstellen](#datenbankschnittstellen)
  - [Stringoperationen](#stringoperationen)
  - [Sessions](#sessions)
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

# Was ist eine Webanwendung?

- Web = World Wide Web $\rightarrow$ Teil des Internets
- Client-Server-Anwendung (Client = Browser)
- Pattformunabhängig, keine zusätzliche Installation
- Nutzung des Hypertext Transfer Protocol (`http`)
- Interaktion mit dem Nutzer

# Client-Technologien

- HTML 5 $\rightarrow$ Beschreibung der Struktur der Webseiten
- CSS 3 $\rightarrow$ Formatierung / Aussehen
- Java-/ECMA-Script $\rightarrow$ Interaktion
- DOM/Ajax $\rightarrow$ Manipulation des Seiteninhalts
- Flash $\rightarrow$ obsolet
- JSON, XML(SVG, MathML, RSS, GraphML, ...) $\rightarrow$ Datenaustausch

# Server-Technologien

- PHP
- NodeJS
- Ruby (on Rails)
- Java
- ASP.NET
- ColdFusion

# HTML

- 1991 publiziert durch Entwickler Burners-Lee
- verbreitet sich rasend schnell als ~~"Programmiersprache"~~ (Auszeichnungssprache) des Internets
- letzte Version: HTML 5.2 (14. Dezember 2017)
- Arbeitsentwurf für 5.3 seit 18. Oktober 2018

## HTML-Syntax

- Auszeichnung von Textelementen durch Tags
- ``<tag>Text</tag>``
- Öffnendes Tag $\rightarrow$ schließendes Tag $\rightarrow$ dazwischen Body
- schließende Tags können in einigen Fällen entfallen (z.B. `<img/>`)
- Tags können Attribute enthalten ``<tag attribut="Wert">body</tag>``

Beispiel-Skelett:

```html
<!DOCTYPE html>
<!--DOCTYPE ist kein HTML-Tag! sondern DTD (document type definition)-->
<html lang="en">
  <head>
    <!--verwendeter Zeichensatz-->
    <meta charset="utf-8" />
    <!--kann Funktion eines HTTP-Response-Headers erfüllen-->
    <meta http-equiv="x-ua-compatible" content="ie=edge" />
    <!--Größe der Darstellung auf Displaygröße des Devices anpassen-->
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!--Name des Autors-->
    <meta name="author" content="anonymous" />
    <!--Beschreibung des Inhalts der Seite-->
    <meta name="description" content="404 - not found" />
    <!--Seite stellt zwei Farbschemata zur Verfügung, bevorzugt hell -->
    <meta name="color-scheme" content="light dark">
    <title>Hier steht der Titel der Seite</title>
    <link rel="stylesheet" href="css/main.css" />
    <link rel="icon" href="images/favicon.png" />
  </head>

  <body>
    <!-- insert comment here -->
    <script src="js/scripts.js"></script>
  </body>
</html>
```

### HTML-Struktur

- ``<html>`` ist sogenanntes Wurzeltag
  - Attribut "lang" gibt die Dokumentensprache an
- in ``<head>...</head>`` wird der Dateikopf beschrieben
  - hier Metainformationen über die Website
  - wird auf der Seite nicht dargestellt
  - Informationen werden durch Browser, Suchmaschinen und Crawler benutzt
- in ``<body> ... </body>`` wird der "Hauptteil" der Seite beschrieben
- Kommentare mit ``<!-- Kommentar -->``

### Text-Formatierung

> Hinweis: diese Tags werden zwar von vielen Browsern noch dargestellt, sind aber eigentlich veraltet und sollten nicht mehr verwendet werden

- ``<b> ... </b>`` um Text fett zu formatieren
- ``<u> ... </u>`` um Text zu unterstreichen
- ``<i> ... </i>`` für Kursivschreibung
- ``<font> ... </font>`` mit folgenden Attributen:
  - color - Schriftfarbe
  - face - Schriftart
  - size - Schriftgröße

### Hyperlinks

- werden in ``<a> Linktext </a>`` definiert
- durch ``href``-Attribut wird das Linkziel festgelegt: ``<a href="https://www.dhge.de"> Hier gehts zur DHGE </a>``
- URLs können relativ oder absolut sein:
  - Absolute URLs für externe Ziele (wie DHGE-Beispiel)
  - relative URLS für lokale Ziele: ``<a href="index.html">Nach Hause</a>``
  - spezielle Verweise:
  - ``<a href=""> RELOOOAD </a>`` - Seite neu laden
  - ``<a href="#"> Nach oben </a>`` - Zum Seitenbeginn springen
  - ``<a href="#id"> gimme this </a>`` - Zum Seitenelement mit der angegebenen ID springen
- ``download``-Attribut um anzugeben, dass Linkziel heruntergeladen werden soll
- ``target``-Attribut um festzulegen, wie der Browser die Seite öffnen soll
  - eher nicht verwenden, Freiheit der Entscheidung dem User überlassen, zudem teilweise unsicher
  - ``<a href="Ziel" target="_self">`` - auf der selben Seite öffnen
  - ``<a href="Ziel" target="_blank">`` - auf neuer Seite (in neuem Tab) öffnen
- ``title``-Attribut: Linkbeschreibung, für Tooltips und Screenreader
- ``type``-Attribut: MIME-Typ angeben, um Ausführung der Datei zu spezifizieren

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

### Bilder

- Tag: ``<img>`` $\rightarrow$ kein schließendes Tag!
- Attribute:
  - ``src`` : Pfad zur Bilddatei - veraltet, besser: ``srcset``
  - ``alt`` : Bildbeschreibung für Screenreader oder falls Datei nicht gefunden: **wichtig!**
  - ``height`` und ``width``: Höhe und Breite des Bildes angeben
  - ``ismap``: serverseitige Image Map, bei Klick werden Mauskoordinaten an Server gesendet
    - ``<img>``-Tag muss dafür innerhalb eines ``<a>``-Tags stehen
    - zudem muss das auswertende Skript verlinkt werden
  - ``usemap``: in Verbindung mit Map-Tag
  - responsive Bilder mit Attribut ``srcset``
    - wählt Bilder je nach Größe des Viewports aus, lädt ggf. nach falls sich Viewport ändert
    - best practice unter <https://www.mediaevent.de/html/srcset.html>
- Map-Tag:
  - ``<map name="NAME">``
  - in Verbindung mit ``<img usemap ...>``
  - Definition einer verweissensitiven Fläche, die mit Sprungziel verknüpft ist

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

### Listen

- es gibt sortierte (``ol``), unsortierte (``ul``) und Beschreibungs-Listen (``dl``)
- Listenelemente tragen das ``li``-Tag
- geordnete Listen
  - nummeriert
  - ``start``-Attribut gibt Startwert für Nummerierung an
  - ``reversed``-Atttribut für umgekehrte Zählrichtung
  - ``type``-Tag für die Art der Aufzählungszeichen
    - ``1`` für arabische Ziffern (Standard)
    - ``A`` für Großbuchstaben
    - ``a`` für Kleinbuchstaben
    - ``I`` für große römische Zahlen
    - ``i`` für kleine römische Zahlen
  - ``value`` um den Startwert des ersten Eintrags festzulegen
- ungeordnete Listen:
  - Reihenfolge nicht wichtig
  - ``type``-Attribut (deprecated)
- Beschreibungsliste
  - zweiteilig: Listenelement besteht aus ``dt`` (description term) und ``dd`` (description description)
  - wird z.B. für Glossare verwendet
  - zu einem ``dt`` können mehrere ``dd`` gehören

Beispiel für Listen:

```html
<!--Ungeordnet-->
<ul>
  <li>Listenpunkt 1</li>
  <li>Listenpunkt 2</li>
  <li>Listenpunkt 3</li>
</ul>

<!--Geordnet-->
<ol>
    <li value ="100"> Item Nummer 100 </li>
    <li> Item Nummer 101 </li>
</ol>
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

### Tabellen

- strukturierte Datensammlung
- Anwendung in z.B. Kalendern, Stundenplänen, Fahrplänen, ...
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
  <caption>Stundenplan PI19</caption>
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

### Zeilenumbrüche

- werden erzwungen mit ``<br>``
- Browser wird bei Leerzeichen einen Zeilenumbruch einfügen, wenn notwendig
- ``<wbr>``: Word Break - unsichtbare Markierung, wo der Browser ggf. einen Zeilenumbruch einfügen kann
- ``&shy;``: wie ``<wbr>``, fügt aber einen Bindestrich ein

### Formulare

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
  - `autocomplete="on|off"`: Autovervollständigung aktivieren/deaktivieren
  - `novalidate`: nicht auf Vollständigkeit prüfen (Plausibilität)

### Formular-Elemente

- `label` (Beschriftung)
- `input` (Eingabefeld)
  - Attribute: `name`, `maxlength`, `minlength`, `required`, `pattern`, `value`, `placeholder`, ...
    - `type` = `text`, `search`, `password`, `tel`, `url`, `email`, `number` (mit `min`, `max`, `step`), `range`
- `textarea` (mehrzeiliges Textfeld)
- `button` (Button, Schalter)
  - `type` = ``button|submit|reset``
- `select` (Auswahllisten)
  - `size` Anzahl angezeigter Elemente
  - `multiple` Mehrfachauswahl
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

## Universal Attribute

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

## Positionierungselemente

- HTML-Elemente sind entweder Blöcke oder inline
  - Blöcke erzeugen Newline
- alle HTML-Elemente werden von Boxen umgeben (innen nach außen)
  - Content
  - Padding
  - Border
  - Margin

# CSS

- **C**ascading **S**tyle **S**heet
- Standard des W3C (World Wide Web Consortium)
  - erstmals 1996 standardisiert
  - aktuell Version 3
- Trennung der Darstellung vom Inhalt
  - Darstellungsmerkmale der HTML-Elemente werden beschrieben (Farbe, Größe, Position)

**Einbindung**

- inline CSS (`style="..."`)
- `<style></style>` im HTML-Header
- externes CSS einbinden (`<link rel="stylesheet" type="text/css" href="style.css">` im ``<head>``)

## Syntax

- Eigenschaften werden in Regelsätzen gespeichert
- arbeitet anhand von Selektoren/Selektorenlisten
- Basissyntax: ``selektor{ eigenschaft1: wert; eigenschaft2: wert;}``
- Klassen- und ID-Bezeichner sind **case-sensitiv**
- Kommentare: ``/*...*/``

```css
h3{
  color: yellow;
  font-size: 2em;
}
```

## Farben

**RGB-Farbmodell**

- hex: `#ff7f50`
- dezimal: `rgb(0,128,0)`
- prozentual: `rgb(60%, 20%, 40%)`
- Alphakanal auch möglich: `#ff7f50ff`, `rgba(0,128,0,42)`, ...
  - der vierte Wert bestimmt dabei die Deckkraft
    - hex: 00 (transparent) bis ff (volle Deckung)
    - dez: 0 (transparent) bis 1 (volle Deckung)

**HSL-Farbmodell**

- **h**ue, **s**aturation, **l**ightness
- hue für Farbton: 0 - 360
- saturation für Sättigung: 0-100 (Prozentangabe)
- lightness für Helligkeit: 0-100 (Prozentangabe)
  - 50 ist normale Helligkeit
- Alphakanal auch hier möglich
- `hsl(200,100%,50%)`, `hsla(200,100%,50%,1)`

**CMYK-Modell**

- Farbauswahl hier naach standardisierten Namen

> Palette unter <https://wiki.selfhtml.org/wiki/Grafik/Farbe/Farbpaletten#Farbnamen>

## Einheiten

**Zahlen:**

- Ganz- oder Fließkommazahlen (Dezimalzeichen ist der Punkt)
- Null vor dem Punkt ist optional
- Maßeinheit direkt nach der Zahl (ohne Leerzeichen)
- Maßeinheit für 0 optional

**Physische Längenmaße:**

- Zoll (`in`), Zentimeter (`cm`), Pixel (`px`)
- relative Längenmaße:
  - `em`: Schriftgröße des Elements
  - `ex`: Größe von x
  - `vw`/`vh`: Prozent der Viewportbreite/-höhe (Anzeigebereich)
  - `vmin`/`vmax`: minimales/maximales Maß des Viewports
  - `%`: Prozentual im Verhältnis zum übergeordnetem Element

**weitere Maße:**

- Winkelmaße: Grad (`deg`), Radiant (`rad`)
- Zeit: Sekunden (`s`), Millisekunden (`ms`)

## Selektoren

- Typselektor: HTML-Element (`body`, `h1`, `p`, `li`, ...) $\rightarrow$ wirken für alle Elemente diesen Typs
- Universalselektor: `*`
- Klassenselektor: `.` als Prefix (`.column`, `.btn`, ...) $\rightarrow$ wirken für alle Elemente mit bestimmten Klassen-Attribut
- ID-Selektor: `#` als Prefix (`#header`, `#footer`, ...) $\rightarrow$ wirkt für ein Element mit einer bestimmten ID
  - **wichtig:** Unterschiede zwischen CSS- und HTML5-Spezifikationen zur ID-Benamung beachten

> Wichtig: **Cascading** $\rightarrow$ spezifischere Selektoren überschreiben Unspezifischere (`*` < `typ` < `.class` < `#id` < inline CSS)
> für gleichrangige Selektoren gilt: das zuletzt definierte überschreibt das zuerst definierte

### Kombinierte Selektoren

- Verbundselektoren: `*.class`, `h2#title.classA.classB`
- Nachfahrenkombinator: `p em{...}` (alle untergeordneten Elemente, unabhängig von der Tiefe)
- Kindkombinator: `ul > li{...}` (nur direkte Kindelemente)
- Nachbarkombinator: `h1 + p{...}` (direkter Nachfolger)
- Geschwisterkombinator `h1 ~ p{...}` (für Element auf gleicher Ebene)

### Pseudoselektoren

**Pseudoklassen:** beziehen sich auf Eigenschaften der HTML-Elemente $\rightarrow$ Abfrage eines besonderen Zustandes

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

## Berechnungen

- für ``nth-child()`` können Folgen berechnet werden
- Syntax: ``An+B``, wobei A und B zu ersetzen sind
- Beispiel: ``tr:nth-child(2n+1)`` wählt jede zweite Tabellenzeile, und zwar die ungeraden
  - es gibt auch ``even`` und ``odd``
- Dokumentation: [Mozilla](https://developer.mozilla.org/en-US/docs/Web/CSS/:nth-child)

## Attributselektoren

- Syntax: `[Attributname=Wert]` oder `[Attribut]`
- Beispiel: `p[andre]{}` wählt alle `<p>`-Tags, die das André-Attribut haben (also `<p andre>`)
- `^=`: beginnt mit
- `$=`: endet mit
- `*=`: enthält genauen Wert
- `~=`: enthält genauen Wert (mit Leerzeichen getrennt, vgl. class)
- `|=`: enthält genauen Wert oder mit Wert beginnend gefolgt von "-" (mit Leerzeichen getrennten, vgl. class)
- "OR"-Verknüpfung im HTML: `<p andre="andre klaus grimm">`
- [siehe MSDN für bessere Erklärungen](https://developer.mozilla.org/de/docs/Web/CSS/Attribute_selectors#%C3%BCbersicht)

## Beispiele 1

<!-- md2apkg ignore-card -->
<!--🤮-->

```css
/*Typselektor: jeder Textabsatz hat die angegebene Farbe & Sxhriftgröße von 2em*/
p{
  color: rgb(14, 5, 173);
  font-size: 2em;
}

/*Universalselektor: jeder Textabsatz ist 3em eingerückt*/
*{ margin: 3em}

/*Klassenselektor: alle Elemente aus klasse1 und klasse2 haben gelben Hintergrund*/
.klasse1.klasse2{
  background: yellow
}

/*ID-Selektor: Schrift für Element mit "wichtig"-ID ist fett*/
#wichtig { font-weight: bold}

/*Attributselektor: alle Elemente mit title-Attribut haben schwarze Schrift*/
[title] {color: black}

/*Attributselektor: alle Elemente mit title-Attribut, die im Titel-Wert "test" beinhalten haben grüne Schrift */
[title*="test"] {color: green}

/*Pseudoklassen: alle ersten Eintrage einer Liste grün, alle anderen rot*/
li{color:red;}
li:first-child{color:green;}

```

## Flex-Container

- eindimensionales Layout Modell:
  - behandelt Spalte oder Zeile, nie beide auf einmal
- das kann zu unerwünschten Ergebnisses führen, wenn aufgrund eines kleinen Viewports Elemente verschoben werden (siehe Beispiele 2)

> weitere Ausführungen sparen wir uns an der Stelle. Wirklich gut zu dem Thema Flex vs. Grid vs. Box: <https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Grid_Layout/Relationship_of_Grid_Layout>

## Grid-Container

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

- Linien in Zeilen / Spalten kann man Namen geben: ``grid-template-coloumns: [vorne] fit-content [mitte] 2fr [hinten] 3fr``
- negative Zahlen in bspw. ``grid-coloumn`` zählen von rechts nach links (d.h. vom Ende aus)
- man kann alternativ die ganze Tabelle auf einmal definieren:

```css
grid-template-areas: "head head head head"
                     "nav main main main"
                     "nav main main main"
                     "foot foot foot foot"
                     ;
```

## Beispiele 2

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

## Media-Queries

- eingeführt, um Websiten responsiver zu gestalten und auf das Betrachtungsmedium besser anzupassen
- kann Elemente bei zu kleiner Displagrößer verstecken und umformatieren
- Deklaration: ``@media (bedingung) {style}``

> Mehr dazu: <https://www.w3schools.com/css/css_rwd_mediaqueries.asp> daher auch das Beispiel:

```css
 /* Extra small devices (phones, 600px and down) */
@media only screen and (max-width: 600px) {...}

/* Small devices (portrait tablets and large phones, 600px and up) */
@media only screen and (min-width: 600px) {...}

/* Medium devices (landscape tablets, 768px and up) */
@media only screen and (min-width: 768px) {...}

/* Large devices (laptops/desktops, 992px and up) */
@media only screen and (min-width: 992px) {...}

/* Extra large devices (large laptops and desktops, 1200px and up) */
@media only screen and (min-width: 1200px) {...} 
```

# JS

- mittels `<script>`-Tag
- inline im Tag oder mit `<script src="müll.js">`
- Ausführung im Browser mit bspw. Chromiums V8 oder Firefox' SpiderMonkey
- Ausführung auch unabhängig vom Browser mit Node (nicht Node.js)
- grundsätzlich C-like Sprache
- Variablendeklaration: ``var Bezeichner`` oder nur ``Bezeichner``
  - mit Scope: ``let Bezeichner``
- case-sensitiv
- implizite Datentypen und Umwandlungen
- "Dodo-Modus": `use strict`
- Vergleiche:
  - ``==``: vergleicht auf denselben Wert, aber castet implizit
  - ``===`` vergleicht auf denselben Wert und denselben Datentyp

## Fancy-Input Beispiel

In diesem Beispiel wird JavaScript verwendet, um das Label eines Inputs dynamisch zu verändern.

Das Beispiel ist im Ordner `extra/fancy-input` zu finden.

# PHP und Datenbanken

- Einbettung mit:

```html
<?php

?>
```

- Anzeige von Buildoptionen: ``phpinfo();``
- Variablendeklaration mit ``$lowerKamelBezeichner``
- Datentypen: Integer, Float, Double, Boolean
- ``var_dump()`` gibt Datentyp und Inhalt aus $\rightarrow$ evtl. hilfreich für Debugging
- erwähnenswerte Operatoren:
  - ``.``: Punktoperator verknüpft Strings: ``echo "Hallo".$fullName."!"``
  - logische Operatoren ausgeschrieben, z.B. ``AND``, ``OR``; Ausnahme: Not-Operator bleibt ``!``
  - ``pow($basis, $exp)``
  - ``sqrt($i)``
- Fallen beim impliziten Casten: ``strpos()`` gibt im Fehlerfall ``false`` zurück, was implizit auf ``int`` gecastet werden kann
  - hier hilft der ``===``-Operator
- switch-cases müssen mit ``break;`` beendet werden
- Arrays: ``$name = array("Franz", "Xaver", "Viktor", "Jochen");``
  - sind immer dynamisch
  - appenden mit ``$name[] = "Franziska";``
  - es gibt auch assoziative Array, also mit benannten Indizes:
- Funktionen unterstützen Standard-Parameter wie in C++
- Javadoc-artige Kommentare werden unterstützt

```php
$wochentage = array(
  "so" => "Montag",
  "mo" => "Dienstag",
  "di" => "Es ist Mittwoch, meine Kerle"
  /*>:)*/
)
```

- For-each-Schleifen: ``foreach($namen as $person)`` und für assoziative Arrays: ``foreach($wochentage as $kurz => $lang)``
- Array-Elemente mit Trennzeichen ausgeben: ``echo "Namen: ".implode(", ", $namen).<br>``
  - Achtung: der Punkt ist kein Bestandteil von Objektorientierung, siehe oben
- das geht auch umgedreht:

```php
$farben = "rot, gelb, weiß, blau";
$farbenArray = explode(", ", $farben);
```

Mehrdimensionale Arrays:

```php
$mitarbeiter = array(
  array("Rv", "Novae"),
  array("ZeroPoint", "Max"),
  array("Steve", "2955"),
  array("nuker", "xy")
)

foreach($mitarbeiter as $person)
  echo "<li>".$ma[0]." ".$ma[1]."</li>";
```

- Arraylänge berechnen: ``count()``
- Element in Array suchen: ``in_array("weiß", $farben);``
- Prüfen, ob Array-Index existiert: ``array_key_exists("fr", $wochentage)``
- sortieren von Arrays mit ``sort($mitarbeiter)`` bzw. ``rsort($mitarbeiter)`` (reverse)
  - Achtung: case-sensitiv nach ASCII
  - Achtung: es werden KEINE neuen Indizes vergeben
- Ausgabe der Zeit: ``date("d-m-Y H:i:s", time());``
- Umwandlung einer Zeit in den Unix-Timestamp: ``strtotime("11 November 2011 11:11")``
- Abfragen von Formularinhalten: ``print_r($_POST);``
  - Formularinhalte sind in einem assoziativen Array gespeichert

## Datenbankschnittstellen

- verschiedenes im Angebot: ``mysqli``, ``PDO``
- Bsp.: ``$dbh = new PDO($connectionstring, $user, $pw);``
- Connection-String: ``$connectionstring = "mysql:host=localhost;dbname=dhge";``
- Um unangekündigten Besuch vom Datenschutzbeauftragten zu vermeiden, sollte man Exception Handling einbauen, sodass der Server im Fehlerfall nicht die Verbindungsdaten leakt

## Stringoperationen

- ``strpos(haystack, needle [, offset])``: sucht ``needle`` in ``haystack``, ggf. nach Offset. Gibt Zeichenindex vom Wortbeginn aus, oder ``false``.
- ``substr(haystack, needle [, length])``: sucht ``needle`` in ``haystack`` und gibt den String ab da aus, ggf. nur ``length`` Zeichen, oder ``false``.
- ``str_replace(needle, replace, haystack)``: sucht ``needle`` in ``haystack`` und ersetzt sie durch ``replace``. Case-sensitiv.
  - case-insensitive Funktion: ``str_ireplace(...)``
- ``nl2br(src)``: wandelt ``\n`` in ``src`` zu ``<br>`` und gibt diesen String zurück

## Sessions

- Daten wie Session ID werden im Browser permanent gespeichert, um den Nutzer zu identifizieren
  - Zweck: u.a. unnötige Logins vermeiden
- Session erzeugen: ``session_start()``
  - darf nur einmal auf dem Seitenkomplex<!--manche Profs würden das _Website_ nennen--> vorkommen
- Daten werden in ``$_SESSION``-Array gespeichert
  - Bsp.: ``$_SESSION["name"] = Franz;``
- ``session_destroy()`` löscht die Session

# Moderne Webentwicklung mit Frameworks

<!--Haha, LOL-->
