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

- [Dokumentation](#dokumentation)
  - [Dokumentationsgeneratoren](#dokumentationsgeneratoren)
  - [Andere Tools](#andere-tools)
- [Versions-Verwaltungs-Systeme](#versions-verwaltungs-systeme)
  - [Zweck von Versions-Verwaltungs-Systemen](#zweck-von-versions-verwaltungs-systemen)
  - [Aufgaben von Versions-Verwaltungs-Systemen](#aufgaben-von-versions-verwaltungs-systemen)
  - [Andere Tools für Patches, Versionshandling usw](#andere-tools-f%C3%BCr-patches-versionshandling-usw)
- [Make](#make)
  - [Makefile](#makefile)
  - [Autotools](#autotools)
    - [Verwendung](#verwendung)
  - [Doxygen](#doxygen)
- [Compiler](#compiler)
  - [Funktionsumfang](#funktionsumfang)
  - [Tools im Compiler-Umfeld](#tools-im-compiler-umfeld)
    - [Tools für Objects, Libraries, Executables](#tools-f%C3%BCr-objects-libraries-executables)
- [Fehlersuche und Analyse des Programm-Verhaltens](#fehlersuche-und-analyse-des-programm-verhaltens)
  - [Debugger](#debugger)
  - [ltrace und strace](#ltrace-und-strace)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Dokumentation

- Unterscheidung zwischen interner Doku (Entwickler-/Tester-Doku) und externer Doku (Endnutzer)
- in agilen Teams wird die interne Doku von den Entwicklern geschrieben; in schwergewichtigen von einer eigenen Abteilung
- interne Dokumentation sollte direkt in dem Quellcode festgehalten werden
  - dokumentiert gleichzeitig Code
  - erlaubt einfachere Änderung der Dokumentation bei Code-Änderung
  - einfach und direkt in Versionsverwaltung eingebunden (entgegen Office-Formaten)
  - Unterstützung durch moderne IDE-Anbindung
  - einfaches Suchen-und-Ersetzen

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

# Versions-Verwaltungs-Systeme

## Zweck von Versions-Verwaltungs-Systemen

- Verwaltung / Archivierung aller Dateien eines Software-Produkts in allen Ständen
- Buchführung über jede einzelne Änderung jeder einzelnen Datei
- \rightarrow\rightarrow **Reproduzierbarkeit** und **Nachvollziehbarkeit**

## Aufgaben von Versions-Verwaltungs-Systemen

- Versionsgeschichte: Wer (Autor) hat wann (Datum) was (Änderung) geändert? Entweder eines einzelnen Files / Verzeichnisses oder des gesamten Projekts!
- konsistente Versions-Nummerierung x.y.z (heute nicht mehr so, z.B. in `git`: Hashes \rightarrow\rightarrow Blockchain)
- Labeling / Tagging von Ständen: z.B. "Weihnachts-Beta-Release"
- Änderungen begründen \rightarrow\rightarrow Querverweis in den Bugtracker / Ticket-System!
- Rekonstruktion alter Stände (nach Datum oder Versionsnummer)
- Anzeige aller Änderungen zwischen zwei Ständen (grafisch!)
- Verwaltung von Branches:
  - `Head`, `Main` oder `Trunk` (aktueller Hauptentwicklungs-Branch)
  - Release- und Wartungs-Branches (nur Fixes, keine Neuentwicklungen)
  - Plattform- oder Kundenbranches (Sonderversion anderer Branches)
  - Feature Development Branches (experimentelle Entwicklungen)
  - Im schlimmsten Fall: Dead Head Branch (aufgegebener Head, Weiterentwicklung in anderem, älteren Stand)
  - Anzeige der Versionen im Idealfall als Graph oder Baum!
  - Automatisches Mergen von einzelnen Änderungen aus dem `Head`-Branch oder einem Wartungs-Branch in andere Branches (bei Wartungs-Branches auch aufwärts: Mergen eines Fixes aus dem Wartungsbranch nach `Head`).
  - Vor allem bei Feature Branches: Zurück-Mergen aller Entwicklungen des Feature-Branches nach `Head` oder Resynchronisation mit `Head` in beide Richtungen (Übernahme aller Neuerungen von `Head` in den Feature-Branch).
- Sperrverwaltung:
  - Welche Files werden aktuell gerade geändert (sind ausgecheckt), von wem?
  - Konkurrierende Veränderungen verhindern oder mergen!
  - nicht von allen VCS genutzt
  - beim Checkout einer Datei wird die Bearbeitung für Andere gesperrt
  - Vorteil: keine Merge Konflikte
  - Nachteil: für große, verteilte Entwicklergruppen nicht praktisch
- Automatisches Einfügen von Versionsverwaltungs-Tags (Datum, Version, Autor, ...) in Source-Kommentare
- Automatische Changelog-Erstellung
- Optimierte Speicherung: Nur die Deltas jeder Änderung, nicht jedesmal die komplette Datei, und zwar rückwärts (aktuelle Version im Volltext)!
- **Beispiele:**
  - Historisch: SCCS (“Source Code Control System”, AT & T System V Unix), RCS (“Revision Control System”, andere Unix-Dialekte) (nur lokal)
  - Lange Zeit führend: CVS (“Concurrent Version System”), Subversion (beide Open Source, Remote- und Multi-User-Fähigkeit)
  - Kommerziell: Perforce, IBM/Rational ClearCase, MS Visual SourceSafe (alt) / Team Foundation Server (neu), BitKeeper (verteilt)
  - Aktuell im Open-Source-Bereich: GIT (verteilt, ursprünglich für den Linux-Kernel entwickelt, heute für die meisten Projekte eingesetzt)
  - Andere: Mercurial, Monotone (verteilt)
  - Einige Webdienste (z.B. GitHub, Sourceforge oder berliOS) bieten über das Internet eine Versionsverwaltung für freie (und gegen Entgelt für kommerzielle) Projekte.
- **Terminologie:**
  - Repository: Ablage aller Files und Verwaltungsdaten
  - Checkout: Herauskopieren einer Datei zwecks Änderung, ev. mit Sperre
  - Checkin / Commit: Speichern einer geänderten Datei, Anlegen einer neuen Version
  - Merge: Übernahme von Änderungen aus einem Branch in einen anderen / aus einem verteilten Repository in ein anderes
    - Im Idealfall (nicht kollidierende Änderungen) vollautomatisch, sonst mit händischer Unterstützung (grafisch)
    - Sonderfall "Three Way Merge": Nicht zwei Files miteinander abgleichen, sondern die Änderungen zwischen zwei Files in einen dritten File einarbeiten.
- **Wichtige Features:**
  - Verwaltung mehrerer Projekte
  - Datenbank (Vorteil oder Nachteil???) (rein text-basiert ist besser)
  - Netzwerk-Zugriff, Client-Server-Architektur
  - Commandline- bzw. Batch-Zugriff (für automatische Checkouts für die Builds) sowie Zugriff mit GUI (Versionsbaum!)
  - Client-Plugins für IDEs
  - Web-Interface
  - Remote Checkout / Checkin / Clone (über HTTPS oder anderes "Firewall-gängiges" und sicheres Protokoll!)
  - Rechte-Verwaltung (wer darf was ändern?)
  - Verwaltung auch von Binär-Dateien
  - Hooks für eigene Programme / Skripts bei Checkin und Checkout
    - (z.B. automatische Qualitätssicherung, Verständigung des Projektleiters, ...)
  - Export- / Import-Fähigkeiten der Versionsgeschichte
  - "Blame Tool": Anzeige von Fileinhalt mit Version, Datum, Autor neben jeder Zeile
  - **Verteilte Versionsverwaltung:**
    - Kein zentrales Repository mehr, Dateien und Verwaltungsinformation (Versionsgeschichte) auf mehrere Standorte verteilt
    - Nicht jeder Standort benötigt das komplette Repository
    - Lokale Checkins und Checkouts ohne Server-Verbindung möglich
      - \rightarrow\rightarrow Sperren-freies Arbeiten
      - \rightarrow\rightarrow nachträglicher Abgleich / Merge mit anderen Standorten
- **Was wird eingecheckt?**
  - Alle Sourcen (incl. Makefiles, Icons, ...)
  - Die Entwicklungs-Tools (Compiler, ...)
  - Alle Fremd-Libraries usw.
  - Alle Test-Sourcen und -Scripts, alle Testfälle / Testinputs
  - Die Dokumentation + Doku-Tools

## Andere Tools für Patches, Versionshandling usw

- **Diff & Merge:**
  - Vergleicht 2 Dateien / Verzeichnisse
  - Liefert zeilenweise Unterschiede in verschiedenen Formaten
  - Gleicht die Unterschiede wenn möglich automatisch ab
  - Sowohl für die Commandline als auch mit GUI
- **Three Way Merge:**
  - Sonderform, spielt die Unterschiede zweier Dateien / Verzeichnisse in einer dritten Datei / einem dritten Verzeichnis ein
- **Kriterien grafischer Tools:**
  - Zeichenweise grafische Darstellung der Unterschiede in den einzelnen Zeilen
  - Geh zum nächsten / vorigen Unterschied
  - Händisches Einfügen oder Entfernen von Unterschieden per Tastatur und Maus, automatisches Mergen aller konfliktfreien Unterschiede
  - Händische Editierbarkeit der Files
  - Händisches Alignment der Differenzen in der Darstellung
  - Mehrere Vergleiche (ganzer Verzeichnisbaum) gleichzeitig
  - Ignorieren von Zwischenräumen / Leerzeilen / unterschiedlichen Zeilenenden / Groß- und Kleinschreibung
- **patch:**
  - Kleines Tool, um Änderungen in Source-Code-Verzeichnissen einzuspielen. Im wesentlichen die Merge-Seite eines 3-Way-Merge:
  - Bekommt diff-Outputs (d.h. geänderte Zeilen) als Input und spielt die Änderungen in einem lokalen Verzeichnis ein
  - Erkennt geringfügig verschobene Änderungen automatisch
  - Legt nicht einspielbare Änderungen zum händischen Nachziehen ab

# Make

`make` automatisiert das Compilieren (großer) Projekte:

- Es erzeugt intern einen Abhängigkeitsgraph der gewünschten Output-Files von den dazu notwendigen Input-Files
- Es prüft, welche der benötigten Files überhaupt noch fehlen, und vergleicht das File-Datum aller vorhandenen direkt voneinander abhängigen Files (potentielles Problem bei Netz-Laufwerken usw. mit ungenauen Uhren!)
- Es baut genau das neu, was notwendig ist / geändert wurde (und nicht mehr!)
- Es kennt Abhängigkeiten (welcher File braucht zum Bauen welche Input-Files?) \rightarrow\rightarrow Es kann voneinander unabhängige Files parallel compilieren! (\rightarrow\rightarrow schneller!)
- Es kann sich selbst rekursiv aufrufen \rightarrow\rightarrow Es kann Unterverzeichnisse, Teilprojekte, ... erzeugen
- `make` arbeitet nur nach File-Datum, aber greift nicht auf die File-Inhalte zu \rightarrow\rightarrow Es ist nicht auf C/C++ beschränkt, sondern kann für beliebige Aufgaben verwendet werden, bei denen ein Programm einen Outputfile X aus Inputfiles Y1, ... erzeugt. \rightarrow\rightarrow Es wird nicht nur zum Compilieren verwendet, sondern auch zum Installieren, Aufräumen, Testen, Doku erstellen, .tar-Archiv erstellen, ...
- Gesteuert wird make vom “Makefile”. Dieser wird pro Projekt (bei größeren Projekten eventuell pro Verzeichnis) erstellt
- man kann parallele Rechenarbeit daran erkennen, dass bei einer Messung mit ``time`` die Userspace-Zeit die Realzeit übertrifft

## Makefile

- jede Befehlszeile muss mit einem ECHTEN Tab beginnen
- erste Zeile `ziel: prereqs`
- `clean` löscht alle Kompilate aber keine Konfigurationen, `dist-clean` löscht Konfigurationen
- Compiler, Linker etc. sollten alle in Variablen definiert sein, einfache Anpassung
- ein Makefile kann auch automatisch generiert werden (von der IDE, einem Dependency-Generator oder cmake etc.)
- Alternativen: jam (C/C++), ant (Java), Maven (Java), Gradle (Java), IDE-integrierte build-tools
- das ``all``-Ziel sollte als erstes in der Makefile stehen, da der Aufruf ohne Ziel das erste baut
- Shell-Erweiterungen werden unterstützt, z.B.: `` `sdl2-config --libs` ``

Beispieldatei für Übung 2:

```make
all: main

main: main.cpp sdlinterf.o circ.cpp circ.h color.h graobj.cpp graobj.h rect.cpp rect.h
  g++ -o main main.cpp sdlinterf.o circ.cpp circ.h color.h graobj.cpp graobj.h rect.cpp rect.h `sdl2-config --libs`
sdlinterf.o: sdlinterf.c sdlinterf.h
  gcc -c sdlinterf.c sdlinterf.h
clean:
  rm -f *.o *.gch main
```

> Oben genanntes Beispiel ist zwar kürzer als die Musterlösung, hat aber die Konsequenz, dass man bei einer Dateiänderung alles neu kompilieren muss und keine Parallelisierung möglich ist.

## Autotools

- sollen helfen, portable Software und portable Makefiles zu erstellen
- Entwicklung durch GNU
- Nutzer soll den geladenen Source-Code konfigurieren können
- Entwickler baut Makefile-Gerüste und ein Konfigurationsfile (plattformabhängige Konfigurationen)
- ein Tool findet nicht-portable Konstrukte im C/C++ Code
- Autotools erstellen ein `configure`-Script
- Nutzer startet dann `configure`
- `configure` führt automatische Tests auf dem lokalen System aus, um Probleme und Inkompatiblitäten zu finden
- danach wird ein Makefile generiert und ein C-Headerfile
- dieser C-Headerfile steuert plattformabhängige Code-Strukturen mit Makros
- `libtool` ist ein Tool zum Erzeugen und Linken von Shared Libraries, es soll es auf verschiedenen Plattformen vereinheitlichen
- `gettext` ist ein Tool zum Internationalisieren aller Texte in einem Programm

### Verwendung

- Indiz: Vorhandensein von ausführbarer ``configure``, ``*.in``, ``*.ac``
- ``configure``-Datei muss ausgeführt werden, um auf das System angepasste Makefiles etc. zu generieren
  - ``-h`` / ``--help`` zeigt alle Optionen und Variablen an
  - kompiliert Testprogramme und prüft auf Abhängigkeiten
  - ist das erfolgreich, werden systemspezifische Dateien wie ``config.h`` und ``Makefile`` generiert

## Doxygen

- Doxygen interessiert sich nicht für alle Kommentare
- Kommentare sollten `///` oder `/**` sein
- Parameter werden i.d.R. mit `//<` dahinter kommentiert, bspw.:

```cpp
/// this function does something
int someFunction(int par1, ///< parameter 1
                 int par2) ///< parameter 2
```

# Compiler

Praxistipps

- Es spart Mühe, Code für alle Plattformen vom selben Compiler bauen zu lassen
- Keine Kompilate unterschiedliche Compiler zusammenlinken
- Compiler finden mehr Fehler bei aktivierter Optimierung
- Precompiled Headers vermeiden
- Cross-Compiler bauen Code für eine andere Zielplattform

## Funktionsumfang

Vernünftige Compiler sollten folgende Features besitzen:

- Präprozessor:
  - Ausgabe der Abhängigkeiten
  - mit Linker: Umdefinieren von Header-, Lib-Verzeichnissen und System-Startup-Codes<!--?-->
  - Ausgabe der vom Präprozessor verarbeiteten Quellen mit Beibehaltung von Formatierung und Kommentaren und Verweis auf Quell-Zeile (für Probleme in Makros und Headern)
  - Liste definierter Makros
- wählbares temporäres Verzeichnis
- Warnings für "dubiose Konstrukte" (mögliche Programmierfehler)
- verschiedene Zeichensätze
- Standardkonformität des Codes prüfen lassen
- signed und unsigned ``char``s
- Ausgabe der Assembler-Sourcen
- Debug-Output für optimierten Code
- Separierung von Executable und Debug-Symbolen
- Erzeugung zusätzlicher Laufzeitprüfungen
- "Strict inlining mode" für Inline-Assembler
- Reduzierter C++-Runtime (keine Exceptions, ...)
- Genaue Festlegung von Zielhardware (Befehlssatz und Optimierung für Eigenheiten von Rechenwerken)
- Profiling und Coverage-Analyse
- Feedback-Optimierung ("Profile Guided Optimization"), damit für die meistgenutzten Programm-Abläufe und -Strukturen optimiert wird
- Optimierung beim Linken ("Link-time Optimization") - Optimierung über Filegrenzen hinweg

## Tools im Compiler-Umfeld

- Compiler-Compiler: Erzeugen Code für Syntaxanalyse
- Compiler-Caches, z.B.: ``ccache``
- verteiltes Kompilieren, z.B. mit ``distcc``: große Projekte können über mehrere Computer verteilt gebaut werden

### Tools für Objects, Libraries, Executables

- ``strip``: löscht Debug-Informationen aus einer Binary
- ``ld``: Linker
- ``nm``: Symbole anzeigen
  - ``T``: Text
  - ``U``: Undefines - müssen gelinkt werden
  - ``D``: Datensegment
  - ``B``: null-initialisierter Datenbereich
  - ``R``: read-only
  - Parameter ``-C``: Auflösen von Symbolen in die originalen Namen, nützlich bei C++
- ``c++filt``: Auflösung eines bestimmten Namens in einer Binary
- ``ar``: Anzeige und Manipulation von Objekten in einer Library
- ``size``: gibt Größe der Datenbereiche in einer Binary an

# Fehlersuche und Analyse des Programm-Verhaltens

## Debugger

- 3 Betriebsmodi
  - Post mortem Debugging: analysieren einer "Leiche"
  - Anhängen an einen bereits laufenden Prozess: nützlich, wenn Programm erst nach langer Laufzeit Fehler zeigt
  - Starten einer Binary mit Debugger: gängigste Methode in der Entwicklung
- Laden eines Coredumps: ``gdb programm coredump``
  - wenn Programm und Dump nicht zusammenpassen, wird GDB das anmerken
  - wichtigste Befehle:
    - ``where``: zeigt Position des Absturzes auf dem Call-Stack mit Traceback
    - ``up``: geht im Call-Stack eins nach oben (in den Aufrufer des Absturzes) (analog: ``down``)
    - ``print``: gibt Variablen aus, aber nur die im aktuellen Stack Frame

## ltrace und strace

- funktionieren immer, auch ohne Debug-Symbole u.s.w.
- ``ltrace`` untersucht Library-Calls
- ``strace`` untersucht Kernel-Calls
