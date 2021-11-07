# Lernkontrollfragen: Grafische Datenverarbeitung

## Wofür steht CAD und wofür CAE?

## Auf welche Prozess des Produktlebenszyklusses konzentrieren wir uns im Kurs?

## Was versteht man unter "Mechatronik"?

## Was ist das Ziel eines PDM- bzw. PLM-Systems?

## Was ist ein "Virtuelles Produkt"?

## Erklären Sie den sogenannten "digitalen Zwilling"!

## Wie unterscheiden Sie Objektraum und Bildraum?

## Was verstehen Sie unter "Computervision"?

## Was stellen Sie sich unter Objektraum vor?

## Wofür stehen PPS und PDM?

## Was kennzeichnet ein integriertes Produktdatenmodell?

## Nennen Sie Beispiele für anwendungsbezogene und anwendungsübergreifende Funktionen eines PDM-Systems.

## Wofür steht der Begriff "vault" im Zusammenhang mit PDM-/PLM-Systemen?

## Erklären Sie die Unterscheidung in Produktdaten und Metadaten im Zusammenhang mit PDM-PLM-Systemen.

## Wofür steht die Anforderung der Rückverfolgbarkeit bei PDM-Systemen?

## Nennen Sie Beispiele für Applikationen im Zusammenhang mit CAE/CAD.

## Welche Betriebssysteme stehen für CAD-Systeme bevorzugt zur Verfügung?

Windows, macOS, Linux als Ausnahme.

## Nennen Sie bekannte bzw. große Hersteller für CAD-Systeme.

- Autodesk
- Siemens
- Dassault Systemés
- PTC

## Durch welche Aktivitäten ist der Markt der Softwareanbieter für die digitale Produktentwicklung gekennzeichnet?

- Abomodelle
- Rolling Release (kontinuierliche, kleinere Updates, meist in Verbindung mit besagten Abomodellen)

## Beschreiben Sie die Herangehensweise für die Geometriebeschreibung mittels CSG.

- CSG $\rightarrow$ Constructive Solid Geometry
- Platzierung von graphischen Primitiven, sodass sie eine Schnittmenge ergeben $\rightarrow$ verknüpfung mit booleschen Operatoren

## Was sind Feature im Zusammenhang mit CAD-Modellen?

- Bsp.: Bohrungen, Fasen, Flansche
- Formelemente
- manipulieren Komponenten
- sind Kindelemente von Komponenten

## Welche Booleschen Operatoren kennen Sie im Zusammenhanf mit CSG?

- Vereinigung, Differenzmenge, Schnittmenge

## Beschreiben Sie die geometrische Nutzung boolescher Operationen in CAD und CG.

- Kombination graphischer Primitive zur Bildung komplexer Geomatrien

## Aus welchen geometrischen Elementen ist eine komplexe Geometrie aufgebaut?

- Einzelteile bestehen aus Volumen
- Volumen werden von Flächen eingeschlossen
- Flächen bestehen aus Kanten
- Kanten bestehen aus Punkten

## Woran erkennt man schnell die Komplexität der Darstellung einer Geometrie?

- Vertices anzeigen lassen (Ecken eines Polygons)

## Worum handelt es sich bei geometrischen Randbedingungen?

- Constraints
- legen Verhältnis zwischen geom. Grundelementen fest
- Bsp.: Orthogonalität, Parallelität, Winkel

## Wie werden Parameter im Inventor verwendet?

<!--häufig!-->

- Definition von Form und Größe von Features
- auch im Parameter-Editor
- Positionierung von Komponenten
- Bestimmung von Komponenten $\rightarrow$ keine Freiheitsgrade

## Was repräsentiert der Modellbaum (Historiengraph) im Inventor?

- Projekthierarchie, Vererbung, Komponentenhistorie

## Was versteht man unter "Parametric Design"?

<!--Quatsch-->

- Parameter können editiert werden, Komponente passt sich entsprechend an

## Was ist das Ziel geometrischer Grundelemente im 2D- und 3D-Bereich?

- bilden Basis für Modellierung
- ermöglichen Datenaustausch durch Annäherung von komplexen Geometrien (z.B.: B-Spline $\rightarrow$ Kreis)
- "vom Groben zum Feinen"

## Was ist eine Bezierkurve?

- Spline, Freiformkurve
- geht durch Punkte oder mithilfe von Polen

## Was sind NURBS?

- Non-Uniform Rational B-Splines and Surfaces
- exakt beschriebene Freiformflächen
- alle CAD-Systeme sind NURBS-Modellierer

## Wie wird Truetype-Font geometrisch beschrieben?

- bestehen ausschließlich aus B-Splines 2. Grades

## Worum handelt es sich bei sog. "meatballs"?

- s. Wassertropfenform
- Modellierungsform auf Basis von Kugeln als Grundelement
  - mit Eigenschaften wie Oerflächenspannung

## Was versteht man unter "Subdivision Surface Modeling"?

Flächenverteilungsmodellierung
