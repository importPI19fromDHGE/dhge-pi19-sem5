## Skizzieren Sie, wie üblicherweise zweistufig Boole’sche Terme in Programmierbaren Logikbausteinen implementiert werden.

Disjunktive Normalform:

1.  Stufe: UND-Verknüpfungen (Konjunktionen)
2.  Stufe: ODER-Verknüpfungen (Disjunktionen)

## Welche Möglichkeiten kennen Sie, um die Funktionalität von Programmierbaren Logikbausteinen zu spezifizieren?

-  Art der Programmierung / Interner Aufbau?
-  Technische Kennzahlen (Makrozellen, Taktfrequenz, I/Os)

## Wie unterscheiden sich ASIC / ASSP / FPGA in der Anwendung?

- 2 Bilder einfügen TODO


## Wie unterscheiden sich Programmierbare Logikbausteine von Mikroprozessoren?

- Tabelle TODO

Gemeinsamkeit:
EVA

Unterschiede:
MP: Sequenzielle Verarbeitung				PLD: Parallele Verarbeitung
Eher langsam						Eher schnell
Günstig							Teuer
Allgemeine Funktion					Spezialisierte Funktion

##	Welche Arten von Speicher sind in einem FPGA integriert? Beschreiben Sie kurz deren Eigenschaften.
-	SDRAM
o	flüchtig
o	Synchronous DRAM (Kondensator)
o	Die Lese- und Schreibzugriffe des Speichers sind mit dem Systemtakt des Rechners synchronisiert
o	Üblicher DRAM seit 2000 SDRAM

-	SRAM
o	Flüchtiger Speicher: Strom aus, Inhalt weg
o	6 Transistoren, kein Refresh nötig (Vgl. DRAM)

-	Flash-EEPROM
o	Sog. Flash-Speicher
o	Nicht-flüchtig
o	„Electronically Erasable Read only memory”
6.	Über welche Schnittstelle wird ein FPGA in der Schaltung programmiert? Beschreiben Sie kurz die Funktion dieser Schnittstelle.
JTAG:
-	Serieller Bus
-	Zu testende ICs werden hintereinandergeschaltet (JTAG-Chain)

## Schildern Sie das übliche Vorgehen beim Entwurf von Schaltungen mit VHDL. (Testbench) Wozu dienen Stimuli?
Daher wird beim Entwurf normalerweise zu jedem Modul eine Testbench erstellt. Mit dieser soll sich die Funktionalität des Modules vor der Synthese mittels Simulation prüfen lassen. Die Testbench generiert alle Eingangssignale, auch Testvektoren oder Stimuli genannt, für das zu testende Modul (device under test) und prüft ggf. die Resultate

## Sind alle VHDL-Anweisungen für die Verwendung in einer zu synthetisierenden Schaltung geeignet? Wenn ja, warum? Wenn nein, warum nicht?

Keine Ahnung
[zustandsgesteuerte FlipFlops]

## Geben Sie die grafische Darstellung der Programmierung der folgenden Gleichung in einem PLA an…(Antwort: Bild der UND-Matrix).
	UND-Matrix malen, Punkte verbinden


## Was meint der Begriff „Programmierbare Logik“?
a) Die Bausteine können Programme ausführen, die in Sprachen wie C oder Java geschrieben sind.
b) ASICs, die einen softwareprogrammierbaren Mikroprozessor beinhalten.
c) Die logische Funktion der Hardware des Bausteins kann durch den Anwender programmiert werden.
d) Logische Funktionen, die mithilfe eines Programms auf einem PC simuliert werden. (Begründen Sie Ihre Aussage.)

## Signale in Prozessen. Wann werden die Zuweisungen wirksam? (Am Beispiel eines Code-Schnipsels, ähnlich wie in Vorlesung).
Signale in Prozessen werden immer erst ganz am Ende des Prozesses wirksam.

## Wie verhalten sich die Zuweisungen bei Variablen? Wann/wo können Variablen verwendet werden?
Variablen können nur in Prozessen verwendet werden, werden im Gegensatz zu Signalen jedoch direkt bei der Zuweisung aktualisiert und können verwendet werden.

## Allgemeine Fragen zu VHDL, beispielsweise als richtig/falsch formuliert:

In VHDL wird Groß- und Kleinschreibung nicht unterschieden: MY_SIG und my_sig bezeichnen das gleiche Signal. --> Richtig
Anhand der Entity einer VHDL-Beschreibung können die Ein- und Ausgänge eines Moduls identifiziert werden. --> Richtig
Signale vom Datentyp std_logic können nur die Werte ‚0‘, ‚1‘ und ‚U‘ annehmen. --> Falsch --> Falsch (U,X,0,1,...)
Im Deklarationsteil einer Architecture (= vor begin) können sowohl Signale als auch Variablen definiert werden. --> Falsch, Signale ja, Variablen nein
Numerische Konstanten können nicht in hexadezimaler Darstellung angegeben werden. --> Falsch

## VHDL: Machen Sie aus einer if-Anweisung eine case-Anweisung (oder umgekehrt).
if Expression_1 then
Output_signal <= Value1;
elsif Expression_2 then
Output_signal <= Value2;
else Expression_3 then
Output_signal <= Value3;
end if;

case control_expression is
when option_1 =>output_signal <= value_1;
When option_2 => output_signal <= value_2;
When others => output_signal <= value_3;
end case;

## Geben Sie zu einer Architecture die passende Entity Deklaration an.
ENTITY aoi4 IS
PORT(
 	    a : IN std_logic;
 	b : IN std_logic;
      c : IN std_logic;
      d : IN std_logic;
      z : OUT std_logic);
END ENTITY aoi4;

ARCHITECTURE data_flow OF aoi4 IS
 SIGNAL temp1, temp2 : std_logic;

 BEGIN
 	temp1 <= a AND b;
	      temp2 <= c AND d;
 	 z <= temp1 NOR temp2;

END ARCHITECTURE data_flow;

Schritte:
1.	Entity-Namen aus der Architecture entnehmen (hier: aoi4)
2.	Betrachten, wie mit den Werten in der Entity gearbeitet wird
a.	temp1, temp 2 sind hier Signale, also für Entity nicht von Belang
b.	a,b,c,d, und z werden hier nicht deklariert, müssen also aus der Entity kommen
c.	Aus a,b,c und d wird auf die beiden Signale zugewiesen --> müssen also IN-Ports sein und da temp1 und temp2 vom Typ std_logic sind, dementsprechend selber Typ
d.	Auf z wird hier zugewiesen und steht auch am Ende --> Out-Port mit Typ std_logic



