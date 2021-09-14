<!----------
title: "Rechnernetzadministration/Verteilte Systeme"
date: "Semester 5"
keywords: [Rechnernetzadministration, Verteilte Systeme, NET, DHGE, Semester 5]
---------->

Rechnernetzadministration/Verteilte Systeme
===========================================

<!-- md2apkg ignore-card -->

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Inhaltsverzeichnis**

- [Literaturempfehlung](#literaturempfehlung)
- [Einleitung](#einleitung)
  - [Designziele](#designziele)
  - [Wiederholung Grundlagen](#wiederholung-grundlagen)
    - [Netzwerk](#netzwerk)
    - [Klassifizierung von Datennetzen](#klassifizierung-von-datennetzen)
      - [Räumliche Ausdehnung](#r%C3%A4umliche-ausdehnung)
      - [Größe/Anzahl der Teilnehmer](#gr%C3%B6%C3%9Feanzahl-der-teilnehmer)
      - [Hardware-Sicht](#hardware-sicht)
      - [Logische Sicht](#logische-sicht)
        - [ISO/OSI und TCP/IP](#isoosi-und-tcpip)
      - [Topologie-/Struktursicht](#topologie-struktursicht)
      - [Logische Struktur](#logische-struktur)
    - [Einschub: Frames/Sicherungsschicht](#einschub-framessicherungsschicht)
    - [Paketkollision](#paketkollision)
    - [Einschub: Geräte](#einschub-ger%C3%A4te)
    - [Topologien auf der logischen Ebene](#topologien-auf-der-logischen-ebene)
      - [flache Topologie](#flache-topologie)
      - [standortbasiert](#standortbasiert)
      - [funktionsgruppenbasierte Topologie](#funktionsgruppenbasierte-topologie)
      - [Overlay-Netzwerke](#overlay-netzwerke)
      - [VLAN](#vlan)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Literaturempfehlung

<!-- md2apkg ignore-card -->

- Saida Helali: Systems and Network Infrastructure Integration
- J. Scott Marcus: Designing Wide Area Networks and Internetworks
- Jeff Bollinger: Crafting the InfoSec Playbook
- Tanenbaum: Computer Networks
- Douglas R. Mauro: Essential SNMP
- Thomas A. Limoncelli: The Practice of System and Network Administration

# Einleitung

## Designziele

- **Funktional:** Erfüllung der Anforderungen im Lastenheft $\rightarrow$ Benutzer können ihre Arbeit unter optimalen Bedingungen erfüllen
- **Ausbaufähig:** Wachstum muss möglich sein
- **Wartbarkeit:** von der Entwurfsphase an muss einfache Wartung/Betrieb eingeplant werden $\rightarrow$ Doku
- **Adaptivität:** Anpassung an neue Technologien

## Wiederholung Grundlagen

### Netzwerk

- besteht aus Hard- und Software
- durch kabelgebundene und/oder drahtlose Übertragungssysteme verbunden
- zur Übertragung/Verarbeitung von Informationen
- digitale Datennetze (es sollen keine Rundfunknetze und Telefonnetze behandelt werden) \rightarrow\rightarrow NGN (Next Generation Networking)

### Klassifizierung von Datennetzen

- Topologien/Strukturen
- Größe/Leistungsfähigkeit (Anzahl Clients)
- Übertragungmedium
- Anwendungsbereich: Protokollebene (Heterogen/Homogen)
- Hard-/Software
- Räumliche Ausdehnung (LAN, WAN, etc.)
- Betriebsmodus (Client-Server, Peer-to-Peer)

#### Räumliche Ausdehnung

- **PAN:** Personal Area Network, Reichweite *1m-10m* (bspw. Bluetooth)
- **LAN:** Local Area Network, Reichweite *10m-1km*
- **MAN:** Metropolitan Area Network, Reichweite *1-100km*
- **WAN:** Wide Area Network
- **GAN:** Global Area Network

#### Größe/Anzahl der Teilnehmer

- klein: ~200 Teilnehmer
- mittel: ~1000..2000 Teilnehmer
- groß: >2000 Teilnehmer

#### Hardware-Sicht

- Endgeräte (PC, Handy, Telefon, Server, Drucker, IoT, Management-Stationen)
- Kopplungsgeräte (Switch, Firewall, Repeater, Router, Bridge, Hub, Modem, Access-Point)
- Übertragungsmedien (Kabel, Funk)

#### Logische Sicht

##### ISO/OSI und TCP/IP

| Schicht                | Funktion                                                     | Protokolle | TCP/IP                          |
| ---------------------- | ------------------------------------------------------------ | ---------- | ------------------------------- |
| Anwendungsschicht      | Kommunikation zw. Anwendungen                                | NFS, DNS,  | Anwendungungsschicht            |
| Darstellungsschicht    | Transformation zw. Datenformaten, Verschlüsselung            | DHCP, HTTP | Anwendungungsschicht            |
| Sitzungsschicht        | Dialogsteuerung, Synchronisation                             | FTP, ...   | Anwendungungsschicht            |
| Transportschicht       | Ende-zu-Ende-Kommunikation zw. Prozessen                     | TCP, UDP   | Transportschicht                |
| Vermittlungsschicht    | Wegewahl Sender -> Empfänger, Kopplung heterogener Teilnetze | IP         | Internetschicht                 |
| Sicherungsschicht      | Behandlung von Übertragungsfehlern                           | Ethernet   | Netzzugangsschicht (Link Layer) |
| Bitübertragungsschicht | physikalische Ebene -> Übertragung von Signalen              |            | Netzzugangsschicht (Link Layer) |

#### Topologie-/Struktursicht

- ~~**Bus**~~ (in LV nicht betrachtet)
- **Stern** (Switch verbunden zu Host 1..n; Routerverbunden zu  Switch 1..n)
  - *nicht nur in Geräten denken, sondern allgemein in Strukturen*
  - Vorteil: schöne Struktur (leicht verständlich, wartbar), kostengünstig
  - Problem: Zentrale (Router, Switch) ist SPOF
- Lösung Redundanz: Stern aufbrechen $\rightarrow$ mehrere kleinere Sterne, redundant verbunden
  - $\rightarrow$ SPOF nicht mehr katastrophal, weniger Langstreckenverkehr
- **Ring:** weitere Redundanzen durch ringförmige Verbindungen der Zentralen (früher bereits leitungsvermittelt: SoNET/SDH $\rightarrow$ Telekom)
  - jede Einheit ist mit zwei anderen verbunden
    - Vorteil: einzelne Verbindung kann ausfallen, Kommunikation weiterhin möglich
    - Nachteil: hohe Kosten, schwerer wartbar (Strukturänderungen)
- **Mesh:** Verknüpfung von Ringen und Sternen (Teilvermascht)

#### Logische Struktur

- logische Struktur kann nicht in Übereinstimmung mit der physischen Struktur entworfen werden
- wird beeinflusst von Unternehmensstruktur, Zugang zu Diensten, Verzeichnisdienst
- z.B. flaches L2-Netz: eine Broadcast-Domäne, kein Router
  - Overlay: logische Struktur über physikalischen Netz $\rightarrow$ **VLAN** (IEEE 802.1q)

### Einschub: Frames/Sicherungsschicht
- Bereitstellung einer wohldefinierten Schnittstelle zur Vermittlungsschicht
- Umgang mit Übertragungsfehlern
- Regulierung des Datenflusses (Flow-Control)
- zur Erfüllung dieser Aufgaben: Bildung von Frames/Rahmen
  - | Header | Payload | Trailer |
  - Header und Trailer werden von der Sicherungsschicht hinzugefügt
  - Payload Daten kommen von der Vermittlungsschicht
  - Header: Verwaltungsinformationen
  - Trailer: Prüfsumme
  - Frames unterscheiden sich von System zu System

### Paketkollision

- zwei Teilnehmer senden zur gleichen Zeit Frames über ein geteiltes Medium (bspw. Bus oder Funk (bei gleicher Frequenz))
- Verhinderung mithilfe von CSMA/CD (Carrier Sense Multiple Access/Collision Detection) oder anderen Multiplex-Verfahren
- Collision-Domain $\rightarrow$ Bereich, in dem Kollisionen auftreten können
  - solche Domains sollten klein sein
  - keine Busse bauen
- Switches sollten duplex sein (heute eigentlich immer der Fall)

### Einschub: Geräte

| Schicht                | Gerät                                    |
| ---------------------- | ---------------------------------------- |
| Anwendungsschicht      | Application-Gateway                      |
| Darstellungsschicht    |                                          |
| Sitzungsschicht        |                                          |
| Transportschicht       | Transport-Gateway                        |
| Vermittlungsschicht    | L3-Switch, Router                        |
| Sicherungsschicht      | Switch                                   |
| Bitübertragungsschicht | Kabel, Repeater, Kopplungselemente (Hub) |

- **Firewall:**
  - traditionell auf L3, bei Deep-Packet-Inspection etc. heute jedoch auch auf anderen Ebenen
  - besteht aus: | Router | Application Layer Gateway | Router
- **Repeater:**
  - analoges Gerät, arbeitet mit Signalen auf Kabeln/Funkstrecke
  - empfängt, bereinigt, verstärkt, sendet Signale
  - i.d.R. Anzahl an Repeatern und Kabellänge ist durch die maximal "erlaubte" Latenz begrenzt
- **Hub:** <!-- dicker Lötklecks :D -->
  - verbindet Leitungen elektrisch
  - an den Hub angeschlossene Geräte sind Mitglieder der gleichen Kollisionsdomain
  - alle Teilnehmer müssen mit der gleichen Geschwindigkeit angebunden sein
- **Bridge:**
  - verbindet zwei/mehrere LANs miteinander (bspw. WLAN mit kabelgebundenem LAN $\rightarrow$ Accesspoint)
  - Entkopplung von Kollisionsdomänen
  - Frames werden nur an Ports gesendet, für deren angeschlossene Teilenehmer die Frames relevant sind
  - gleichzeitig ankommende Frames werden gepuffert
    - Kollisionsvermeidung
    - Geschwindigkeitsanpassung
  - Kopplung von LANs mit verschiedenen Protokollen
  - Problem: z.B. Dienstgüte, Verschlüsselung verschieden
- **Switch:**
  - ist eine Bridge mit anderem Namen
  - mit zusätzlicher Point-to-Point Anbindung der Teilnehmer
- **Router:**
  - wirft Header und Trailer weg und kümmert sich lediglich um den Payload
  - L2-Payload wird an die Routing Software übergeben
  - Routing-Software wählt Ausgangsport aus
- **Transport-Gateway:**
  - Umsetzung zwischen verschiedenen Protokollen auf der Transportebene
- **Application(-Level)-Gateway**
  - Umsetzung zwischen verschiedenen Protokollen auf der Anwendungsschicht
  - bspw.: SIP $\leftrightarrow$ H.323, E-Mail $\leftrightarrow$ SMS

### Topologien auf der logischen Ebene

#### flache Topologie

  - **HIER BILD EINFÜGEN:** PC1, PC2 und PC3 sind mit Switch1 verbunden
  - flache Topologie
  - großes Netzwerk aller Layer2 Geräte
  - Switch ist SPOF
  - kein Routing
  - eine Broadcast-Domain
  - ein Subnetz
  - Dienste (Datei-/Druck-/Namensauflösungs-/Email-/Dienste) werden in diesem Netz bereitgestellt

#### standortbasiert

  - **HIER BILD EINFÜGEN:**
  - Schicht-2-Netzwerke basierend auf dem Standort
  - L3-Geräte, um die L2-Netze zu verbinden
  - jedes Stockwerk/L2-Netz hat einen eigenen L3-Adressblock

#### funktionsgruppenbasierte Topologie

  - **HIER BILD EINFÜGEN:**
  - Mitglieder einer Funktionsgruppe (= Abteilung) in jeweils eigenem L2-Netz (Gruppennetzwerke)
  - Dienste teils auf Gruppen-Ebene (Anmeldung, Dateien, ...
  - andere Dienste(bspw. E-Mail/Internet) zentral
  - teils hierarchische Struktur der Dienste (bspw. Anmelde-Server)

#### Overlay-Netzwerke

- Entkopplung der physischen von der logischen Struktur
- logische Struktur, die auf der physischen aufbaut
- VLAN, VPN(, Framerelay, ATM)

#### VLAN

- virtuelle LANs schaffen, die in Software konfiguriert werden können
- 