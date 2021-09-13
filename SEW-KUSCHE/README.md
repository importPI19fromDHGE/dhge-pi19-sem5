<!----------
title: "Software-Entwicklungswerkzeuge"
date: "Semester 5"
keywords: [Software-Entwicklungswerkzeuge, SEW, DHGE, Semester 5]
---------->

Software-Entwicklungswerkzeuge
==============================

<!-- md2apkg ignore-card -->

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Inhaltsverzeichnis**

- [Platzhalter](#platzhalter)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Dokumentation

- Unterscheidung zwischen interner Doku (Entwickler-/Tester-Doku) und externer Doku (Endnutzer)
- interne Doku ist vom jeweiligen Entwickler zu erstellen
- interne Doku sollte so viel wie möglich direkt aus dem Source kommen (möglichst keine separaten files)

**Grundsätze**

- Code muss in jedem Fall dokumentiert werden
- Kommentare werden bei Code-Änderungen mit angepasst (externe files werden meist vergessen)
- Office ist kein sinnvolles Werkzeug zur Erstellung interner Doku!
- Doku ist Bestandteil der Software und wird mit dieser versioniert
- Programmierer wollen Doku in ihrem Editor erstellen
- bei Open-Source-Projekten sollte die Doku plattformunabhängig sein (ohne spezielle Software lesbar)
- Formate: LaTeX, TeXinfo, Docbook, AsciiDoc

## Dokumentationsgeneratoren

- Zweck: Erzeugung kommentierter Klassenreferenzen
- Beispiele: Doxygen, Javadoc, Robodoc, ...
- Fähigkeiten:
  - Extraktion von Doku aus dem Code und speziellen Kommentaren im Source
  - Spezielle Formatierung von Funktionsparametern- und Returnwert-Doku
  - Automatische Erzeugung von Listen und Inhaltsverzeichnissen, Abhängigkeitslisten, ...
  - Erzeugen HTML, LaTeX (PDF), RTF, ...

## Andere Tools

- **Pretty Printer:** generiert HTML aus Source (Syntaxhighlighting: markierte Keywords usw.)
  - bessere Darstellung auf Webseiten
  - z.B.: `a2ps`
- **Source Formatter:** Umformatieren des Source (einheitliche Einrückung, Zwischenräume, ...)
  - zur Durchsetzung eines firmenweit einheitlichen Stils
  - lesbarmachen fremder und alter Sourcen
  - z.B.: `indent`, `astyle`, `uncrustify`