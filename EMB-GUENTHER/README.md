<!----------
title: "Embedded Systems II"
date: "Semester 5"
keywords: [Embedded Systems II, EMB, DHGE, Semester 5]
---------->

Embedded Systems II
===================

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Inhaltsverzeichnis**

- [Prüfungsleistung](#pr%C3%BCfungsleistung)
  - [Projekt](#projekt)
  - [Vortragsthemen](#vortragsthemen)
- [Buildroot](#buildroot)
- [QR-Code und Impfzertifikat](#qr-code-und-impfzertifikat)
  - [Grundlegender Aufbau](#grundlegender-aufbau)
  - [Impfzertifikat-Code](#impfzertifikat-code)
    - [Überprüfung](#%C3%9Cberpr%C3%BCfung)
- [Hardware des Raspberry Pi 4](#hardware-des-raspberry-pi-4)
  - [Komponenten](#komponenten)
    - [Peripherie](#peripherie)
- [QEMU](#qemu)
  - [Vorgehen](#vorgehen)
- [Konfigurationsmanagement mit Buildroot](#konfigurationsmanagement-mit-buildroot)
  - [Motivation](#motivation)
  - [Konfigurationsdateien](#konfigurationsdateien)
  - [Erstellen und Ändern](#erstellen-und-%C3%84ndern)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Prüfungsleistung

- Seminararbeit bzw. Teildokumentation + Kurzvortrag
- Bewertungskriterien:
  - Detaillierungsgrad (Nachvollziehbarkeit)
  - Umfang: 10 Seiten (A4, 11pt, Word)
- Vortrag: 30 min + 15 min Diskussion
- Demo: 13.10.21
- Abgabe Doku: 17.10.21
- optional: Image-Battle unter 15 MB
- Arbeit soll Ansprüchen wissenschaftlichen Arbeitens genügen
- Zusammenarbeit erwünscht

## Projekt

- Webcam
  - Webzugriff auf RPI Cam über Access-Point
- QR-Scanner für Impfzertifikate
  - QR-Code einlesen, auswerten und Aktion realisieren

## Vortragsthemen

- Raspberry Pi Hardware
- Buildroot / Image-Erzeugung
- Kernelkonfiguration
- Webserver / Motion (Stream-Software für Kamera)
- Konfigurationsmanagement
- WLAN<!--gemacht von Ben, -edict, Max-->
- DHCP

optional:

- QR-Code, digitales Impfzertifikat, Testbestätigung
- Servobetrieb für bewegliche Kamera
- QEMU-Simulation des Pi 4

# Buildroot

[https://buildroot.org/](https://buildroot.org/)

Buildroot ist ein Tool zum Bauen von Embedded Linux Images.

1. [buildroot herunterladen](https://buildroot.org/downloads/buildroot-2021.02.4.tar.gz) und entpacken
2. `make <board>_defconfig`, wobei \<board\> eine Konfiguration aus dem `boards`-Ordner ist
3. `make menuconfig` öffnet eine TUI zur Konfigurationsanpassung (`WSL2` braucht eventuell `apt install libncurses-dev`)
4. eigene Dateien können via Overlay-Ordner im Board-Verzeichnis abgelegt werden
5. `make` baut das Image
6. Image auf SD-Karte kopieren: `sudo dd if=output/images/sdcard.img of=/dev/sdX`

# QR-Code und Impfzertifikat

- steht für "Quick Response"
- 2D-Matrix aus schwarzen und weißen Quadraten, in denen Zeichen codiert sind
- Weiterentwicklung des Barcodes $\rightarrow$ wesentlich höhere Zeichenmenge möglich

## Grundlegender Aufbau

- aufgeteilt in Ruhezone und Datenbereich
- Ruhezone trennt Code von Umgebung, hilft bei Bildverzerrung, zeigt Ausrichtung an
- Synchronisationscode zur Größenbestimmung durch abwechselnde schwarze und weiße Zellen zwischen Positionsmarkern
- Formatinformationen über Datenmaske und Prüfbits für diese (XOR)
- verschiedene Versionen für verschiedene Größen (21x21 bis 177x177)
- verschiedene Encoding-Modes für numerisch, alphanumerisch, End of Message
  - Datenstream: Mode, Bitstream, EOM

## Impfzertifikat-Code

- ``base45``-codiert in QR-Code
- decodiert: signiertes JSON

### Überprüfung

- App lädt [öffentliche Schlüssel](https://github.com/HQJaTu/vacdec/blob/main/certs/roots/Digital_Green_Certificate_Signing_Keys.json) zum Entschlüsseln der Signatur
- Signatur wird auf Gültigkeit geprüft
- Details zum Signaturverfahren: [Krypto Semester 4](https://github.com/importPI19fromDHGE/dhge-pi19-sem4/tree/main/SWS-KUSCHE#hashes--signatur)

# Hardware des Raspberry Pi 4

- Motivation: günstiger + einfacher Computer zur Steigerung des Interesse an Computertechnik und Programmierung
- flexibler Einsatz: Radio- / Funkmodule, Roboter, NAS- und Server-Betrieb, Anlagen-Steuerung, Prozessüberwachung, u.v.m.
- gängige Betriebssysteme: Raspberry Pi OS, KODI/OSMC, Ubuntu Core / Server, Retro Pie / Lakka Linux

## Komponenten

- Broadcom SoC mit ARM Cortex A-72 64-Bit CPU mit 4 Kernen und bis zu 1,5GHz
  - = energiesparende RISC-CPU $\rightarrow$ gut geeignet für Embedded Systems
- GPU mit bis zu 500MHz, OpenGL-Support
- LP-DDR4-SDRAM (je nach Modell des Pi 4: 1 bis 8 GB)
  - ``LP``: Low Power; 1,1V
- Interfaces:
  - 2x miniHDMI
  - Klinkenausgang
  - Ethernet mit bis zu 300Mbit/s
  - Dual-Band WiFi
  - Bluetooth 5.0
  - 2x USB 2.0
  - 2x USB 3.0
  - microSD-Karte
  - 40 Pins (davon 26 GPIO)
  - Display Serial Interface (DSI)
  - Camera Serial Interface (CSI)
  - 5,1V 3A USB-C Input

### Peripherie

- pHats: **H**ardware **A**ttached on **T**op
  - Komponenten benötigen EEPROM mit Hardware-Informationen
  - z.B.: Coaxial-Adapter, Servomotoren, PoE, u.v.m.
- PiCamera
  - über CSI angeschlossen
  - verschiedene Generationen, 5MP bis 12,3MP
- Touch-Bildschirme via DSI angeschlossen

# QEMU

- nutzt ``Kernel Virtual Machine`` (KVM) von Linux
- simuliert x86, ARM, u.v.m.
- Emulation fremder Architekturen jedoch langsam
- Emulation Raspberry Pi 3 mit ``qemu-system-aarch64`` mit ``-M type=raspi2`` oder ``-M type=raspi3``
- kein RaspberryPiOS mit 64bit Kernel vorhanden

## Vorgehen

- Repo auschecken
- erweitern des RaspberryPiOS-Image um 4 GiB mit ``dd``
- einhängen des Images mit ``losetuo -f -P --show``
- vergrößern der 2. Partition auf Image-Grenze
- mounten des Images mit Schreibzugriff

# Konfigurationsmanagement mit Buildroot

## Motivation

- Optimale OS-Anpassung an gewünschten Zweck
  - weglassen unnötiger Komponenten
  - höhere Geschwindigkeit<!--MEHR ENEGIE!-->

## Konfigurationsdateien

- in der ``.config``-Datei ist die gesamte Buildroot-Konfiguration für das Image gespeichert
- ``defconfig``-Dateien sind kleinere Dteien, die alle Änderungen zur Standardkonfiguration enthalten

## Erstellen und Ändern

- ``make raspberrypi4_defconfig`` erstellt Standardkonfiguration für Pi 4
- ``make config``: textbasierte Konfiguration
- ``make menuconfig``: TUI
- ``make gconfig``: GTK-GUI
- ``make xconfig``: QT-GUI
- Overlay spezifizieren: Option ``Root filesystem overlay directories`` im Menü ``System configuration``
