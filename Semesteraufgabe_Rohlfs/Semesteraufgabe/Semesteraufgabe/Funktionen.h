//Headerdatei für Funktionen.cpp zum Programm 'Literaturverwaltung'
//Geschrieben von Roman Rohlfs im SoSe 2020 im Modul Informatik 1
//Visual Studio 2017

#pragma once

extern void menu();
extern void clear();
extern int abfrage_typ();
extern void nullen(Daten *Datensatz);
extern void eingabe(Daten *Datensatz);
extern void einlesen(Daten *Datensatz);
extern void ausgabe(Daten tmp[1000]);
extern void speichern(Daten tmp[1000]);
extern void loeschen(Daten *Datensatz);
extern void aendern(Daten *Datensatz);
extern void exportbib(Daten tmp[1000]);
extern void suchen(Daten *Datensatz);