<!----------
title: "Theorie und Praxis programmierbarer logischer Schaltungen"
date: "Semester 5"
keywords: [logische Schaltungen, PLD, DHGE, Semester 5]
---------->

Theorie und Praxis programmierbarer logischer Schaltungen
=========================================================

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Inhaltsverzeichnis**

- [Platzhalter](#platzhalter)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Wiederholung Digitaltechnik

## Disjunktive Normalform (DNF)

- logischer Ausdruck, der in der oberen Ebene ausschließlich aus ODER-Verknüpfungen besteht
- Stufen:
  - 1.Stufe: UND-Verknüpfungen (Konjunktionen)
  - 2.Stufe: ODER-Verküpfungen

**Beispiel:**

**1.Stufe:**
P1 = X1 & $\overline{X2}$ & X3
P2 = X2 & $\overline{X3}$

**2.Stufe:**
Y = P1 $\lor$ = (X1 &  $\overline{X2}$ & X3)  $\lor$ (X2 &  $\overline{X3}$)

Für die Schaltung würde dies bedeuten, dass die Signale zunächst durch UND und danach durch ODER geführt werden.

> zum Weiterlesen: <https://www.biancahoegel.de/logik/normalform_disjunktiv.html>

## Konjunktive Normalform

- logischer Ausdruck, der in der oberen Ebene ausschließlich aus UND-Verknüpfungen besteht
- ist eine Konjunktion von Disjunktionstermen, dementsprechend:
  - 1.Stufe: ODER-Verknüpfungen
  - 2.Stufe: UND-Verknüpfungen
- wird für programmierbare Logiken eher nicht verwendet

> zum Weiterlesen: <https://www.biancahoegel.de/logik/normalform_konjunktiv.html>

**Beispiel:** Y=(X1 $\lor$ X2) & (!X2  $\lor$ !X3) & (!X1  $\lor$ X2  $\lor$ X3)

## Look-Up-Tables (LUT)

- LUT sind Tabellen, in denen vorberechnete Ergebnisse gespeichert werden
- der Abruf dieser Informationen ist u.U. schneller bzw. flexibler als diese zur Laufzeit zu berechnen
- Für FPGAs werden LUT verwendet, um Binärfunktionen zu hinterlegen
- somit können (fast) beliebige physische Gatter simuliert werden
- die LUT werden in SRAM-Zellen hinterlegt und könnend ann durch Ansteuerung der Eingänge ausgelesen werden

> weitere Infos: <https://de.wikipedia.org/wiki/Field_Programmable_Gate_Array#Aufbau_und_Struktur>

# PLDs: Programmable Logic Devices

## Einordnung und Abgrenzung zum Mikrocontroller

Als PLD (Programmable Logic Device) werden **elektronische Bauelemente** bezeichnet, die in **integrierten Schaltungen** verwendet werden. Sie werden von logischen Gattern dadurch abgegrenzt, dass ihre Funktion konfigurierbar ist (daher *programmable*).

|Mikroprozessor|PLD|
|---|---|
|EVA-Prinzip|EVA-Prinzip|
|Sequenzielle Verarbeitung $\rightarrow$ eher langsam|Parallele Verarbeitung $\rightarrow$ eher schnell|
|Günstig|Teuer|
|Allgemein gehalten|spezialisiert|

## Unterscheidung nach Art der Programmierung

|Programmierungsart|Beschreibung|Merkmale|
|---|---|---|
|**Fuse**|Verbindungen, die nach der Produktion bestehen, werden **aufgetrennt**|Auftrennen ist dauerhaft $\rightarrow$ nur einmal konfigurierbar|
||dies geschieht z.B. durch Laser oder elektrische Energie||
||||
|**Antifuse**|Konfiguration geschieht durch das **Herstellen von Verbindungen**|dauerhaft $\rightarrow$ nur einmal konfigurierbar|
||durch Laser, Metallmasken, elektrische Energie||
||||
|**EPROM**|erasable programmable read-only memory|löschbar, wiederbeschreibbar, nicht flüchtig|
||nichtflüchtiger Speicher|spezielle Geräte zur Konfiguration benötigt|
||durch UV-Licht löschbar|wird kaum bis gar nicht mehr verwendet|
||danach neuprogrammierbar||
||||
|**EEPROM**|electrically erasable programmable read-only memory|löschbar, wiederbeschreibbar, nicht flüchtig|
||elektrisch löschbarer Speicher|wort- und byteweise löschbar|
||besteht aus Matrix von Feldeffekttransistoren||
||||
|**Flash-EEPROM**|Sonderform der EEPROMs|löschbar, wiederbeschreibbar, nicht flüchtig|
|||nur blockweise löschbar, nicht auf byte- oder Wortgröße|
||||
|**(S)RAM**|(static) random-access memory|löschbar, wiederbeschreibbar, **flüchtig**|
|||flüchtig $\rightarrow$ Strom weg, Inhalt weg|

## Unterscheidung nach internem Aufbau / Komplexität

### SPLD - Simple Programmable Logic Device

> Hinweis: SPLD kam als Bezeichnung nicht in der Vorlesung vor, kann aber als Klassenbezeichnung für PAL, PLA und GAL verwendet werden.
> further reading: <http://www.informatik.uni-ulm.de/ni/Lehre/SS01/TI/folien/pld.pdf>

#### PAL - Programmable Array Logic

- nach DNF aufgebaut (erste Stufe ist UND-Matrix, zweite Stufe ist ODER-Matrix)
- UND-Matrix ist als Array programmierbar
  - es kann also bestimmt werden, welche Eingangsvariablen UND-verknüpft werden sollen
- ODER-Matrix ist fest vorgegeben
- auf EEPROM-Basis

#### GAL - General Array Logic

- selbes Kernprinzip wie PAL (1. Stufe = programmierbares UND, zweite Stufe festes ODER) $\rightarrow$ Realisierung DNF
- besitzen jedoch zusätzlich konfigurierbare Ausganszellen (OLMC)
  - OLMC = *output logic macrocell*
  - durch diese können u.A. die Ausgangssignale umgeleitet und wieder in die UND-Matrix zurückgeleitet werden
- auf EEPROM-Basis

> Zusatzinfo aus <https://k1.spdns.de/Develop/Hardware/K1-Bus%2068008%20CPU%20board%20with%20DRAM/GALs%20und%20so/PLD_Vers.pdf>
> OLMCs können als Eingang, kombinatorischer Ausgang, Tristate-Ausgang, Tristate-Ausgang im Registermodus und als Resgisterausgang konfiguriert werden

#### PLA - Programmable Logic Array

- zusätzlich zu der programmierbaren UND-Matrix ist bei PLAs auch die ODER-Matrix programmierbar
- dies führt zu einer höheren Flexibilität
- auf EEPROM-Basis

### CPLD - Complex Programmable Logic Device

- bei CPLDs sind mehrere (S)PLDs über eine programmierbare Verbindungsmatrix miteinander verbunden
  - die frei programmierbare UND & ODER - Matrix wird zudem um sogenannte Makrozellen ergänzt, welche zusätzliche Logiken implementieren können
- Ansteuerung der einzelnen Bausteine von Außen daher sowohl über Verbindungsmatrix als auch direkt möglich
- einfach interne Verdrahtung $\rightarrow$ Signallaufzeiten vorhersagbarar als bei *FPGA*
- auf EEPROM-Basis

**Leistungsparameter:**

- Anzahl der Makrozellen
- Max I/Os
- Max. Taktfrequenz
- Anzahl der Logikelemente
- Verzögerungszeit pin-to-pin

### FPGA - Field Programmable Gate Array

- im Gegensatz zu vorab genannten Technologien, die auf logischer Matrix beruhen $\rightarrow$ Look-Up-Tables (LUTs) als zentrales Element der FPGAs
- sind ein Feld aus Logikblöcken und I/O-Blöcken die über ein Verbindungsnetzwerk verschaltet sind
- in jedem Logikblock: LUT und Steuerfunktionen
- oftmals auf SRAM-Basis  $\rightarrow$ müssen nach Wegfall der Spannung neu programmiert werden
  - Programmierung kann in einigen Modellen aber auf EEPROM- oder Flash-Chips vorgehalten werden

## Abgrenzung zu anderen Technologien

**ASIC (application-specific integrated circuit)**

- integrierter Schaltkreis
- für bestimmten Anwendungsfall entworfen und optimiert
- nach Kundenanforderung entworfen und nur an diesen geliefert

**ASSP (application specific standard product)**:

- wie ASIC, nur dass diese Bauteile am Markt verkauft werden (mehrere Kunden)

**Mikrocontroller (uC)**

- elektronische Bauteile, die Prozessor und Peripheriefunktionen enthalten
- Funktion wird durch Software verwirklicht

### Vergleich

||ASIC|ASSP|uC|FPGA|
|---|---|---|---|---|
|Hohe Flexibilität|+|-|+|++|
|Geringe Entwicklungszeit|--|+|++|O|
|Geringe Entwicklungskosten|--|+|++|O|
|Geringe Stückkosten|++|+|++|O|
|Rechenleistung|++|++|O|+|
|Verlustleistung|++|++|O|O|
|Geringe Stückzahlen möglich|--|++|++|++|
|Hohe Stückzahlen möglich|++|++|++|+|

> lt. Folien aus: Gehrke; Winzker; Urbanski; Woitowitz: *Digitaltechnik*. Springer Vieweg; 2018
