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

- [Klausur](#klausur)
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
  - [Was ist der technische Auslöser eines Coredumps?](#was-ist-der-technische-ausl%C3%B6ser-eines-coredumps)
  - [Mit welchem Programm kann ich mir alle geöffneten Files (im weitestens Sinne) anzeigen lassen?](#mit-welchem-programm-kann-ich-mir-alle-ge%C3%B6ffneten-files-im-weitestens-sinne-anzeigen-lassen)
  - [Was macht der Befehl `df`?](#was-macht-der-befehl-df)
  - [Das `/proc` Verzeichnis](#das-proc-verzeichnis)
  - [Das `/sys` Verzeichnis](#das-sys-verzeichnis)
  - [Core dumps aktivieren](#core-dumps-aktivieren)
  - [Finding your C/C++ Pointer and Array Bugs](#finding-your-cc-pointer-and-array-bugs)
    - [Knowing your enemies](#knowing-your-enemies)
    - [Bug-Symptome](#bug-symptome)
    - [Program checking, debugging, tracing](#program-checking-debugging-tracing)
    - [Compiling your code with seatbelts: Address sanitizer & co.](#compiling-your-code-with-seatbelts-address-sanitizer--co)
    - [Dealing with plain off-the-shelf code: Valgrind and friends](#dealing-with-plain-off-the-shelf-code-valgrind-and-friends)
    - [Similar tools for different purposes](#similar-tools-for-different-purposes)
    - [Statische Analyse](#statische-analyse)
    - [Profiling und Tracing](#profiling-und-tracing)
- [Qualitätssicherung](#qualit%C3%A4tssicherung)
  - [Grundlegendes](#grundlegendes)
  - [Tests vs. Verifikation](#tests-vs-verifikation)
  - [Black Box Test vs. White Box Test](#black-box-test-vs-white-box-test)
  - [Modultests vs. Gesamtsystem-Tests](#modultests-vs-gesamtsystem-tests)
  - [manuelle vs. automatische Tests](#manuelle-vs-automatische-tests)
  - [Test-Checkliste](#test-checkliste)
  - [GUI-Scripting](#gui-scripting)
  - [Unit Tests](#unit-tests)
  - [Famework-Komponenten](#famework-komponenten)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Klausur

- Theorieklausur, ca. 5 bis 6 Seiten mit jeweils 5 bis 10 kurzen Fragen
- kein Code, keine Befehlsdetails
- Bsp.: Anforderungen an Dokumentation, Bestandteile eines Makefiles
- Stichpunkte reichen, straffer Zeitrahmen
- Es gibt wieder Überpunkte<!--:-)-->
- Themenschwerpunkte sind die Übungen, aber auch Tools wie Versionsverwaltung

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
all: main html/index.html latex/refman.pdf

hfiles=circ.h color.h graobj.h rect.h

main.o: main.cpp $(hfiles)
  @g++ -c main.cpp

rect.o: rect.cpp $(hfiles)
  @g++ -c rect.cpp

circ.o: circ.cpp $(hfiles)
  @g++ -c circ.cpp

graobj.o: graobj.cpp $(hfiles)
  @g++ -c graobj.cpp

sdlinterf.o: sdlinterf.c $(hfiles)
  @gcc `sdl2-config --cflags` -c sdlinterf.c

main: circ.o graobj.o main.o rect.o sdlinterf.o
  @echo Compiling $@
  @g++ -o main circ.o graobj.o main.o rect.o sdlinterf.o `sdl2-config --libs`

Doxyfile:
  @doxygen -g

html/index.html: Doxyfile
  @doxygen &> /dev/null

latex/refman.pdf: Doxyfile html/index.html
  @$(MAKE) -C latex &> /dev/null

clean:
  @rm -rf main *.o html latex
```

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

**Praxistipps**

- Es spart Mühe, Code für alle Plattformen vom selben Compiler bauen zu lassen
- Keine Kompilate unterschiedlicher Compiler zusammenlinken
- Compiler finden mehr Fehler bei aktivierter Optimierung
- Precompiled Headers vermeiden
- Cross-Compiler bauen Code für andere Zielplattformen

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
- Separierung von Executable und Debug-Symbolen (Debug Symbole können in seperater Datei gespeichert werden)
- Erzeugung zusätzlicher Laufzeitprüfungen
- "Strict inlining mode" für Inline-Assembler
- Reduzierter C++-Runtime (keine Exceptions, ...)
- Genaue Festlegung von Zielhardware (Befehlssatz und Optimierung für Eigenheiten von Rechenwerken)
- Profiling und Coverage-Analyse
- Feedback-Optimierung ("Profile Guided Optimization"), damit für die meistgenutzten Programm-Abläufe und -Strukturen optimiert wird
  - typischer Programmablauf wird durchgefuehrt $\rightarrow$ Profil wird erstellt
  - Programm wird erneut mit diesem Profil gebaut
- Optimierung beim Linken ("Link-time Optimization") \rightarrow\rightarrow Optimierung über Filegrenzen hinweg
- Bei der Fehlersuche sollte mit Compiler-Optimierungen kompiliert werden, da dadurch mehr Fehler gefunden werden können
- Precompiled Header beschleunigen zwar das Kompilieren großer Projekte, machen aber teilweise noch viel Ärger wegen unausgereifter Implementierungen

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

- drei Betriebsmodi:
  - Post-mortem Debugging: Analysieren einer "Leiche"
  - Anhängen an einen bereits laufenden Prozess: nützlich, wenn Programm erst nach langer Laufzeit Fehler zeigt
  - Starten einer Binary mit Debugger: gängigste Methode in der Entwicklung
- Laden eines Coredumps: ``gdb programm coredump``
  - wenn Programm und Dump nicht zusammenpassen, wird `gdb` das anmerken
  - wichtigste Befehle:
    - ``where``: zeigt Position des Absturzes auf dem Call-Stack mit Traceback
    - ``up``: geht im Call-Stack eins nach oben (in den Aufrufer des Absturzes) (analog: ``down``)
    - ``print``: gibt Variablen aus, aber nur die im aktuellen Stack Frame

## ltrace und strace

- funktionieren immer, auch ohne Debug-Symbole u.s.w.
- ``ltrace`` untersucht Library-Calls
- ``strace`` untersucht Kernel-Calls

## Was ist der technische Auslöser eines Coredumps?

- Betriebssystem löst für bspw. einen Seitenfehler ein Signal aus
- das Programm hat die Möglichkeit auf das Signal zu reagieren
- SIGSEGV $\rightarrow$ Invalid Memory Reference
- SIGBUS $\rightarrow$ Bus error (bad memory access), tritt bei Intel Prozessoren nicht auf
- SIGABRT $\rightarrow$ wird vom Programm (durch ABORT) aufgerufen
- viele weitere Signale, die zu einem core dump führen können, steht auf der man page: `man 7 signal`
  - bei `Term` wird das Programm beendet
  - bei `Core` wird ein core-dump erstellt (default)
  - bei `Cont` wird ein Programm wieder in der Vordergrund geholt
  - bei `Ign` wird das Signal ignoriert
  - bei `Stop` wird das Programm gestoppt

## Mit welchem Programm kann ich mir alle geöffneten Files (im weitestens Sinne) anzeigen lassen?

- `lsof`
- `fd`: was ist der relative Pfad `.` des Programms?

## Was macht der Befehl `df`?

- alle Filesysteme und deren Disk-Usage anzeigen

## Das `/proc` Verzeichnis

- Hier kann man alle Prozesse und Informationen dazu finden
- `xhci` $\rightarrow$ USB-3 Controller

## Das `/sys` Verzeichnis

- Informationen zum System
- Kernel Parameter
- etc.

## Core dumps aktivieren

- `ulimit -S -c unlimited`
- `-S` Größe angeben
- `c` Core dumps

## Finding your C/C++ Pointer and Array Bugs

### Knowing your enemies

- falsche Pointer
  - NULL-Pointer
  - Uninitialisierte Pointer-Variable
    - einfacher Pointer $\rightarrow$ kann vom Compiler entdeckt werden
    - Elemente eines ``struct``s oder Array-Elemente werden **nicht** vom Compiler untersucht
  - Pointer to a local array or struct after the function has returned: "use-after-return"
  - "use-after-return": Pointer auf eine lokale Variable einer Funktions, die bereits ``return``ed ist
- Arrays & Pointer-Arithmetrik
  - Verletzung von Arraygrenzen
    - "off by one": knapp daneben ist auch vorbe
    - keine Laufzeitprüfungen
    - fehlender String-Terminator ``\0``
  - Integer Overflow: Wertebereich ausgeschöpft, flippt ins Negative
  - uninitialisierte Variablen (v.a. Integers)
- Dynamischer Speicher
  - Objektgrenzenverletzung<!--merke ich mir für Galgenraten-->
  - "use-after-free": Zugriff auf eigentlich bereits gelöschte Daten via Pointer
  - doppeltes ``free``
  - ``free`` auf ungültige Daten
  - Mischung von C und C++ Konstrukten zum Reservieren + Löschen von Speicher (z.B. ``malloc`` + ``delete``)<!--heutige Compiler sind da sogar gnädig, aber machts einfach nicht-->
  - (Memory-Leaks)<!--ich könnte schwören, ich hätte hier was reserviert... Wo ist nur der Pointer hin???-->
  - (Speicherfragmentierung)
- *Dreckecken* von C/C++
  - falscher ``printf``-Aufruf (bspw. non-String Argument mit `%s`)
  - Variadische Funktionen (variabel viele Parameter wie bspw. bei ``printf``)
  - 32bit / 64bit casts zwischen Pointer und ``int`` (sehr oft in 32bit Programmen zu sehen, die zu 64bit portiert wurden)
  - Nutzung von anderen Datentypen als Pointer:
    - falsche Form von ``union``
    - ``static_cast``s (z.B.: Pointer auf Oberklasse $\rightarrow$ Pointer auf Unterklasse)

### Bug-Symptome

- sofortiger, Debug-fähiger Absturz: be happy, you had very good luck :^)
- Absturz mit schwerwiegender Speicherkorruption: hier kann selbst der Debugger nicht mehr helfen
- verzögerte Nummer:
  - Stunden später
  - in komplett anderen Programmteilen
- überhaupt kein Absturz, nur falsche Ergebnisse
- unvorhersagbares Verhalten

### Program checking, debugging, tracing

- mit maximum warning level und maximum optimization level kompilieren
- warnings LESEN!<!--haha, LOL-->
- statische Programmanalyse
- ``ltrace`` und ``strace``
  - nur von begrenztem nutzen für Pointerfehler
- Compiler-basierte Lösung
  - viele Prüfungen im Code
  - Daten sicherer im Speicher anlegen
  - ``bgcc``, ``MIRO`` (beide nicht mehr geplegt)
  - heute: Address Sanitizer "Asan" (sehr schnell!)
- Valgrind: Codeprüfung jedes Befehls zur Laufzeit
  - stark vereinfacht: vor und nach jeder x86-Instruktion können Plugins ausgeführt werden; die Binary wird quasi "interpretiert"<!--dont quote that-->
  - Valgrind bietet viele Plugins für verschiedene Szenarien
  - ähnliche Projekte: DrMemory, Purify/Quantify (kommerziell), Micro Focus BoundsChecker

### Compiling your code with seatbelts: Address sanitizer & co.

### Dealing with plain off-the-shelf code: Valgrind and friends

### Similar tools for different purposes

### Statische Analyse

- prüfen Quellcode
- melden heikle Programmkonstrukte, "gefährliche" Library-Calls, sowie beliebte Programmierfehler
- Untersuchen Wertebereiche von Variablen
  - stellen daraus fest, ob Zeilen harmlosen oder gefährlichen Code enthält
- finden wenig, kosten viel; viele Falsch-positive

### Profiling und Tracing

- Untersuchung vom zeitlichen Programmverhalten
- Profiling: Statistiken über Programmablauf
  - welche Funktionen wie oft aufgerufen?
  - wie viel vom Quellcode wurde ausgeführt?
  - in welchen Teilen des Programms wurden wie viel Prozent der Zeit verbracht?
  - welche `if`-Zweige werden nie aufgerufen?
- Zweck von Profiling:
  - Analyse der Laufzeitverteilung: Hotspots, Code-Optimierung (wo lohnt sie sich am meisten?)
  - Vergleichen verschiedener Compiler-Parameter
  - falsche Annahme über den typischen Input oder die Datenmenge verhindern
  - Qualitätssicherung, Code-Coverage
- Instrumentierende Profiler:
  - Einfügen von Mess-Code für jeden "Basic Block" oder jeder Funktion
    - Basic Block: Code-Teil ohne Sprünge oder Verzweigungen
  - liefern exakte Zahlen
  - hoher Overhead $\rightarrow$ verändert Zeitverhalten
- Sampling Profiler:
  - Code bleibt unverändert
  - unterbricht laufendes Programm regelmäßig und extrahiert Debug-Informationen zur Auswertung
  - unabhängiger Timer für Interrupts eigentlich notwendig, aber nicht mehr genutzt
  - Vorteile: geringer Overhead, faire Verteilung davon
  - Nachteile: Mindestlaufzeit für statistische Relevanz notwendig, geringere Genauigkeit, keine garantierte Aussage über ungenutzten Code
  - Anfällig für gesperrte Timer
- Vertreter: **Google Perftools**, Oprofile, Sysprof, gprof
- neben Software gibt es auf x86 auch Hardware-Profiler: "Performance-Counter", bspw. durch das ``perfmon``-Tool
- Tracer suchen exakte Aussagen zu einzelnen Ereignissen
  - warum trat ein Deadlock auf?
  - warum wurde eine Echtzeit-Anforderung nicht eingehalten?
  - loggt bestimmte Ereignisse mit genauem Timestamp
  - schreibt Logs in Puffer, um I/O zu vermeiden
  - Daten können i.d.R. grafisch als Zeitdiagramm dargestellt werden
  - Vertreter: LTTng

# Qualitätssicherung

- Was gehört zur Qualität?
  - Fehlerfreiheit
  - Robustheit: geordnete Reaktion auf Eingabefehler, Systemfehler, Stromausfälle / Abstürze; Sicherheit gegen Angriffe
  - Stabilität: vernünftiges Hochlastverhalten, gutes Langzeitverhalten (Memory Leaks, Alterung von Datenstrukturen), Verhalten bei großen Datenmengen
  - Einhaltung relevanter Standards
  - Integration in andere Software
  - Erfüllung rechtlicher Vorgaben
  - Bedienbarkeit (Optik, Verständlichkeit von Fehlermeldungen, Übersetzungen)
  - Administrierbarkeit (Installation, Updates, Rollbacks, Backups, ...)
  - Dokumentation und Hilfe
  - Effizienz, Performance, Skalierbarkeit
  - Zertifizierung

## Grundlegendes

- Fehler pro LoC bleibt historisch konstant
- $n$ Module mit Korrektheitswahrscheinlichkeit ergibt $p^n$ Gesamt-Korrektheits-Wahrscheinlichkeit
- **je später ein Fehler erkannt wird, umso teurer!** $\rightarrow$ Fehler so früh wie möglich beheben
- Vorstufen in der Entwicklung:
  - Testbares Design mit Modularisierung
  - Programmierhandbuch $\rightarrow$ Festlegen von Richtlinien zu Code-Konstrukten, Kommentaren usw.
  - Qualitäts-Tools
  - Defensive Programmierung $\rightarrow$ viele Eingabeprüfungen
  - Einsetzen von Code-Coverage

## Tests vs. Verifikation

- *"Tests können nur die Anwesenheit von Fehlern beweisen, nie deren Abwesenheit!"*
- für absolute Fehlerfreiheit ist ein mathematischer Beweis notwendig $\rightarrow$ **Verifikation ist der formale Beweis der Programm-Korrektheit**
- Grundsätzliches Vorgehen:
  - gegeben ist:
    - formale Spezifikation des Inputs: welche Bedingungen werden erfüllt
    - formale Spezifikation des Outputs: Bedingungen, Abhängigkeit vom Input
    - formale Spezifikation aller verwendeten Grundfunktionen
  - Beweise für Programmvorgehen vom Anfangszustand Schritt für Schritt, welche Bedingungen für alle Daten in jedem Zustand gelten
  - für jede Schleife muss eine "Schleifeninvariante" gefunden werden: eine Bedingung, die vor und nach **jedem** Schleifendurchlauf gelten muss
- in der Praxis wird Verifikation kaum verwendet

## Black Box Test vs. White Box Test

- **Black Box Test:** Code nicht bekannt
  - testet stets Gesamtsystem
  - verhält sich wie ein Kunde
  - kein gezielter Test möglich, keine Gesamt-Coverage testen
  - keine Gefahr von Fehlern, die erst in Testumgebung entstehen
  - keine zusätzlichen Debug-Infos
- **White Box Test:** Code bekannt
  - Modultests möglich
  - gezielte Funktionstests mithilfe eigens konstruiertem Input möglich
  - Codeabdeckung testbar
  - zeitaufwändiger, da Einarbeitung in Code notwendig
  - Tester kennt Quellen, "erbt" Gedanken des Entwicklers, macht ggf. dieselben Fehler

## Modultests vs. Gesamtsystem-Tests

- Bottom-Up-Tests:
  - das zu testende Modul ruft nur bereits gestestete, korrekte Module auf
  - nur das Testprogramm wird selbst geschrieben
- Testen mit Stubs
  - Tests nur mit isolierten Funktionen
  - alles andere wird durch "Stubs" ersetzt $\rightarrow$ Dummys, Hilfsprogramme speziell zum Testen

## manuelle vs. automatische Tests

- automatisierte Ausführung und Auswertung, gleich in Datenbank, oft bei Nightly Build $\rightarrow$ zuverlässiger
- anderes ist schwer automatisierbar $\rightarrow$ händische Tests notwendig
- automatisierte Tests berücksichtigen nur wenige Nutzerfehler
- am Ende beides wichtig und sinnvoll

## Test-Checkliste

- Funktionalitäts-Tests
- Randfälle, Stabilität, Robustheit
- GUI-Kontrolle
  - Software-Ergonomie
  - Schönheitskontrolle
  - DPI / HiDPI
- Regressionstests
- Doku und Hilfe
- Installations-, Deinstallations-, Upgrade-Tests

## GUI-Scripting

- zwei Formen:
  - Benutzer-Input
  - Reaktionen auf Input
- Simulieren via Pixel-Vergleich oder mit modifizierten Programmen via GUI-Libraries
- drei Aufgaben:
  - Test des Programmes selbst
  - Autmatisiertes Ausführen / Installieren
  - Lasterzeugung

## Unit Tests

- Motivation: zeitnahe Fehlerfindung, gesamte Code-Abdeckung, genaue Lokalisierung
- Unit-Tests sind Tests von möglichst kleine Code-Stücken (z.B. Funktionen), auf konformes Verhalten
- laufen automatisch, erfordern Tooling
- hoher Einmal-Aufwand, geringer laufender Aufwand
- sind auch Regression Tests
- Positive Nebeneffekte:
  - Prüfung der Spezifikation
  - Prüfung des Feinentwurfes
- Ein Testfall pro Verhalten einer Funktion $\rightarrow$ ein Testfall pro Codefall
- Ein Testfall für jeden bekannten Bug
- Erstellung...
  - zeitnah / gleichzeitig zum Code
  - nicht durch QA $\rightarrow$ Betriebsblindheit
- grundsätzlich als Black Box Test
- erweitert durch White Box Tests
- Extremfall Test-Driven Development: Tests sind Spezifikation, werden zuerst geschrieben
- GUI und Multithreaded Code schlecht geeignet für Unit Tests
- werden in der Versionsverwaltung mit eingecheckt
- sind isoliert, darf nur zu testende Funktion aus dem Produktivcode verwenden
  - Aufruf von Realcode wird umgeleitet zu Stubs mit selber Schnittstelle, aber nur Simulationen
- Stubs und Mocks haben hohen Aufwand, sind ungetestet, divergieren von Realcode, z.B. bei Anpassungen der Spezifikation
- Werkzeuge: `JUnit`, `CUnit`, `CppUnit`, `CppTest`, `GoogleTest`, u.v.m.

## Famework-Komponenten

- Test-Makros
  - rufen zu testende Funktion auf
  - prüfen auf Ergebnis und Nebenwirkungen
  - protokollieren Test
  - ein Testmakro für einen Testfall
- Test-Setup und Test-Teardown
  - Anlegen und Aufräumen von frischen, leeren Test-Environments für jeden Test
  - meist für mehrere Tests verwendet
- Testverwaltung und -ausführung
  - jeder Test im Framework registriert
- Hierarchie:
  - Test-Suite: 1 pro Modul / Klasse
    - Tests: 1 pro Funktion / Methode
      - Testfälle: 1 pro Funktionalität
- Auswertungs-Skript
  - generieren Statistiken, Fehlerlisten, Unterschiede zum vorherigen Lauf
  - speichern und präsentieren Ergebnisse
