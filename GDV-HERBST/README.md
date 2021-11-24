<!----------
title: "Graphische Datenverarbeitung"
date: "Semester 5"
keywords: [Graphische Datenverarbeitung, GDV, CAD, CAE, CG, DHGE, Semester 5]
---------->

Graphische Datenverarbeitung
============================

<!-- md2apkg ignore-card -->

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Inhaltsverzeichnis**

- [Graphische Datenverarbeitung](#graphische-datenverarbeitung)
- [Organisatorisches](#organisatorisches)
- [CAD - Computer Aided Design](#cad---computer-aided-design)
  - [Grundlagen und Glossar](#grundlagen-und-glossar)
    - [CAD](#cad)
    - [CAE](#cae)
    - [ERP](#erp)
    - [PPS](#pps)
    - [PLM](#plm)
    - [PDM](#pdm)
    - [Mechatronik](#mechatronik)
    - [e-collaboration](#e-collaboration)
    - [Rapid-Prototyping / additive manufacturing](#rapid-prototyping--additive-manufacturing)
    - [PEP](#pep)
    - [Industrie 4.0](#industrie-40)
    - [IoT](#iot)
    - [Digitaler Zwilling](#digitaler-zwilling)
    - [Digitale Transformation](#digitale-transformation)
    - [integriertes Produktdatenmodell](#integriertes-produktdatenmodell)
    - [CG](#cg)
    - [DCC](#dcc)
    - [Rendering](#rendering)
    - [VR, AR, MR, XR](#vr-ar-mr-xr)
    - [Immersion](#immersion)
    - [ungeordnet, muss noch an andere Stelle](#ungeordnet-muss-noch-an-andere-stelle)
- [Grundlagen geometrischer Modellierung](#grundlagen-geometrischer-modellierung)
  - [grafische Primitive](#grafische-primitive)
    - [2D-Elemente](#2d-elemente)
    - [3D-Elemente](#3d-elemente)
  - [Boolsche Operatoren](#boolsche-operatoren)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Organisatorisches

<!-- md2apkg ignore-card -->

- Software:
  - [Autodesk Inventor](https://www.autodesk.de/solutions/autocad-and-inventor)
  - [3ds max](https://www.autodesk.de/products/3ds-max/overview)
- Klausur: Theoretische Zusammenhänge (größtenteils Multiple-Choice)

# CAD - Computer Aided Design

## Grundlagen und Glossar

### CAD

CAD bedeutet **C**omputer **A**ided **D**esign und beschreibt die Unterstützung von Konstruktionsaufgaben mittels Hilfsmitteln der EDV.
Es kann unterteilt werden in:

- **MCAD**: **M**echanical CAD, zur Konstruktion mechanischer Systeme
- **ECAD**: **E**lewctronic CAD, zur Konstruktion elektronischer Systeme

Anwendung:

- leichte und schnelle Änderung der Modelle auch im fortgeschrittenen Konstruktionsprozess
- Vorbeugen von Informationsverlusten und Fehlern
- Simulationen und Berechnungsverfahren anhand der Modelle (dann: CAE)
  - z.B. thermische, aerodynamische Simulation, Materialdatenbanken, Recycling
- Digital Mock-Ups

### CAE

CAE bedeutet **C**omputer **A**ided **E**ngineering und beschreibt die Nutzung von CAD für Berechnungen und Simulationen der so erstellten Bauteile.
Anwendung für Thermodynamik, Belastungsanalyse, Flussanalyse von Flüssigkeitn durch die Bauteile, ...

### ERP

**E**nterprise **R**essource **P**lanning beschreibt Softwarelösungen zur Ressourcenverwaltung und -planung in einem Unternehmen oder einer Organisation.
Es integriert eine Vielzahl von Geschäftsanwendungen und Betriebsdaten für die Verwaltung in einer zentralen Datenbank.
Hier werden vor allem personelle und finanzielle Ressourcen verwaltet. **PPS**-Systeme können ggf. integriert werden.

### PPS

**P**roduct **P**lanning **S**ystems oder Produktplanungs- und Produktsteuerungssysteme sind Softwarelösungen, die die Produktionsplanung und -steuerung unterstützen.
Sie übernehmen die mit dem Prozess verbundene Datenverwaltung.

Ziel:

- kurze Durchlaufzeiten
- optimale Bestandshöhen
- Termineinhaltung
- wirtschaftliche Nutzung der Betriebsmittel

Quelle: [Wikipedia-PPS](https://de.wikipedia.org/wiki/PPS-System)

### PLM

**P**roduct **L**ifecycle **M**anagement ist ein Management-Ansatz zur Verwaltung aller Daten, die im Lebenszyklus eines Produktes anfallen.
PLM kann durch EDV unterstützt werden, wobei die Daten schnell und zentral bereitgestellt werden sollen.
Integration in oder Schnittstellen zu anderen Systemen wie ERP sind sinnvoll, da Daten der CAD, CAE, CAM, ERP, PDM, ..., hier zentral verwaltet werden sollen.

Typische Phasen in Lebenszyklus:

- Planung
- Konstruktion
- Fertigungsplanung
- Produktion
- Nutzung
- Wartung
- Recycling

### PDM

Durch das **P**roduct **D**ata **M**anagement werden alle Daten der Entstehungsphase eines Produktes gesammelt, aufgearbeitet und zentral bereitgestellt.
Es dient somit als erste Grundlage für PLM.

Mögliche Daten:

- Produktstruktur (Baugruppen und Einzelteile)
- Varianten- und Konfigurationen
- Klassifizierung
- Materialien
- Änderungshistorie
- Status- und Freigabe

Beispielsoftware:

- Teamcenter (Siemens/UGS)
- Productstream (Autodesk)
- Product Manager (IBM)

> Quelle: [contact-software: PDM](https://www.contact-software.com/de/wissen/schwerpunkte/produktdatenmanagement-pdm-system)

### Mechatronik

**Mechatronik** bezeichnet das interdisziplinäre Zusammenwirken von Mechanik/Maschinenbau, Elektronik/Elektrotechnik und Informatik (und weiteren).

> Quelle [Wikipedia: Mechatronik](https://de.wikipedia.org/wiki/Mechatronik)

### e-collaboration

Beschreibt die Maßnahmen zur dezentralen computergestützten Zusammenarbeit von zeitlich und/oder räumlich getrennten Teams und Gruppen, die an einer gemeinsamen Aufgabe arbeiten.
Hier: arbeiten gemeinsam an einem Produkt.

> Quelle [Wikipedia: e-collaboration](https://de.wikipedia.org/wiki/E-Collaboration)

### Rapid-Prototyping / additive manufacturing

**Rapid-Prototyping** bezeichnet die schnelle Herstellung eines Musters oder Modells auf Basis von CAD-Daten.
Dies geschieht häufig durch **additive manufacturing**, also z.B. 3D-Druck, wo schichtweise (additiv) das Modell hergestellt wird.

Vorteile:

- frühes Bild, wie das Produkt aussehen wird
- kostengünstige Prototypherstellung
- frühe Problemerkennung

> Quelle: [twi-global Rapid-Prototyping](https://www.twi-global.com/locations/deutschland/was-wir-tun/haeufig-gestellte-fragen/was-ist-rapid-prototyping)

### PEP

**P**rodukt**e**ntstehungs**p**rozess: Darstellung und Beschreibung der Arbeitsabläufe von der Produktidee bis Herstellung und Verkauf.
Normung nach DIN.

### Industrie 4.0

Projekt der Bundesregierung und Forschungsplattform. Ziel ist die Verknüpfung industrieller Produktion mit moderner Informations- und Kommunikationstechnik und die Optimierung der Wertschöpfungskette.

Prinzipien:

- Vernetzung
- Informationstransparenz
- technische Assistenz
- dezentrale Entscheidungen

> Quelle: [Wikipedia: Industrie 4.0](https://de.wikipedia.org/wiki/Industrie_4.0)

### IoT

Das Netzwerk physischer Objekte, die z.B. per Sensoren Daten sammeln und per integrierter Software über das Internet mit anderen Objekten Daten austauschen.

### Digitaler Zwilling

Die digitale Repräsentation eines Objekts der realen Welt. Darüber hinaus: Datenaustausch zwischen den Zwillingen möglich.

Beispiele:

- Track and Trace in der Logistik
- Anwendungen im PLM

### Digitale Transformation

Der fortlaufende, durch digitale Technologien begründete gesamtgesellschaftliche Veränderungsprozess.
Betrachtet werden vor allem Auswirkungen auf Wirtschaft und Industrie.

### integriertes Produktdatenmodell

Ein Datenmodell, welches das komplette Produkt beschreibt.

Inhalt:

- Produktdefinition:
  - Identifikation, Klassifikation
  - Freigabe und Änderungszustände
- Produktrepräsentation (Eigenschaften über Merkmale ausgedrückt):
  - Geometrie, Topologie
  - FEM, Kinematik
Produktpräsentation:
  - grafisch, textuell, zeichnerisch
  - multimedial
  - Animationen

### CG

**C**omputer **G**raphics: Bildgeneration durch Computersysteme.
Beschreibt die "Umwandlung von Daten des Objektraumes in grafische Daten des Bildraumes, wozu Methoden wie Balkendiagramme, Ablaufpläne, Karten, Zeichnungen und Schaltpläne
bis hin zur Illustration dreidimensionaler Objekte zählen."

### DCC

**D**igital **C**ontent **C**reation: Erstellung multimedialer Inhalte durch Computerunterstützung.

### Rendering

Erstellen einer Grafik aus Rohdaten.

Beispiele:

- Fertigstellen eines Videos aus dem Schnittprogramm
- Erstellen einer Grafik aus CAD-Modell

### VR, AR, MR, XR

- **V**irtual Reality: Darstellung und Wahrnehmung einer scheinbaren Wirklichkeit und ihrer Eigenschaften in Echtzeit
  - z.B. VR-Brillen
- **A**ugmented **R**eality: computergestützte Erweiterung der Realitätswahrnehmung (durch Einblendung, Überlagerung)
  - z.B. Pokemon Go
- **M**ixed **R**eality: Überführung der Realität in virtuelle Realität
  - durch Devices (Handbewegungen ins Digitale)
  - durch Kamera (realer Raum ins Digitale)
- e**X**tended **R**eality: Überbegriff für AR,VR,MR

### Immersion

Der Grad, mit dem eine virtuelle Umgebung als real empfunden wird. Wird durch enstprechende Hardware (VR-Brillen, Interaktionsequipment, ...) erhöht.

### ungeordnet, muss noch an andere Stelle

- Tendenzen bei Herstellern: Abo-Modelle, Abdeckung des gesamten PLM, Angebot in unterschiedlichen Preissegmenten, cloudbasierte Angebote
- komplexe Geometrien sind aus "Features", deutsch "Formelemente\[n\]" aufgebaut $\rightarrow$ Fasen, Bohrungen, ...
  - bestehen wiederum aus Flächenelementen aus Kanten und Vertices, die eine Hüllengeometrie erstellen
- Historiengraph (Modellbaum) beschreibt die vollständige Geometrie und auch die "Entstehungsgeschichte" der Objekte, enthält "Know-how des Konstrukteurs"
- NURBS: Non-Uniform Rational B-Spline; Übetragung von Splines in den Raum $\rightarrow$ Flächenbeschreibung
  - heutige CAD-Systeme sind NURBS-Modellierer
- TrueType: Fonts, ausschließlich mit Splines beschrieben
- "Metabälle": Tropfenform als Modell-Basis, Partikelsysteme

<!-- ziemlich viele einfache Begriffe, aber wir haben sehr viel Zeit damit verbracht (in BAckstage soll ein Glossar landen) -->
<!-- das Glossar ist jetzt auch nicht so der Burner, LG Max -->
<!-- so sollte es jetzt auch anki schlucken. Vielleicht ist das schöner. MfG, Ben-->

# Grundlagen geometrischer Modellierung

## grafische Primitive

### 2D-Elemente

- Punkte, Linien, Polygone, Spline, Bézier-Kurven, Kreise, Rechtecke, Text (mit Fonts)
- Kreise sind problematisch, da sie eigentlich Polygone mit unendlich vielen Ecken sind $\rightarrow$ müssen in Liniensegmente aufgeteilt werden
  - Fachbegriff: Segmentierung und Tesselierung
- Punkte sind auch problematisch: sie sind dimensionslos, man würde ihn nicht sehen $\rightarrow$ prozentual berechnete Größe abhängig von der Bildschirmauflösung
- Spline und Beziér-Kurve: frei geformte Kurven, die durch Punkte gehen; mathematisch ein Polynom n-ten Grades
  - muss ebenfalls in Liniensegmente unterteilt werden, mehr noch als Kreise
    - wenn das einmal geschehen ist, kann die Kurve jedoch **nicht** mehr wiederhergestellt werden
    - v.a. bei Datenübertragung zu anderen Programmen

### 3D-Elemente

- Quader, Kugel, Zylinder, Kegel, ...
- Bézier-Fläche / NURBS (Non-Uniform Rational B-Spline and Surfaces), Subdivision Surfaces Modeling / SubD NURBS
- Metabälle / Blob-Netz (verbindet sich selbstständig mit anderen Objekten mithilfe Verbindungsoberfläche)
- Problemstellungen:
  - Parameter, UI-Erstellung, Tesselierung, Interpolation, alternative Modellierungsansätze
  - Tesselierung genauer: Flächen werden in Dreiecke unterteilt
- moderne CAD-Systeme sind meist NURBS-Modellierer
- SubD NURBS in Autodesk Inventor: "Freiform erstellen"

## Boolsche Operatoren

- Vereinigung OR
- Differenzmenge "A\\B" (NOT?)
- Schnittmenge AND
