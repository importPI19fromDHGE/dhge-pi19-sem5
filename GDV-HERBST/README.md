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
  - [CAD-Grundlagen](#cad-grundlagen)
  - [CAD-Technik](#cad-technik)
  - [Konfiguration](#konfiguration)
  - [Internet](#internet)
  - [Konstruktion](#konstruktion)
  - [Werkzeuge](#werkzeuge)
- [CG - Computer Graphics](#cg---computer-graphics)
  - [CG-Grundlagen](#cg-grundlagen)
  - [Mathematik](#mathematik)
  - [Farbgebung](#farbgebung)
  - [CG-Technik](#cg-technik)
  - [Standards](#standards)
  - [2D-Elemente](#2d-elemente)
  - [3D-Objekte](#3d-objekte)
  - [Visualisierung](#visualisierung)
  - [Bildformate](#bildformate)
- [Grundlagen geometrischer Modellierung](#grundlagen-geometrischer-modellierung)
  - [grafische Primitive](#grafische-primitive)
    - [2D-Elemete](#2d-elemete)
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

## CAD-Grundlagen

- **CAD:** Computer Aided Design (Computergestützte Entwicklung von Produkten)
  - **MCAD:** Mechanical CAD
  - **ECAD:** Electronic CAD
- **CAE:** Computer Aided Engineering (Produktentwicklung mit Simulation)
- **ERP:** Enterprise Resource Planing (Kaufmännische Produktentwicklung)
- **PPS:** Production Planning System (in der Produktion verwendet)
- **PDM/PLM** Produktdatenmanagement/Product Lifecycle Management
- **Mechatronik:** Mechanik + Elektronik + Softwareentwicklung?
- **e-collaboration:** elektronische Zusammenarbeit bei der Produktentwicklung
- **Rapid-Prototyping** (additive manufacturing): Digitales Modell in reales Produkt überführen (Prototyping: 3D-Druck)
- **PEP:** Produktentwicklungsprozess (genormt nach DIN)
- Industrie 4.0 (Digitalisierung als 4. industrielle Revolution) / IoT / Digitaler Zwilling / Digitale Transformation / ...

<!-- ziemlich viele einfache Begriffe, aber wir haben sehr viel Zeit damit verbracht (in BAckstage soll ein Glossar landen) -->

## CAD-Technik

## Konfiguration

## Internet

## Konstruktion

## Werkzeuge

# CG - Computer Graphics

## CG-Grundlagen

> Umwandlung von Daten des Objektraums in grafische Daten des Bildraumes

- **CG:** Computer Graphics
- **DCC:** Digital Content Creation
- **Rendering:** Berechnung der grafischen Ausgabe
- **Immersion:** Eintauchen in virtuelle Welten
- **VR/AR/MR/XR:** Virtual-/Augmented-/Mixed-Reality

## Mathematik

## Farbgebung

## CG-Technik

## Standards

## 2D-Elemente

## 3D-Objekte

## Visualisierung

## Bildformate

# Grundlagen geometrischer Modellierung

## grafische Primitive

### 2D-Elemete

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
