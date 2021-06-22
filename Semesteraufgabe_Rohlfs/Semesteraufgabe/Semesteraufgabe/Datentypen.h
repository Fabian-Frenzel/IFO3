//Headerdatei für Datentypen zum Programm 'Literaturverwaltung'
//Geschrieben von Roman Rohlfs im SoSe 2020 im Modul Informatik 1
//Visual Studio 2017
//Weiterentwickelt in 2021

#pragma once

//Datentyp Autor
struct autor {
	char vorname[25] = "0";
	char nachname[25] = "0";
};

//Datentyp für den Datensatz
typedef struct Daten {
	int belegt;
	int typ;

	autor author;

	char keyword[20] = "0";
	char address[50] = "0";
	char booktitle[50] = "0";
	char chapter[10] = "0";
	char edition[10] = "0";
	char editor[50] = "0";
	char howpublished[50] = "0";
	char institution[50] = "0";
	char journal[50] = "0";
	char month[10] = "0";
	char note[100] = "0";
	char number[10] = "0";
	char organization[50] = "0";
	char pages[10] = "0";
	char publisher[50] = "0";
	char school[50] = "0";
	char series[50] = "0";
	char title[100] = "0";
	char type[50] = "0";
	char volume[10] = "0";
	char year[5] = "0";
};

//Konstanten für den Literaturtyp
const int article = 1;
const int book = 2;
const int booklet = 3;
const int inbook = 4;
const int incollection = 5;
const int conference = 6;
const int proceedings = 7;
const int inproceedings = 8;
const int manual = 9;
const int masterthesis = 10;
const int phdthesis = 11;
const int techreport = 12;
const int unpublished = 13;
const int misc = 14;