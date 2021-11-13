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

- [Wiederholung Digitaltechnik](#wiederholung-digitaltechnik)
  - [Disjunktive Normalform (DNF)](#disjunktive-normalform-dnf)
  - [Konjunktive Normalform](#konjunktive-normalform)
  - [Look-Up-Tables (LUT)](#look-up-tables-lut)
- [PLDs: Programmable Logic Devices](#plds-programmable-logic-devices)
  - [Einordnung und Abgrenzung zum Mikrocontroller](#einordnung-und-abgrenzung-zum-mikrocontroller)
  - [Unterscheidung nach Art der Programmierung](#unterscheidung-nach-art-der-programmierung)
  - [Unterscheidung nach internem Aufbau / Komplexität](#unterscheidung-nach-internem-aufbau--komplexit%C3%A4t)
    - [SPLD - Simple Programmable Logic Device](#spld---simple-programmable-logic-device)
      - [PAL - Programmable Array Logic](#pal---programmable-array-logic)
      - [GAL - General Array Logic](#gal---general-array-logic)
      - [PLA - Programmable Logic Array](#pla---programmable-logic-array)
    - [CPLD - Complex Programmable Logic Device](#cpld---complex-programmable-logic-device)
    - [FPGA - Field Programmable Gate Array](#fpga---field-programmable-gate-array)
  - [Abgrenzung zu anderen Technologien](#abgrenzung-zu-anderen-technologien)
    - [Vergleich](#vergleich)
- [VHDL - Very High Speed Integrated Circuit Hardware Description Language](#vhdl---very-high-speed-integrated-circuit-hardware-description-language)
  - [VHDL-Modelle](#vhdl-modelle)
    - [Entity](#entity)
    - [Architecture](#architecture)
    - [Configuration](#configuration)
  - [Packages / Bibliotheken](#packages--bibliotheken)
  - [Datentypen](#datentypen)
  - [Typumwandlungen](#typumwandlungen)
  - [Operatoren](#operatoren)
    - [Logische Operatoren](#logische-operatoren)
    - [Arithmetische Operatoren](#arithmetische-operatoren)
    - [Vergleichsoperatoren](#vergleichsoperatoren)
  - [Processes](#processes)
  - [Signale](#signale)
  - [Variablen](#variablen)
  - [Port Maps](#port-maps)
  - [Components](#components)
  - [Arrays](#arrays)
  - [if](#if)
  - [case](#case)
  - [ATTRIBUTE KEEP](#attribute-keep)
  - [Testen mit VHDL](#testen-mit-vhdl)
  - [JTAG](#jtag)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Wiederholung Digitaltechnik

## Disjunktive Normalform (DNF)

- logischer Ausdruck, der in der oberen Ebene ausschließlich aus ODER-Verknüpfungen besteht
- Stufen:
  - 1.Stufe: UND-Verknüpfungen (Konjunktionen)
  - 2.Stufe: ODER-Verknüpfungen

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
- die LUT werden in SRAM-Zellen hinterlegt und könnend dann durch Ansteuerung der Eingänge ausgelesen werden

> weitere Infos: <https://de.wikipedia.org/wiki/Field_Programmable_Gate_Array#Aufbau_und_Struktur>

# PLDs: Programmable Logic Devices

## Einordnung und Abgrenzung zum Mikrocontroller

Als PLD (Programmable Logic Device) werden **elektronische Bauelemente** bezeichnet, die in **integrierten Schaltungen** verwendet werden. Sie werden von logischen Gattern dadurch abgegrenzt, dass ihre Funktion konfigurierbar ist (daher *programmable*).

| Mikroprozessor                                       | PLD                                               |
| ---------------------------------------------------- | ------------------------------------------------- |
| EVA-Prinzip                                          | EVA-Prinzip                                       |
| Sequenzielle Verarbeitung $\rightarrow$ eher langsam | Parallele Verarbeitung $\rightarrow$ eher schnell |
| Günstig                                              | Teuer                                             |
| Allgemein gehalten                                   | spezialisiert                                     |

## Unterscheidung nach Art der Programmierung

| Programmierungsart | Beschreibung                                                           | Merkmale                                                         |
| ------------------ | ---------------------------------------------------------------------- | ---------------------------------------------------------------- |
| **Fuse**           | Verbindungen, die nach der Produktion bestehen, werden **aufgetrennt** | Auftrennen ist dauerhaft $\rightarrow$ nur einmal konfigurierbar |
|                    | dies geschieht z.B. durch Laser oder elektrische Energie               |                                                                  |
|                    |                                                                        |                                                                  |
| **Antifuse**       | Konfiguration geschieht durch das **Herstellen von Verbindungen**      | dauerhaft $\rightarrow$ nur einmal konfigurierbar                |
|                    | durch Laser, Metallmasken, elektrische Energie                         |                                                                  |
|                    |                                                                        |                                                                  |
| **EPROM**          | erasable programmable read-only memory                                 | löschbar, wiederbeschreibbar, nicht flüchtig                     |
|                    | nichtflüchtiger Speicher                                               | spezielle Geräte zur Konfiguration benötigt                      |
|                    | durch UV-Licht löschbar                                                | wird kaum bis gar nicht mehr verwendet                           |
|                    | danach neuprogrammierbar                                               |                                                                  |
|                    |                                                                        |                                                                  |
| **EEPROM**         | electrically erasable programmable read-only memory                    | löschbar, wiederbeschreibbar, nicht flüchtig                     |
|                    | elektrisch löschbarer Speicher                                         | wort- und byteweise löschbar                                     |
|                    | besteht aus Matrix von Feldeffekttransistoren                          |                                                                  |
|                    |                                                                        |                                                                  |
| **Flash-EEPROM**   | Sonderform der EEPROMs                                                 | löschbar, wiederbeschreibbar, nicht flüchtig                     |
|                    |                                                                        | nur blockweise löschbar, nicht auf byte- oder Wortgröße          |
|                    |                                                                        |                                                                  |
| **(S)RAM**         | (static) random-access memory                                          | löschbar, wiederbeschreibbar, **flüchtig**                       |
|                    |                                                                        | flüchtig $\rightarrow$ Strom weg, Inhalt weg                     |

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
> OLMCs können als Eingang, kombinatorischer Ausgang, Tristate-Ausgang, Tristate-Ausgang im Registermodus und als Registerausgang konfiguriert werden

#### PLA - Programmable Logic Array

- zusätzlich zu der programmierbaren UND-Matrix ist bei PLAs auch die ODER-Matrix programmierbar
- dies führt zu einer höheren Flexibilität
- auf EEPROM-Basis

### CPLD - Complex Programmable Logic Device

- bei CPLDs sind mehrere (S)PLDs über eine programmierbare Verbindungsmatrix miteinander verbunden
  - die frei programmierbare UND & ODER - Matrix wird zudem um sogenannte Makrozellen ergänzt, welche zusätzliche Logiken implementieren können
- Ansteuerung der einzelnen Bausteine von Außen daher sowohl über Verbindungsmatrix als auch direkt möglich
- einfach interne Verdrahtung $\rightarrow$ Signallaufzeiten besser vorhersagbar als bei *FPGA*
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

**ASIC (application-specific integrated circuit)**:

- integrierter Schaltkreis
- für bestimmten Anwendungsfall entworfen und optimiert
- nach Kundenanforderung entworfen und nur an diesen geliefert

**ASSP (application specific standard product)**:

- wie ASIC, nur dass diese Bauteile am Markt verkauft werden (mehrere Kunden)

**Mikrocontroller (uC)**:

- elektronische Bauteile, die Prozessor und Peripheriefunktionen enthalten
- Funktion wird durch Software verwirklicht

### Vergleich

|                             | ASIC | ASSP | uC  | FPGA |
| --------------------------- | ---- | ---- | --- | ---- |
| Hohe Flexibilität           | +    | -    | +   | ++   |
| Geringe Entwicklungszeit    | --   | +    | ++  | O    |
| Geringe Entwicklungskosten  | --   | +    | ++  | O    |
| Geringe Stückkosten         | ++   | +    | ++  | O    |
| Rechenleistung              | ++   | ++   | O   | +    |
| Verlustleistung             | ++   | ++   | O   | O    |
| Geringe Stückzahlen möglich | --   | ++   | ++  | ++   |
| Hohe Stückzahlen möglich    | ++   | ++   | ++  | +    |

> lt. Folien aus: Gehrke; Winzker; Urbanski; Woitowitz: *Digitaltechnik*. Springer Vieweg; 2018

# VHDL - Very High Speed Integrated Circuit Hardware Description Language

## VHDL-Modelle

### Entity

- beschreibt die Ein- und Ausgänge einer Struktur
- Struktur selbst ist in dieser Beschreibung eine BlackBox
  - das Innenleben wird nicht beschrieben
- Schnittstellen werden in ``port`` beschrieben
  - dabei Namensgebung und Richtung der Verbindung (in/out)

Beispiel:

```vhdl
entity beispielname is
  port ( a : in std_logic;
         b : in std_logic;
         q : out std_logic) ;
end beispielname;
```

### Architecture

- Architecture ist die Verhaltensbeschreibung
- was passiert im Inneren der BlackBox?

Beispiel:

```vhdl
architecture behave of entityName is
begin
  q <= a and b;
end;
```

### Configuration

- sind für uns nicht relevant
- Konzept zur Erweiterung der basalen Möglichkeiten in VHDL

## Packages / Bibliotheken

- Bibliotheken werden in VHDL ``packages`` genannt

Verwendung:

```vhdl
-- packages std und work brauchen keine library-Anweisung:
-- std liefert Standardfunktionen
use std.textio.all;
-- mit work können eigene Pakete verwendet werden
-- diese müssen bereits in der Arbeitsbibliothek hinterlegt sein
use work.eigenesPaket.all;
-- für darüber hinausgehende Pakete muss library verwendet werden
-- so z.B. für Datentypen aus dem iee-Standard
library ieee;
use ieee.std_logic_1164.all;
```

## Datentypen

- ``INTEGER``
  - ganze Zahlen, in der Standardbibliothek
- ``STD_LOGIC``
  - Mögliche Werte:
    - U : uninitalized
    - X : unknown
    - 0 : low
    - 1 : high
    - Z : high impedance
    - W : weak unknown
    - L : weak low
    - H : weak high
    - \- : don´t care
  - aus ieee-library
- ``STD_LOGIC_VECTOR``
  - std_logic als Vektor
  - ieee-library
- ``SIGNED``
  - positive oder negative Ganzzahlen
- ``UNSIGNED``
  - positive Ganzzahlen
- ``BIT``
  - einzelnes Bit

> weitere Datentypen möglich, aber für uns nicht relevant

## Typumwandlungen

- Teilweise nur über Umwege möglich
- ``STD_LOGIC_VECTOR``
  - per ``signed(x)`` zu ``SIGNED``
  - per ``unsigned(x)`` zu ``UNSIGNED``
- ``UNSIGNED``
  - per ``to_integer(x)`` zu ``INTEGER``
  - per ``std_logic_vector(x)`` zu ``STD_LOGIC_VECTOR``
- ``INTEGER``
  - per ``to_unsigned(x,N)`` zu ``unsigned``
    - N ist dabei Wortbreite
  - per ``to_signed(x,N)`` zu ``SIGNED``
- ``SIGNED``
  - per ``to_integer(x)`` zu ``INTEGER``
  - per ``std_logic_vector(x)`` zu ``STD_LOGIC_VECTOR``

## Operatoren

### Logische Operatoren

- ``and`` $\rightarrow$ UND-Verknüpfung
- ``or`` $\rightarrow$ ODER-Verknüpfung
- ``nand`` $\rightarrow$ NICHT-UND-Verknüpfung
- ``nor`` $\rightarrow$ NICHT-ODER-Verknüpfung
- ``xor`` $\rightarrow$ EXKLUSIVES-ODER-Verknüpfung
- ``nor`` $\rightarrow$ Invertierung

- gelten für ``STD_LOGIC``, ``STD_LOGIC_VECTOR``, ``SIGNED`` und ``UNSIGNED``
- sind synthetisierbar

### Arithmetische Operatoren

- für numerische Datentypen, immer synthetisierbar:
  - ``+`` $\rightarrow$ Addition
  - ``-`` $\rightarrow$ Subtraktion
  - ``*`` $\rightarrow$ Multiplikation
  - ``abs`` $\rightarrow$ Absolutwert
- für numerische Datentypen, Synthese abhängig vom verwendeten Programm:
  - ``/`` $\rightarrow$ Division
  - ``mod`` $\rightarrow$ Qotient der Ganzzahldivision
  - ``rem`` $\rightarrow$ Rest der Ganzzahldivision
- für ``INTEGER``-Datentypen, nur für Konstanten synthetisierbar:
  ``**`` $\rightarrow$ Potenzierung

### Vergleichsoperatoren

- für beliebige Datentypen, Synthetisierbar
  - ``=`` $\rightarrow$ Gleich
  - ``/=`` $\rightarrow$ Ungleich
- für numerische Datentypen, Synthetisierbar
  - ``>`` $\rightarrow$ Größer
  - ``<`` $\rightarrow$ Kleiner
  - ``>=`` $\rightarrow$ Größer-gleich
  - ``<=`` $\rightarrow$ Kleiner-gleich

## Processes

- Prozesse in VHDL werden verwendet um Zustandsänderungen von Signalen zu erreichen
- um das Arbeiten mit Schleifen u.ä. zu ermöglichen, laufen Prozesse sequentiell ab
- nebenläufige Ausführung zu anderen Prozessen oder Signalzuweisungen: alle Prozesse laufen gleichzeitig (daher Implikationen für Signale)
- Prozesse sind immer aktiv und werden kontinuierlich ausgeführt
- werden in ``ARCHITECTURE``definiert
- laufen ab, wenn sich ein Signal in der Sensitivity List ändert, oder nach ``wait``-Statement: **nicht beides!**

**Beispiel:**

```vhdl
-- mit sensitivity-list

architecture architecture_name of entity_name is
begin
  optional_prozess_name : process (a,b,c) -- Ausführung bei Änderung der Signale a,b,c
  begin
    q <= (a and b) or c;
  end process;
end;

-- mit wait statement
architecture architecture_name of entity_name is
begin
  optional_prozess_name : process
  begin
    wait until a = `1`;
    q <= (a and b) or c;
  end process;
end;

```

## Signale

- Signale sind in VHDL die "Zustände der Leitungen" $\rightarrow$ Zwischenergebnisse
- sie werden innerhalb der Architecture deklariert (siehe Beispiel unten): **interne Signale**
- in der ``ENTITY`` beschriebene Ports stehen in der zugeordneten ``ARCHITECTURE`` als Signale zur Verfügung und müssen nicht neu deklariert werden: **externe Signale**

**Verwendung:**

```vhdl
-- Deklaration:
signal signal_name : signaltyp;

-- Deklaration mit Zuweisung:
signal signal_name : signaltyp := initialisationswert;

-- Lokales Signal in Architecture

architecture behave of entityName is
  signal s : bit := `0`;
begin
  q <= a and s;
end;

```

**Besonderheit:**

- VHDL arbeitet (meist) parallel, nicht sequenziell
- Problem bei der Verwendung von Signalen in (sequenziellen) Prozessen:
- bei Verwendung von Signalen innerhalb eines Prozesses werden diese nicht während der Prozesslaufzeit aktualisiert
  - es wird der Signalwert verwendet, der bei Prozessbeginn zur Verfügung steht
  - nur die letzte Zuweisung an das Signal wird bei Prozessende oder -unterbrechung tatsächlich geschrieben
  - Signale dürfen von beliebig viele Prozessen gelesen, aber in nur einem Prozess geschrieben werden

## Variablen

- können **NUR** in Prozessen verwendet werden
- existieren auch nur in demselben Prozess $\rightarrow$ nur lokal
- Deklaration nach ``process`` aber vor ``begin``
- Wertänderungen sind augenblicklich und können daher im Gegensatz zu Signalen für die sequenzielle Abarbeitung genutzt werden

**Beispiel:**

````vhdl
optional_prozess_name : process (a)
  -- Deklaration und Zuweisung mit :=
  variable variable_name : integer := 1;
begin
  variable_name := variable_name + 2;
  variable_name := variable_name + 4;
-- Wert von variable_name sollte jetzt 7 sein
  a <= variable_name;
end process;
````

## Port Maps

## Components

> entnommen aus: <http://www.informatik.uni-ulm.de/ni/Lehre/SS03/ProSemFPGA/VHDL-Grundlagen.pdf>

- Machen letzten Endes den Unterschied zwischen einen Strukturmodell und einem Verhaltensmodell aus

**Verhaltensmodell**

- keine externen Komponenten angegeben
- beschreibt einfach nur, wie sich eine Einheit verhält: welche Ausgangssignale aufgrund welcher Eingangssignale

Beispiel:

```vhdl
ENTITY halfAdder IS
  PORT (
    X, Y : IN Bit;
    SUM, COUT : OUT Bit);
END halfAdder;

ARCHITECTURE behavioural OF halfAdder IS
BEGIN
  SUM <= X XOR Y ;
  COUT <= X AND Y ;
END behavioural ;
```

**Strukturmodell**

- beschreibt ein Modell aus mehreren Komponenten und ihren Verbindungen untereinander
- jede Unterkomponente muss in der Architekturbeschreibung dazu vor der Verwendung bekannt gemacht werden (Schlüsselwort ``component``)

Beispiel:

```vhdl
ENTITY fullAdder IS
  PORT (
    X, Y, CIN : IN Bit;
    SUM, COUT : OUT Bit);
END fullAdder;

ARCHITECTURE structural OF fullAdder IS
  SIGNAL S1, S2, S3;
  COMPONENT halfAdder
    PORT (
      X, Y : IN Bit;
      SUM, COUT : OUT Bit);
  END COMPONENT;
BEGIN
  U1 : halfAdder  PORT MAP (X, Y, S1, S2);
  U2 : halfAdder  PORT MAP (S1, CIN, SUM, S3);
  COUT <= S2 OR S3;
END structural;
```

## Arrays

## if

## case

## ATTRIBUTE KEEP

## Testen mit VHDL

- VHDL bietet die Möglichkeiten, eine sogenannte **Testbench** zu erstellen
  - für ein zu testendes Design (DUT - design under test) wird ein dafür passender Stimulus programmiert
  - Der Stimulus generiert die Inputs, für die das Design getestet werden soll
  - die durch das DUT zurückgelieferten Outputs können auf ihre Richtigkeit getestet werden, und zwar durch:
    - Betrachten der Outputs des Simulations-Tools (Wellenform)
    - Programmieren eines Output-Checkers

## JTAG
