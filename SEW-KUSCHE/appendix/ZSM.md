# Zusammenfassung: Softwareentwicklungswerkzeuge

## Dokumentation

- Unterscheidung zwischen interner Doku (Entwickler-/Tester-Doku) und externer Doku (Endnutzer)
- in agilen Teams interne Doku durch Entwicklern geschrieben
- interne Dokumentation sollte direkt mit Quellcode festgehalten werden
  - dokumentiert gleichzeitig Code
  - erlaubt einfachere Änderung der Dokumentation bei Code-Änderung
  - einfache direkte Einbindung in Versionsverwaltung (entgegen Office)
  - Unterstützung durch moderne IDE-Anbindung

### Doku-Grundsätze

- Code **muss** dokumentiert werden
- Kommentare werden bei Code-Änderungen mit angepasst (externe files werden meist vergessen)
- Doku ist Bestandteil der Software und wird mit dieser versioniert
- bei Open-Source-Projekten sollte die Doku plattformunabhängig sein (ohne spezielle Software lesbar)
- Formate: LaTeX, TeXinfo, Docbook, AsciiDoc, Markdown

### Dokumentationsgeneratoren

- Zweck: Erzeugung kommentierter Klassenreferenzen
- Beispiele: `doxygen`, `javadoc`, `robodoc`, ...
- Fähigkeiten:
  - Extraktion der Doku aus dem Code und speziellen Kommentaren im Source
  - Spezielle Formatierung von Funktionsparametern- und Returnwert-Doku
  - Automatische Erzeugung von Listen und Inhaltsverzeichnissen, Abhängigkeitslisten, ...
  - Erzeugen HTML, LaTeX (PDF), RTF, ...

### Andere Doku-Tools

- **Pretty Printer:** generiert HTML aus Source (Syntaxhighlighting: markierte Keywords usw.) $\rightarrow$ bessere Darstellung auf Webseiten
- **Source Formatter:** Umformatieren des Source (einheitliche Einrückung, Zwischenräume, ...)
  - zur Durchsetzung eines firmenweit einheitlichen Stils
  - lesbarmachen fremder und alter Sourcen
