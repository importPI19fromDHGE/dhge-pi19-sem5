# HTML
## Grundgerüst
```html
<!DOCTYPE html>
<html lang="de">
    <head>
    </head>
    <body>
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

## Listentypen
- sortiert -> ol
- unsoritert -> ul
- Beschreibungsliste -> dl

## Tabellen
```html
- <table>
- Zeile: <tr>
- Zelle: <td>
- Kopfzelle: <th>
- <th> scope-Attribut: Zeilen- oder Spaltenkopf
```
## Formulare
```html
<form action=submit.html id=form1>
    <label for="name">Name:
        <input id=name type=text name=name required>
    </label>
    ...
```
- ID und Name bestenfalls identisch halten
- ```html<fieldset>``` -> Formularelemente gruppieren
- ```html<button>``` -> clientseitige Aktion, submit, reset

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
    - Kindkombinator: Element > Kind z.B. p > em
    - Nachfahrenkombinator: Element Kind z.B. p em
    - Nachbarkombinator: Element + Kind z.B. h1 + p
    - Geschwisterkombinator: alle Elemente, die auf gl Ebene folgen z.B. h1 ~ p

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
- flex-direction
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
