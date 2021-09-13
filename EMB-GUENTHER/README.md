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

- [Platzhalter](#platzhalter)

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

## Projekt

- Webcam
  - Webzugriff auf RPI Cam über Access-Point
- QR-Scanner für Impfzertifikate
  - QR-Code einlesen, auswerten und Aktion realisieren

# buildroot

[https://buildroot.org/](https://buildroot.org/)

1. [buildroot herunterladen](https://buildroot.org/downloads/buildroot-2021.02.4.tar.gz) und entpacken
2. `make menuconfig` (`WSL2` braucht eventuell `apt install libncurses-dev`)
3. Image bauen (`make`)
4. Image auf SD-Karte kopieren (`sudo dd if=output/images/sdcard.img of=/dev/sdX`)