# LKF PLD

## Skizzieren Sie, wie üblicherweise zweistufig Boole’sche Terme in Programmierbaren Logikbausteinen implementiert werden.

Disjunktive Normalform:

1. Stufe: UND-Verknüpfungen (Konjunktionen)
2. Stufe: ODER-Verknüpfungen (Disjunktionen)

## Welche Möglichkeiten kennen Sie, um die Funktionalität von Programmierbaren Logikbausteinen zu spezifizieren?

- Art der Programmierung / Interner Aufbau?
- Technische Kennzahlen (Makrozellen, Taktfrequenz, I/Os)

## Wie unterscheiden sich ASIC / ASSP / FPGA in der Anwendung?

- 2 Bilder einfügen TODO

## Wie unterscheiden sich Programmierbare Logikbausteine von Mikroprozessoren?

Gemeinsamkeit: EVA

Unterschiede:

| Mikroprozessor                | Programmierbare Logikbausteine        |
| ----------------------------- | ------------------------------------- |
| Sequenzielle Verarbeitung     | Parallele Verarbeitung                |
| Eher langsam                  | Eher schnell                          |
| Günstig	                    | Teuer                                 |
| Allgemeine Funktion           | Spezialisierte Funktion               |

##	Welche Arten von Speicher sind in einem FPGA integriert? Beschreiben Sie kurz deren Eigenschaften.

- SDRAM (**S**ynchronous **D**ynamic **R**andom **A**ccess **M**emory)
  - flüchtig
  - Synchronous DRAM (Kondensator)
  - Die Lese- und Schreibzugriffe des Speichers sind mit dem Systemtakt des Rechners synchronisiert
  - Üblicher DRAM seit 2000 SDRAM

- SRAM (**S**tatic **R**andom **A**ccess **M**emory)
  - Flüchtiger Speicher: Strom aus, Inhalt weg
  - 6 Transistoren, kein Refresh nötig (Vgl. DRAM)

- Flash-EEPROM
  - Sog. Flash-Speicher
  - Nicht-flüchtig
  - „Electronically Erasable Read only memory”

##	Über welche Schnittstelle wird ein FPGA in der Schaltung programmiert? Beschreiben Sie kurz die Funktion dieser Schnittstelle.

JTAG

- Serieller Bus
- Zu testende ICs werden hintereinandergeschaltet (JTAG-Chain)

## Schildern Sie das übliche Vorgehen beim Entwurf von Schaltungen mit VHDL. (Testbench) Wozu dienen Stimuli?

Daher wird beim Entwurf normalerweise zu jedem Modul eine Testbench erstellt. Mit dieser soll sich die Funktionalität des Modules vor der Synthese mittels Simulation prüfen lassen. Die Testbench generiert alle Eingangssignale, auch Testvektoren oder Stimuli genannt, für das zu testende Modul (device under test) und prüft ggf. die Resultate

## Sind alle VHDL-Anweisungen für die Verwendung in einer zu synthetisierenden Schaltung geeignet? Wenn ja, warum? Wenn nein, warum nicht?

Keine Ahnung
[zustandsgesteuerte FlipFlops]

## Geben Sie die grafische Darstellung der Programmierung der folgenden Gleichung in einem PLA an…(Antwort: Bild der UND-Matrix).

UND-Matrix malen, Punkte verbinden

- TODO Bild

## Was meint der Begriff „Programmierbare Logik“?

a) Die Bausteine können Programme ausführen, die in Sprachen wie C oder Java geschrieben sind.
b) ASICs, die einen softwareprogrammierbaren Mikroprozessor beinhalten.
c) Die logische Funktion der Hardware des Bausteins kann durch den Anwender programmiert werden.
d) Logische Funktionen, die mithilfe eines Programms auf einem PC simuliert werden. (Begründen Sie Ihre Aussage.)

<!-- md2apkg split -->

Richtige Antwort ist TODO, denn TODO

## Signale in Prozessen. Wann werden die Zuweisungen wirksam? (Am Beispiel eines Code-Schnipsels, ähnlich wie in Vorlesung).

Signale in Prozessen werden immer erst ganz am Ende des Prozesses wirksam.

- TODO Bild

## Wie verhalten sich die Zuweisungen bei Variablen? Wann/wo können Variablen verwendet werden?

Variablen können nur in Prozessen verwendet werden. Im Gegensatz zu Signalen werden Sie jedoch direkt bei der Zuweisung aktualisiert und können verwendet werden.

## Allgemeine Fragen zu VHDL, beispielsweise als richtig/falsch formuliert:

### In VHDL wird Groß- und Kleinschreibung nicht unterschieden: MY_SIG und my_sig bezeichnen das gleiche Signal. (R/F)

Richtig

### Anhand der Entity einer VHDL-Beschreibung können die Ein- und Ausgänge eines Moduls identifiziert werden. (R/F)

Richtig

### Signale vom Datentyp std_logic können nur die Werte ‚0‘, ‚1‘ und ‚U‘ annehmen. (R/F)

Falsch --> Falsch (U,X,0,1,...)

### Im Deklarationsteil einer Architecture (= vor begin) können sowohl Signale als auch Variablen definiert werden. (R/F)

Falsch, Signale ja, Variablen nein

### Numerische Konstanten können nicht in hexadezimaler Darstellung angegeben werden. (R/F) --> Falsch

## VHDL: Machen Sie aus einer if-Anweisung eine case-Anweisung (oder umgekehrt).

´´´VHDL
if Expression_1 then
Output_signal <= Value1;
elsif Expression_2 then
Output_signal <= Value2;
else Expression_3 then
Output_signal <= Value3;
end if;
´´´

<!-- md2apkg split -->

´´´txt
case control_expression is
when option_1 =>output_signal <= value_1;
When option_2 => output_signal <= value_2;
When others => output_signal <= value_3;
end case;
´´´

## Entity - Architecture

### Geben Sie zu einer Architecture die passende Entity Deklaration an.

´´´VHDL
ENTITY aoi4 IS
PORT(
        a : IN std_logic;
        b : IN std_logic;
        c : IN std_logic;
        d : IN std_logic;
        z : OUT std_logic);
END ENTITY aoi4;
´´´

<!-- md2apkg split -->

´´´VHDL
ARCHITECTURE data_flow OF aoi4 IS
 SIGNAL temp1, temp2 : std_logic;

 BEGIN
       temp1 <= a AND b;
       temp2 <= c AND d;
       z <= temp1 NOR temp2;
END ARCHITECTURE data_flow;
´´´

### Geben Sie die notwendigen Schritte an, um aus einer Architecture die passende Entity Deklaration anzugeben.

1. Entity-Namen aus der Architecture entnehmen
2. Betrachten, wie mit den Werten in der Entity gearbeitet wird
  a. Signale für Entity nicht von Belang
  b. nicht deklarierte Bezeichner müssen also aus der Entity kommen
  c. Bezeichner, die auf Signale zuweisen -> müssen IN-Ports sein, Typ feststellen
  d. Bezeichner, auf die zugewiesen wird --> Out-Port, Typ feststellen.



