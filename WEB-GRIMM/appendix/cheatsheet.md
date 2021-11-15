# Technologien für Web-Anwendungen

- HTML 5 -> Beschreibung der Struktur der Webseiten
- CSS 3 -> Formatierung/Aussehen
- Java /EMCA -Script -> Interaktion
- DOM / Ajax -> Manipulation des Seiteninhalts
- Flash -> obsulete
- XML -> Datenaustausch
- PHP
- Ruby (on Rails)
- Java Applet
- ASP.net
- ColdFusion

# HTML

## Werkzeuge

- Texteditor
- WYSIWYG - Editor (What You See Is What You Get)

### hilfreiche Funktionen

- Autovervollständigung
- Syntaxhighlighting
- Einrückungsautomatik
- Projektverwaltung
- Verwaltung von Code Snippets
- Debugger bzw. Prüfung des HTML/CSS-Codes

## Grundgerüst

```html
<!DOCTYPE html> <!-- Definition des Dokumententypens-->
<html lang="de">
    <head> <!-- Dateikopf-->
    </head>
    <body>
        <script src=""></script>
        <header></header>
        <nav></nav>
        <main>
            <article>
                Mit eigenem header, Überschrift, footer...
                <section>
                </section>
            </article>
        </main>
        <footer></footer>
        <aside></aside>
    </body>
```

## Head

```html
<meta charset=UTF-8>
<meta name="description" content="Seite">
<meta name="keywords" content="HTML, CSS">
<meta name="author" content="John Doe">
<link rel="stylesheet" href="styles.css">
<title>Titel</title>
```

## Links

- `a` -> anchor
- `href=dokument` ODER `=#ziel` ODER `=dokument#ziel`
- `href=""` -> Seite neuladen
- `href="#"` || `href="#top"` -> Seitenanfang
- `download` -> bei href angegebene Datei soll heruntergeladen werden
- `target` -> wo Linkziel öffnen
  - `_blank` -> neue Seite
  - `_self` -> selbes Fenster
  - `_parent` -> im Elternfenster
  - `_top` -> im obersten Fenster
  - Fenstername

## Listentypen

- sortiert -> `ol`
- unsoritert -> `ul`
- Beschreibungsliste -> `dl`

## Tabellen

- `<table>`
- Zeile: `<tr>`
- Zelle: `<td>`
- Kopfzelle: `<th>` (`scope`-Attribut: Zeilen- oder Spaltenkopf)

## Formulare

```html
<form action="" id=form1 method="GET">
    <label for="name">Name:
        <input id=name type=text name=name required>
    </label>
    ...
```

- ID und Name bestenfalls identisch halten
- `<fieldset>` $\rightarrow$ Formularelemente gruppieren

### Input

- type: text, email, tel, password, url, search, number, range, radio, checkbox, hidden, file, color, date, submit, reset
- weitere Attribute: maxlength, minlength, min, max, required, pattern, value, placeholder

### Select

- Ausswahlliste in Formularen
- Elemente innerhalb des Body mit `<option>`
- verschachtelte Auswahlliste `<optgroup>`
- Attribute: name, size, multiple
- Attribut für `<option>`: selected

### Formular-Beispiel

```html
<form id="annmeldSem5" name="annmeldSem5"
        method="GET" action="" enctype="multipart/form-data">
    <label for="name">Name:
        <input name="vorname" id="name"
        maxlength="10" value="Hilde">
    </label>
    <label for="suche">Suchen:
        <input type="search" name="suche" id="suche"
            maxlength="10" placeholder="Suchbegriff" list="liste">
        <datalist id="liste">
            <option>HTML</option>
            <option>CSS</option>
        </datalist>
    </label>
    <label for="alter">Alter:
        <input type="number" id="alter" name="alter"
            min="0" step="2">
    </label><br><br>
    <label for="tage">Tage:
        <input type="range" id="tage" name="tage"
            min="5" max="15" step="2" value="5">
    </label><br>

    <fieldset id="sturi">
        <legend>Studienrichtung: </legend>
        <label for="pi">PI
            <input type="radio" name="sturi" id="pi" value="1">
        </label>
        <label for="wi">WI
            <input type="radio" name="sturi" id="wi" value="2">
        </label>
    </fieldset>

    <label for="sonder">Sonderheiten:
            <fieldset id="sonder" >
                <label for="polster">Polsterstuhl
                    <input type="checkbox" name="sonder"
                        id="polster" value="1">
                </label>
                <label for="steckdose">Steckdose
                    <input type="checkbox" name="sonder"
                        id="steckdose" value="2">
                </label>
            </fieldset>
    <br>
    <label for="farbe">Hintergrund-Farbe:
        <input type="color" id="farbe" name="hintergrund"
            value="#0066FF">
    </label>
    <br><br>

    <label for="zahlung">Zahlungsbeleg:
        <input type="file" id="zahlung" name="zahlung"
            multiple accept="image/*">
    </label>
    <BR>
    <label for="imaDat">Datum der Imatrikulation:
        <input type="date" id="imaDat" name="imaDat"
                min="1999-09-01" max="2050-12-31">
    </label>
    <br><br>
    <label for="geschl">Geschlecht:
        <select name="geschl" id="geschl" size="2"
                multiple>
            <option value="1">weiblich</option>
            <option value="2">männlich</option>
            <option value="3">divers</option>
        </select>
    </label>
    <br><br>

    <label for="anmerkungen">Anmerkungen: <br>
        <textarea cols="80" rows="20" name="anmerkungen" id="anmerkungen">Beispiel
        </textarea>
    </label>

    <br><br>
    <input type="submit" value="Senden">
    <input type="reset" value="Löschen">
</form>
```

## Universalattribute

- id
- class
- accesskey -> Taste zum Anspringen des Elementes
- contenteditable -> Inhalt kann verändert werden
- hidden -> Element ausgeblendet
- draggable -> kann das Element gezogen werden?
- lang
- spellcheck -> browserinterne Rechtschreibprüfung aktivieren
- style (böse)
- tabindex -> Tabulatorreihenfolge
- title -> Elementbeschreibung

# CSS

## Farben

- RGB: dezimal (dezimal `rgb(255,0,128)` oder prozentual `rgb(100%,0%,50%)`
- hexadezimal (`#ff0080`)
- Transparenz mit 2 Stellen mehr bei hexa & `rgba` (vierter Wert zwischen 0 und 1)

## Einheiten

- physische Einheiten: Zoll (in), Zentimeter (cm), Pixel (px)
- relative Einheiten: em (Schriftgröße), ex (Größe von x), vw (Viewportbreite), vh (Viewporthöhe), vmin & vmax (kleinerer/größerer Wert), %, fr (Anteile)
- Winkel: Grad (deg), Radiant (rad)
- Zeit: Sekunden (s), Millisekunden (ms)

## Selectoren

- Typselektor -> HTML-Element
- Universalselektor -> *
- Klassenselektor -> beginnt mit Punkt
- ID-Selektor -> beginnt mit Raute

### Attributselektoren

- `[Attributname]`
- `[name=wert]`
- Zeichenkette enthält Wert, durch Leerzeichen getrennt [name~=wert]
- Attributwert beginnt mit angegebener Zeichenkette, vom Rest mit Bindestrich getrennt [name|=wert]
- Teilübereinstimmung:
  - beginnt mit Zeichenkette -> [name^=wert]
  - endet mit Zeichenkette -> [name$=wert]
  - enthält Zeichenkette -> [name*=wert]

### Pseudoklassen

- auf Eigenschaften der HTML-Elemente bezogen
- :empty, :first-child, :last-child, :nth-child()
- :link, :visited, :hover, :active, :focus
- :disabled, :enabled, :checked
- :valid, :invalid, :in-range, :out-of-range

### Pseudoelemente

- beginnen mit ::
- ::first-line, ::first-letter
- ::before, ::after
- ::backdrop
- ::selection, ::placeholder

### Verbundsselektoren

- p.classname
- Kombinatoren:
  - Kindkombinator: Element > Kind z.B. p > em -> eine Ebene drunter
  - Nachfahrenkombinator: Element Kind z.B. p em ->
  - Nachbarkombinator: Element + Kind z.B. h1 + p -> Auf gleicher Ebene, was direkt daneben steht
  - Geschwisterkombinator: alle Elemente, die auf gl Ebene folgen z.B. h1 ~ p -> alle, die auf der gleichen Ebene liegen

## Display Eigenschaft

- `none` -> Element wird nicht dargestellt und es wird kein Platz reserviert

### Inline Box

- `display: inline`
- Breite der Box durch Inhalt bestimmt

### Block Box

- `display: block`
- Anordnung untereinander
- gesamte Breite des Elternelements
- für viele Textelemente Standard

### Flex Box

- display: flex
- flex-direction row/row-reverse/column/column-reverse
- horizontalte oder vertikale Ausrichtung

### Grid

- display: grid
- grid-template-columns: legt Spalten & deren Aufteilung fest
- grid-template-areas: Bestimmung Zelle zu welchem Bereich gehört
- grid-area: Bereich festlegen, in dem ein Element angezeigt wird
- automatische Erzeugung
- repeat(auto-fill, minmax(wert,wert))
- Zuweisung der Zeilen/Spalten
  - grid-row: start/end
  - grid-column: start/end

#### Grid Beispiel

```css
body {
    font-family: Calibri, Geneva, Tahoma, sans-serif;
    display: grid;
    grid-template-columns: 1fr 2fr 2fr 1fr;
    grid-template-rows: 2fr 4fr 4fr 1fr;
    grid-template-areas:    "head head head head"
                            "nav main main aside"
                            "nav main main aside"
                            "foot foot foot foot";
}

header {
    grid-area: head;
}
```

## Media Querries

- Medienabfragen
- Darstellung eines Dokumentes für verschiedene Ausgabemedien festlegen
- mit ```css @media (max-width: 500px){HTML-Element CSS Code einfügen mit Änderungen}```

## Ein paar Attribute...

- z-index -> Ebenensystem
- Listen Zeichen weg: text-decoration
- justify-content (Ausrichtung) center/space-between/space-evenly/space-around/end/...
- font-family
- transition: Attirbutname Dauer Art(linear, ease..)
- border: 1px solid/dotted/dashed black
- border-radius: 0 5px 2px 2px
- text-align
- order

# JavaScript

- JavaScript-Engine
  - chrome: V8
  - firefox: SpiderMonkey
- Node -> Nutzung von JS ohne Browser
- z.B. To Do Liste, Button zum Einfügen eines Elementes
- Form html Tag mit "onsubmit=addTodo()"

## Datentypen

- String
- Number
- Boolean
- Symbol
- undefined
- BigInt

### komplexe Datentypen

- Array
- Object
- function

## Operatoren

- klassische C-Operatoren
- ** ist für das Potenzieren
- == -> formatiert ggf. Datentypen um Gleichheit zu erreichen 23 == '23' -> true (!=)
- 23 === '23' -> false (!==)

## DOM - Document Object Model

```javascript
document.getElementById();
document.getElementByName();
document.getElementByTagName(); //z.B. <p>
document.querySelector(); //gibt erstes Element, das dem angegebenen CSS-Selektor entspricht
document.querySelectorAll(); //gibt alle Elemente, die dem angegebenen CSS-Selektor entsprechen
```

## Function Syntax

```javascript
// Klasse eines Elementes togglen (selector, class)
function toggleClass(selector, _class){
  // Element aus DOM auswählen
  const el = document.querySelector(selector);
  // Abbruch, wenn kein passendes Element gefunden
  if(!el) return;
  // Besitzt das Element die Klasse?
  if(el.classList.contains(_class)){
    // ja -> Klasse entfernen
    el.classList.remove(_class);
  }else{
    // nein ->Klasse hinzufügen
    el.classList.add(_class);
  }
}
```

## Unterschied JavaScript & ECMA-Script

- ECMA-Script -> Standard
- JavaScript (& andere Scriptsprachen) -> setzen diesen Standard um

## Variablen

```javascript
let variable; //undefined
variable = 2; //number
variable = 'string';
use strict; //strenger Modus
const variable = 45;
const Pi = 3.1415;
```

### Klausur

- allg. Fragen zu Technologien im Web
- keine Geschichte
- HTML spezifische Fragen
  - Stück Quellcode erläutern/ergänzen
- Bücher & Aufzeichnungen dürfen verwendet werden
