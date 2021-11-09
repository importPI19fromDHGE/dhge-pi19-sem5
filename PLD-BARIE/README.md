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

- [Platzhalter](#platzhalter)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<!--newpage-->

# Wiederholung Digitaltechnik

## Disjunktive Normalform (DNF)

- logischer Ausdruck, der in der oberen Ebene ausschließlich aus ODER-Verknüpfungen besteht
- Stufen:
  - 1.Stufe: UND-Verknüpfungen (Konjunktionen)
  - 2.Stufe: ODER-Verküpfungen

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
- die LUT werden in SRAM-Zellen hinterlegt und könnend ann durch Ansteuerung der Eingänge ausgelesen werden

> weitere Infos: <https://de.wikipedia.org/wiki/Field_Programmable_Gate_Array#Aufbau_und_Struktur>
