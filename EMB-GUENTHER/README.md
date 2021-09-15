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

- [Embedded Systems II](#embedded-systems-ii)
- [Prüfungsleistung](#prüfungsleistung)
  - [Projekt](#projekt)
  - [Vortragsthemen](#vortragsthemen)
- [Buildroot](#buildroot)
- [QR-Code und Impfzertifikat](#qr-code-und-impfzertifikat)
  - [Grundlegender Aufbau](#grundlegender-aufbau)
  - [Impfzertifikat-Code](#impfzertifikat-code)
    - [Überprüfung](#überprüfung)

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
2. `make <board>`, wobei \<board\> eine Konfiguration aus dem `boards`-Ordner ist (`WSL2` braucht eventuell `apt install libncurses-dev`)
3. `make menuconfig` öffnet eine TUI zur Konfigurationsanpassung
4. eigene Dateien können via Overlay-Ordner im Board-Verzeichnis abgelegt werden
5. `make` baut das Image
6. Image auf SD-Karte kopieren: `sudo dd if=output/images/sdcard.img of=/dev/sdX`

# QR-Code und Impfzertifikat

- steht für "Quick Response"
- 2D-Matrix aus schwarzen und weißen Quadraten, in denen Zeichen codiert sind
- Weiterentwicklung des Barcodes
- wesentlich höhere Zeichenmengen als im Barcode möglich

## Grundlegender Aufbau

- aufgeteilt in Ruhezone und Datenbereich
- Ruhezone trennt Code von Umgebung, hilft bei Bildverzerrung, zeigt Ausrichtung an
- Synchronisationscode zur Größenbestimmung durch abwechselnd schwarze und weiße Zellen zwischen Positionsmarkern
- Formatinformationen über Datenmaske und Prüfbits für diese (XOR)
- verschiedene Versionen für verschiedene Größen (21x21 bis 177x177)
- verschiedene Encoding-Modes für numerisch, alphanumerisch, End of Message
  - Datenstream: Mode, Bitstream, EOM

## Impfzertifikat-Code

- ``base45``-codiert in QR-Code
- decodiert: signiertes JSON

### Überprüfung

- App lädt universellen öffentlichen Schlüssel zum Entschlüsseln der Signatur
- Signatur wird auf Gültigkeit geprüft
- Details zum Signaturverfahren: [Krypto Semester 4](https://github.com/importPI19fromDHGE/dhge-pi19-sem4/tree/main/SWS-KUSCHE#hashes--signatur)
