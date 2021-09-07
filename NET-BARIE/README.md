<!----------
title: "Rechnernetzadministration/Verteilte Systeme"
date: "Semester 5"
keywords: [Rechnernetzadministration, Verteilte Systeme, NET, DHGE, Semester 5]
---------->

Rechnernetzadministration/Verteilte Systeme
===========================================

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Inhaltsverzeichnis**

- [Einleitung / Designziele](#einleitung--designziele)
  - [Designziele](#designziele)
  - [Wiederholung Grundlagen](#wiederholung-grundlagen)
    - [Netzwerk](#netzwerk)
    - [Klassifizierung von Datennetzen](#klassifizierung-von-datennetzen)
      - [räumliche Ausdehnung](#r%C3%A4umliche-ausdehnung)
      - [Größe (Anzahl der Teilnehmer)](#gr%C3%B6%C3%9Fe-anzahl-der-teilnehmer)
      - [Hardware-Sicht](#hardware-sicht)
      - [logische Sicht](#logische-sicht)
        - [ISO / OSI](#iso--osi)
      - [Topologie- / Struktursicht](#topologie---struktursicht)
        - [Stern](#stern)
        - [mehrere kleine Sterne -> Redundanz](#mehrere-kleine-sterne---redundanz)
        - [Ring](#ring)
        - [Mesh](#mesh)
      - [logische Struktur](#logische-struktur)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Einleitung / Designziele

## Designziele

- Funktional: Erfüllung der Anforderungen im Lastenheft -> Benutzer können ihre Arbeit unter optimalen Bedingungen erfüllen
- Ausbaufähigkeit: Wachstum muss möglich sein
- Wartbarkeit: von Entwurfsphase an muss einfache Wartung / Betrieb eingeplant werden -> **DOKU**
- Adaptivität: Anpassung an neue Technologien

## Wiederholung Grundlagen

### Netzwerk

- besteht aus: Hardware, Software
- durch kabelgebundene und / oder drahtlose Übertragungssysteme verbunden
- zur Übertragung / Verarbeitung von Informationen
- digitale Datennetzte (es sollen keine Rundfunknetze und Telefonnetze behandelt werden)
- -> NGN (Next Generation Network)

### Klassifizierung von Datennetzen

- Topologien / Strukturen
- Größe / Leistungsfähigkeit (Anzahl der Clients)
- Übertragungsmedium
- Anwendungsbereich
- Protokolle (heterogen / homogen)
- Hardware / Software
- räumliche Ausdehnung (LAN, WAN etc.)
- Betriebsmodus (Peer-to-peer oder Client-Server)

#### räumliche Ausdehnung

- PAN: personal area network, Reichweite 1-10m (bspw. Bluetooth)
- LAN: local area network, Reichweite 10-1000m
- MAN: metropolitan area network, Reichweite 1-100km
- WAN: wide area network
- GAN: global area network

#### Größe (Anzahl der Teilnehmer)

- klein: bis ca. 200 Teilnehmer
- mittel: bis ca. 1000-2000 Teilnehmer
- groß: über 2000 Teilnehmer

#### Hardware-Sicht

- Endgeräte (PC, Telefon, Server, ioT, Drucker, Management-Stationen)
- Kopplungsgeräte (Switches, Firewall, Router, Repeater, Bridges, Hub, Modem, Accesspoint)
- Übertragungsmedien (Funk, Kabel)

#### logische Sicht

##### ISO / OSI

- siehe [Semester 3](https://github.com/importPI19fromDHGE/dhge-pi19-sem3/tree/main/NET-FELDMANN)

#### Topologie- / Struktursicht

##### Stern

- siehe Zeichnung in OneNote
- nicht nur Geräten denken, sondern allgemein in Strukturen
- Problem: Zentrale ist SPOF
- Vorteil: schöne Struktur, leicht verständlich, leicht wartbar, kostengünstig

##### mehrere kleine Sterne -> Redundanz

- siehe Zeichnung in OneNote
- Vorteil: SPOF nicht mehr katastrophal, weniger Langstreckenverkehr

##### Ring

- siehe Zeichnung in OneNote
- früher bereits leitungsvermittelt: Sonet/SDH (Telekom)
- jede Einheit ist mit zwei anderen verbunden
- Vorteil: eine einzelne Verbindung kann ausfallen, Kommunikation ist trotzdem noch möglich
- Nachteile: teurer, schwerer wartbar (besonders bei Strukturänderungen)

##### Mesh

- siehe Zeichnung in OneNote

#### logische Struktur

- logische Struktur kann nicht in vollständiger Übereinstimmung mit der physikalischen Struktur entworfen werden
- wird beeinflusst von
  - Unternehmensstruktur
  - Zugang zu Daten
  - Verzeichnisdienst
- einfachster Fall: flaches L2 Netzwerk: 1 Broadcast-Domain, kein Router
- Overlay : logische Struktur über das physische Netz -> VLAN (IEEE 802.1q)