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

#### Doxygen

- Doxygen interessiert sich nicht für alle Kommentare
- Kommentare sollten `///` oder `/**` sein
- Parameter werden i.d.R. mit `//<` dahinter kommentiert, bspw.:

```cpp
/// this function does something
int someFunction(int par1, ///< parameter 1
                 int par2) ///< parameter 2
```

### Andere Doku-Tools

- **Pretty Printer:** generiert HTML aus Source (Syntaxhighlighting: markierte Keywords usw.) $\rightarrow$ bessere Darstellung auf Webseiten
- **Source Formatter:** Umformatieren des Source (einheitliche Einrückung, Zwischenräume, ...)
  - zur Durchsetzung eines firmenweit einheitlichen Stils
  - lesbarmachen fremder und alter Sourcen

## Versionsverwaltung (think `git`)

- Verwaltung und Archivierung aller Dateien eines Software-Produkts in allen Ständen
- Buchführung über jede einzelne Änderung in jeder einzelnen Datei
  - Optimierte Speicherung: Nur die Deltas jeder Änderung, nicht jedesmal die komplette Datei, und zwar rückwärts (aktuelle Version im Volltext)

> **Reproduzierbarkeit und Nachverfolgbarkeit**

### Aufgaben einer Versionsverwaltung

- Versionsgeschichte: Wer (Auto) hat wann (Datum) was (Änderung) geändert?
- Konsistente Versionsnummerierung (x.y.z)
- Labeling/Tagging von Ständen
- Kommentar der Änderung $\rightarrow$ Verweise in den Bugtracker
- Rekonstruktion alter Stände
- Anzeigen der Änderungen zwischen mehreren Ständen

#### Branches

- `head`, `main` oder `trunk` (aktueller Hauptentwicklungs-Branch)
  - Release- und Wartungs-Branches (nur Fixes, keine Neuentwicklungen)
  - Plattform- oder Kundenbranches (Sonderversion anderer Branches)
  - Feature Development Branches (experimentelle Entwicklungen)
- Anzeige der verschiedenen Branches im Idealfall als Graph bzw. Baum
- Automatisches Mergen von einzelnen Änderungen aus dem `head`-Branch oder einem Wartungs-Branch in andere Branches
  - Zurück-Mergen aller Entwicklungen (vor allem bei Feature Branches) nach `head` oder Resynchronisation mit `head` in beide Richtungen (Übernahme aller Neuerungen von `head`)

#### Sperrverwaltung

> Welche Files werden aktuell gerade geändert (sind ausgecheckt), von wem?

- Konkurrierende Veränderungen verhindern oder mergen!
- nicht von allen VCS genutzt
- beim Checkout einer Datei wird die Bearbeitung für Andere gesperrt
- Vorteil: keine Merge Konflikte
- Nachteil: für große, verteilte Entwicklergruppen nicht praktisch

### Terminologie einer Versionsverwaltung

- **Repository:** Ablage aller Files und Verwaltungsdaten
- **Checkout:** Herauskopieren einer Datei zwecks Änderung, evtl. mit Sperre
- **Checkin/Commit:** Speichern einer geänderten Datei, Anlegen einer neuen Version
- **Merge:** Übernahme von Änderungen aus einer Branch in einen andere bzw. aus einem verteilten Repository in ein anderes
  - Im Idealfall (nicht kollidierende Änderungen) vollautomatisch, sonst mit händischer Unterstützung
  - *Sonderfall "Three Way Merge": Änderungen zwischen zwei Files in einen drittes File einarbeiten*

### Funktionsumfang einer Versionsverwaltung

- Verwaltung mehrerer Projekte
- Datenbank (Vorteil oder Nachteil???) (rein text-basiert ist besser)
- Netzwerk-Zugriff, Client-Server-Architektur
- Commandline-Zugriff (für automatische Checkouts für die Builds) sowie Zugriff mit GUI (Versionsbaum)
- Client-Plugins für IDEs
- Web-Interface
- Remote Checkout/Checkin/Clone (über `https` oder anderes "firewall-gängiges" und sicheres Protokoll)
- Rechte-Verwaltung (wer darf was ändern?)
- Verwaltung auch von Binär-Dateien
- Hooks für eigene Programme/Skripte bei Checkin und Checkout (z.B. automatische Qualitätssicherung, Verständigung des Projektleiters, ...)
- Export-/Import-Fähigkeiten der Versionsgeschichte
- "Blame Tool": Anzeige von Fileinhalt mit Version, Datum, Autor neben jeder Zeile

#### Verteilte Versionsverwaltung

- kein zentrales Repository mehr $\rightarrow$ Dateien und Verwaltungsinformation (Versionsgeschichte) auf mehrere Standorte verteilt
- nicht jeder Standort benötigt das komplette Repository
  - Lokale Checkins und Checkouts ohne Server-Verbindung möglich
  - $\rightarrow$ Sperren-freies Arbeiten und nachträglicher Abgleich/Merge mit anderen Standorten

#### Andere Tool zur Versionsverwaltung

**`diff` und `merge`**

- Vergleichen zweier Datein/Verzeichnisse
- Ausgabe zeilenweiser Unterschiede in verschiedenen Formaten
- möglichst automatisches Abgleichen von Unterschieden

**`patch`**

- Tool um Änderungen in Source-Code-Verzeichnissen einzuspielen (vgl. 3-Way-Merge)
- `diff`-Output als Input $\rightarrow$ Einspielen der Änderungen in lokalem Verzeichnis
- nicht einspielbare Änderungen werden zum händischen Nachziehen abgelegt

## Make

- `make` automatisiert das Compilieren (großer) Projekte
- erzeugt intern Abhängigkeitsgraphen der gewünschten Output-Files von den dazu notwendigen Input-Files
- prüft, welche der benötigten Files überhaupt noch fehlen und vergleicht das File-Datum aller vorhandenen, direkt voneinander abhängigen Files
  - *`make` arbeitet nur nach File-Datum, aber greift nicht auf die File-Inhalte zu*
  - *$\rightarrow$ nicht auf `C`/`C++` beschränkt, sondern kann für beliebige Aufgaben verwendet werden, bei denen ein Programm einen Outputfile X aus Inputfiles Y1, ... erzeugt*
  - *auch zum Installieren, Aufräumen, Testen, Doku erstellen usw. verwendet*
- baut nur genau das neu, was notwendig ist/geändert wurde
- erkennt Abhängigkeiten der Files $\rightarrow$ kann voneinander Unabhängige parallel compilieren
- kann sich selbst rekursiv aufrufen $\rightarrow$ kann Unterverzeichnisse, Teilprojekte, ... erzeugen
- Konfiguration über `Makefile` $\rightarrow$ eines pro Projekt (bei größeren Projekten eventuell pro Verzeichnis)

### Aufbau eines Makefiles

- **Abhängigkeiten:** `target: prerequisites` bzw. `erzeugter File: dazu notwendige Files`
  - z.B. `main.o: main.c mytypes.h mylib.h`
  - Patterns, Wildcards usw. werden ebenfalls unterstützt
  - Pseudo-Targets, die keinem File entsprechen: `all`, `clean`, `doc`, `test`, ...
- zu jeder Abhängigkeit folgen optional **Befehle** (Compiler-Aufruf, Install-Befehl, ...)
  - mit ECHTEM Tab eingerückt; an Shell zur Ausführung übergeben
  - Output mit `@`-Prefix unterdrücken (z.B. `@g++ -c main.cpp`)
- Eine Abhängigkeit und dazugehörige Befehle werden als **Regel** (Rule) bezeichnet

#### Variablen in Makefiles

- **Variablen**-Definition: z.B. `hfiles=circ.h color.h graobj.h rect.h`
- Verwendung in Befehlen oder Targets: z.B. `main.o: main.cpp $(hfiles)`
- sollten für Gruppen von Files (`.o`/`.h`-Files), Befehle (Compiler, Linker) und Optionen (Compiler-Optionen, Suchpfade für System-Header und Libs) definiert werden $\rightarrow$ einfache Anpassung
- standardisierte Namen haben sich eingebürgert: z.B. `CC`, `CFLAGS`, ...

### Makefile erstellen

- manuell
- mit Hilfe von Dependency-Generatoren
- von der Entwicklungsumgebung
- CLI-Tools zur Generierung

### Autotools

- sollen helfen, **portable Software und portable Makefiles zu erstellen** $\rightarrow$ Nutzer soll den geladenen Source-Code konfigurieren können
- Entwickler baut **Makefile-Gerüste und ein Konfigurationsfile** (plattformabhängige Konfigurationen)
- ein Tool findet nicht-portable Konstrukte im C/C++ Code
- Autotools erstellen ein `configure`-Script
- Nutzer startet das Skript $\rightarrow$ führt automatische Tests auf dem lokalen System aus, um Probleme und Inkompatibilitäten zu finden
- danach wird ein Makefile generiert und ein C-Headerfile $\rightarrow$ steuert plattformabhängige Code-Strukturen mit Makros
- `libtool`: Tool zum Erzeugen und Linken von Shared Libraries, es soll es auf verschiedenen Plattformen vereinheitlichen
- `gettext`: Tool zum Internationalisieren aller Texte in einem Programm

## Compiler

### Funktionsumfang


#### Präprozessor:

- Ausgabe der Abhängigkeiten
- mit Linker: Umdefinieren von Header-, Lib-Verzeichnissen, ...
- Ausgabe der vom Präprozessor verarbeiteten Quellen mit Beibehaltung von Formatierung, Kommentaren und Verweis auf Quell-Zeile (für Probleme in Makros und Headern)
- Liste definierter Makros

#### Debugging

- Warnings für *"dubiose Konstrukte"* (mögliche Programmierfehler)
- Standardkonformität des Codes prüfen lassen
- Debug-Output für optimierten Code
- Separierung von Executable und Debug-Symbolen (Debug Symbole können in seperater Datei gespeichert werden)
- Erzeugung zusätzlicher Laufzeitprüfungen

#### Optimierung

- Reduzierter C++-Runtime (keine Exceptions, ...)
- Genaue Festlegung von Zielhardware (Befehlssatz und Optimierung für Eigenheiten von Rechenwerken)
- Profiling und Coverage-Analyse
- Feedback-Optimierung (*"Profile Guided Optimization"*), damit für die meistgenutzten Programm-Abläufe und -Strukturen optimiert wird
  - typischer Programmablauf wird durchgeführt $\rightarrow$ Profil wird erstellt
  - Programm wird erneut mit diesem Profil gebaut
- Optimierung beim Linken (*"Link-time Optimization"*) $\rightarrow$ Optimierung über Filegrenzen hinweg

#### Sonstiges

- verschiedene Zeichensätze (Unicode, ISO Latin, ...)
- wählbarer `char`-Typ (`signed`/`unsigned`)
- Ausgabe der Assembler-Sourcen
- *"Strict inlining mode"* für Inline-Assembler

### Praxistipps

- Code für alle Plattformen vom selben Compiler bauen lassen
- keine Kompilate unterschiedlicher Compiler zusammenlinken
- Compiler finden mehr Fehler bei aktivierter Optimierung
- Cross-Compiler bauen Code für andere Zielplattformen

### Tools im Compiler-Umfeld

- **Compiler-Compiler:** Erzeugen Code für Syntaxanalyse
- **Compiler-Caches:** z.B. `ccache`
- **verteiltes Kompilieren:** z.B. mit `distcc` $\rightarrow$ große Projekte können über mehrere Computer verteilt gebaut werden

#### Tools für Objects, Libraries, Executables

- `strip`: löscht nicht benötigte Symbole und Debug-Infos aus einer Binary
- `ld`: Linker
- `nm`: Symbole anzeigen
- `c++filt`: Auflösung eines bestimmten Namens in einer Binary
- `ar`: Anzeige und Manipulation von Objekten in einer Library
- `size`: gibt Größe der Code- und Datenbereiche in einer Binary an
