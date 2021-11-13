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
<form action=submit.html id=form1>
    <label for="name">Name:
        <input id=name type=text name=name required>
    </label>
    ...
```

- ID und Name bestenfalls identisch halten
- <fieldset> -> Formularelemente gruppieren
- <button> -> clientseitige Aktion, submit, reset

### Input

- type: text, email, tel, password, url, search, number, range, radio, checkbox, hidden, file, color, date, button
- weitere Attribute: maxlength, minlength, required, pattern, value, placeholder

### Select

- Ausswahlliste in Formularen
- Elemente innerhalb des Body mit <option>
- verschachtelte Auswahlliste <optgroup>
- Attribute: name, size, multiple
- Attribut für <option>: selected

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

- RGB (0..255)
- hexadezimal
- dezimal rgb(0,128,0)
- prozentual: rgb(60%, 20%, 40%)
- Transparenz mit 2 Stellen mehr bei heza & rgba vierter Wert zwischen 0 und 1

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

- [Attributname]
- [name=wert]
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

- *.classname
- Kombinatoren:
    - Kindkombinator: Element > Kind z.B. p > em -> eine Ebene drunter
    - Nachfahrenkombinator: Element Kind z.B. p em -> 
    - Nachbarkombinator: Element + Kind z.B. h1 + p -> Auf gleicher Ebene, was direkt daneben steht
    - Geschwisterkombinator: alle Elemente, die auf gl Ebene folgen z.B. h1 ~ p -> alle, die auf der gleichen Ebene liegen

## Display Eigenschaft 

- none -> Element ist nicht vorhanden

### Inline Box

- display: inline
- Breite der Box durch Inhalt bestimmt

### Block Box

- display: block
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

## Media Querries

- Medienabfragen
- Darstellung eines Dokumentes für verschiedene Ausgabemedien festlegen
- mit ```css @media (max-width: 500px){HTML-Element CSS Code einfügen mit Änderungen}```

## Ein paar Befehle..

- z-index -> Ebenensystem
- Listen Zeichen weg: text-decoration
- justify-content (Ausrichtung) center/space-between/space-evenly/space-around/end/...
- font-family
- transition: Attirbutname Dauer Art(linear, ease..)
- ubung3/style.css kürzen + ausdrucken für grid
- border: 1px solid/dotted/dashed black
- border-radius: 0 5px 2px 2px
- text-align

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
- null
    
## Operatoren
    
- klassische C-Operatoren
- ** ist für das potenzieren
- == -> formatiert ggf. Datentypen um Gleichheit zu erreichen 23 == '23' -> true (!=)
- 23 === '23' -> false (!==)

## DOM - Document Object Model
    
```javascript
    getElementById();
    getElementByName();
    getElementByTagName(); //z.B. <p>
    querySelector(); //gibt erstes Element, das dem angegebenen CSS-Selektor entspricht
    querySelectorAll(); //gibt alle Elemente, die dem angegebenen CSS-Selektor entsprechen
```
    
## Function Syntax

```javascript
    function addTodo(){
        todolist.innerHTML += `... $(todofield.value) `; //HTML-Element ID (hier ul) erhält Fktionsaufruf (bei Btn Aufruf) jedes Mal neu HTML-Code zwischen ``
    //todofield.value Wert der in dem HTML Element mit HTML ID (hier von Input Feld) todofield vorhanden ist
    todofield.value ="Hallo" //im Inputfield wird nach Btnklick "Hallo" eingefügt}
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
    
#### Klausur

- allg. Fragen zu Technologien im Web
- keine Geschichte
- HTML spezifische Fragen
    - Stück Quellcode erläutern/ergänzen
- Bücher & Aufzeichnungen dürfen verwendet werden
