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

# Einleitung

- Prüfung: Seminararbeit + Kurzvortrag (30+15 Minuten)
  - Arbeit soll Ansprüchen wissenschaftlichen Arbeitens genügen, ca. 10 Seiten
- Zusammenarbeit erwünscht <!--GitHub intensifies-->
- Projekt: Webcam *oder* QR-Scanner mit Raspberry Pi und eigenem WiFi-AP und App-Zugriff; Linux von Grund auf bauen

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

## Organisation

- Teambildung
  - jedes Team hat eine Nummer

# Buildroot

- Tool zum Bauen von Embedded Linux Images
- Bauen der Default-Config: ``make defconfig`` gefolgt von ``make``
  - die Images liegen in ``output/images``
- eigene Dateien können via Overlay-Ordner im Board-Verzeichnis abgelegt werden
