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
