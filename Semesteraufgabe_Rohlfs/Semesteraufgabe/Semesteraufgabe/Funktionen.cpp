//Funktionen zum Programm 'Literaturverwaltung'
//Geschrieben von Roman Rohlfs im SoSe 2020 im Modul Informatik 1
//Visual Studio 2017

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "Datentypen.h"
#include "Funktionen.h"

//Funktion zum Entfernen des Zeichens \n beim Einlesen
void entf(char *str) {
	str[strlen(str) - 1] = '\0';
}

//Funktion für die Darstellung des Hauptmenüs
void menu() {
	printf("##############################################################\n");
	printf("#                     Literaturverwaltung                    #\n");
	printf("##############################################################\n");
	printf("#                         Hauptmenue                         #\n");
	printf("#                                                            #\n");
	printf("#  Neuen Datensatz eingeben ........................... 1    #\n");
	printf("#  Alle Datensaetze ausgeben .......................... 2    #\n");
	printf("#  Datensaetze durchsuchen ............................ 3    #\n");
	printf("#  Datensaetze speichern .............................. 4    #\n");
	printf("#  Datensatz aendern .................................. 5    #\n");
	printf("#  Datensatz loeschen ................................. 6    #\n");
	printf("#  Export im BibTex-Format ............................ 7    #\n");
	printf("#                                                            #\n");
	printf("#  Programm beenden ................................... 8    #\n");
	printf("#                                                            #\n");
	printf("##############################################################\n");
}

//Funktion zum Leeren der Konsole
void clear() {
	system("cls");
}

//Funktion zum Füllen der Datensaetze mit Nullen um Zufallswerte zu vermeiden
void nullen(Daten *Datensatz) {
	int i;
	for (i = 0; i < 1000; i++) {
		Datensatz[i].belegt = 0;
		Datensatz[i].typ = 0;
		strcpy(Datensatz[i].address, "0");
		strcpy(Datensatz[i].author.nachname, "0");
		strcpy(Datensatz[i].author.vorname, "0");
		strcpy(Datensatz[i].booktitle, "0");
		strcpy(Datensatz[i].chapter, "0");
		strcpy(Datensatz[i].edition, "0");
		strcpy(Datensatz[i].editor, "0");
		strcpy(Datensatz[i].howpublished, "0");
		strcpy(Datensatz[i].institution, "0");
		strcpy(Datensatz[i].journal, "0");
		strcpy(Datensatz[i].month, "0");
		strcpy(Datensatz[i].note, "0");
		strcpy(Datensatz[i].number, "0");
		strcpy(Datensatz[i].organization, "0");
		strcpy(Datensatz[i].pages, "0");
		strcpy(Datensatz[i].publisher, "0");
		strcpy(Datensatz[i].school, "0");
		strcpy(Datensatz[i].series, "0");
		strcpy(Datensatz[i].title, "0");
		strcpy(Datensatz[i].type, "0");
		strcpy(Datensatz[i].volume, "0");
		strcpy(Datensatz[i].year, "0");
	}
}

//Funktion zum Abfragen des Literaturtyps
int abfrage_typ() {

	//Variablendeklarationen
	int auswahl;
	char buf[10];

	auswahl = -1;
	do {
		clear();
		printf("Neuen Datensatz eingeben.\n");
		printf("\nUm welchen Literaturtyp handelt es sich?\n");
		printf(" - Artikel ............................... 1\n"); //article
		printf(" - Buch .................................. 2\n"); //book
		printf(" - Broschuere ............................ 3\n"); //booklet
		printf(" - Teil eines Buches ..................... 4\n"); //inbook
		printf(" - Teil eines Buches mit eigenem Titel ... 5\n"); //incollection
		printf(" - Wissenschaftliche Konferenz ........... 6\n"); //conference
		printf(" - Konferenzbericht ...................... 7\n"); //proceedings
		printf(" - Artikel in einem Konferenzbericht ..... 8\n"); //inproceedings
		printf(" - Technische Dokumentation .............. 9\n"); //manual
		printf(" - Abschlussarbeit ...................... 10\n"); //masterthesis
		printf(" - Doktorarbeit ......................... 11\n"); //phdthesis
		printf(" - Wissenschaftlicher Bericht ........... 12\n"); //techreport
		printf(" - Unveroeffentlichtes Dokument ......... 13\n"); //unpublished
		printf(" - Sonstiges ............................ 14\n"); //misc
		printf("\nAuswahl: ");
		fgets(buf, 10, stdin);			//Auswahl abfragen
		sscanf(buf, "%i", &auswahl);	//Auswahl als Zahl umwandeln
		if ((auswahl < 1) || (auswahl > 14)) {
			printf("\nFehlerhafte Eingabe!");
			getchar();
		}
	} while ((auswahl < 1) || (auswahl > 14));

	return auswahl;
}

//Funktion zum Ausgeben aller belegten Datensätze
void ausgabe(Daten tmp[1000]) {

	//Variablendeklaration
	int i, j = 0, anz = 0;

	clear();
	printf("Alle Datensaetze ausgeben.\n");

	//Datensätze durchgehen und jeden "belegt" markierten Datensatz ausgeben
	for (i = 0; i < 1000; i++) {
		if (tmp[i].belegt == 1) {
			anz++;
			//Nach jedem zweiten Datensatz Ausgabe unterbrechen (Blätterfunktion)
			if (j == 2) {
				j = 0;
				printf("\nWeiter...");
				getchar();
				clear();
				printf("Alle Datensaetze ausgeben.\n");
			}
			printf("\nDatensatz %i, ", i);

			//Typenspezifische Ausgabe
			switch (tmp[i].typ) {
			case article:
				printf("Artikel:\n");
				break;
			case book:
				printf("Buch:\n");
				break;
			case booklet:
				printf("Broschuere:\n");
				break;
			case inbook:
				printf("Teil eines Buches:\n");
				break;
			case incollection:
				printf("Teil eines Buches mit eigenem Titel:\n");
				break;
			case conference:
				printf("Wissenschaftliche Konferenz:\n");
				break;
			case proceedings:
				printf("Konferenzbericht:\n");
				break;
			case inproceedings:
				printf("Artikel in einem Konferenzbericht:\n");
				break;
			case manual:
				printf("Technische Dokumentation:\n");
				break;
			case masterthesis:
				printf("Abschlussarbeit:\n");
				break;
			case phdthesis:
				printf("Doktorarbeit:\n");
				break;
			case techreport:
				printf("Wissenschaftlicher Bericht:\n");
				break;
			case unpublished:
				printf("Unveroeffentlichtes Dokument:\n");
				break;
			case misc:
				printf("Sonstiges:\n");
				break;
			}

			//Ausgabe der jeweiligen Daten.
			//Es werden nur Daten ausgegeben, die nicht als '0' markiert sind (leere Felder des Datensatzes)
			if ((strcmp(tmp[i].author.nachname, "0") != 0) && (strcmp(tmp[i].author.vorname, "0") != 0)) {
				printf(" - Autor:\t\t%s, %s\n", tmp[i].author.nachname, tmp[i].author.vorname);
			}
			else if (strcmp(tmp[i].author.nachname, "0") != 0) {
				printf(" - Autor:\t\t%s\n", tmp[i].author.nachname);
			}
			if (strcmp(tmp[i].editor, "0") != 0) {
				printf(" - Editor:\t\t%s\n", tmp[i].editor);
			}
			if (strcmp(tmp[i].title, "0") != 0) {
				printf(" - Titel:\t\t%s\n", tmp[i].title);
			}
			if (strcmp(tmp[i].journal, "0") != 0) {
				printf(" - Zeitschrift:\t\t%s\n", tmp[i].journal);
			}
			if (strcmp(tmp[i].publisher, "0") != 0) {
				printf(" - Herausgeber:\t\t%s\n", tmp[i].publisher);
			}
			if (strcmp(tmp[i].school, "0") != 0) {
				printf(" - Universitaet:\t%s\n", tmp[i].school);
			}
			if (strcmp(tmp[i].year, "0") != 0) {
				printf(" - Jahr:\t\t%s\n", tmp[i].year);
			}
			if (strcmp(tmp[i].booktitle, "0") != 0) {
				printf(" - Buchtitel:\t\t%s\n", tmp[i].booktitle);
			}
			if (strcmp(tmp[i].volume, "0") != 0) {
				printf(" - Ausgabe:\t\t%s\n", tmp[i].volume);
			}
			if (strcmp(tmp[i].edition, "0") != 0) {
				printf(" - Edition:\t\t%s\n", tmp[i].edition);
			}
			if (strcmp(tmp[i].number, "0") != 0) {
				printf(" - Nummer:\t\t%s\n", tmp[i].number);
			}
			if (strcmp(tmp[i].chapter, "0") != 0) {
				printf(" - Kapitel:\t\t%s\n", tmp[i].chapter);
			}
			if (strcmp(tmp[i].pages, "0") != 0) {
				printf(" - Seiten:\t\t%s\n", tmp[i].pages);
			}
			if (strcmp(tmp[i].series, "0") != 0) {
				printf(" - Serie:\t\t%s\n", tmp[i].series);
			}
			if (strcmp(tmp[i].address, "0") != 0) {
				printf(" - Adresse:\t\t%s\n", tmp[i].address);
			}
			if (strcmp(tmp[i].howpublished, "0") != 0) {
				printf(" - Veroeffentlichung:\t%s\n", tmp[i].howpublished);
			}
			if (strcmp(tmp[i].type, "0") != 0) {
				printf(" - Typ:\t\t\t%s\n", tmp[i].type);
			}
			if (strcmp(tmp[i].institution, "0") != 0) {
				printf(" - Institution:\t\t%s\n", tmp[i].institution);
			}
			if (strcmp(tmp[i].organization, "0") != 0) {
				printf(" - Organisation:\t%s\n", tmp[i].organization);
			}
			if (strcmp(tmp[i].month, "0") != 0) {
				printf(" - Monat:\t\t%s\n", tmp[i].month);
			}
			if (strcmp(tmp[i].note, "0") != 0) {
				printf(" - Notizen:\t\t%s\n", tmp[i].note);
			}
			printf("\n - Schluesselwort:\t%s\n", tmp[i].keyword);
			j++;
		}
	}
	//Anzahl der vorhandenen Datensätze ausgeben
	printf("\nAnzahl vorhandener Datensaetze: %i\n\nZurueck...", anz);
	getchar();
}

//Funktion zum Ausgeben eines Datensatzes
void ausgeben(Daten tmp) {
	printf("**************************************************************\n");
	//Typenspezifische Ausgabe
	switch (tmp.typ) {
	case article:
		printf("* Artikel:\n");
		break;
	case book:
		printf("* Buch:\n");
		break;
	case booklet:
		printf("* Broschuere:\n");
		break;
	case inbook:
		printf("* Teil eines Buches:\n");
		break;
	case incollection:
		printf("* Teil eines Buches mit eigenem Titel:\n");
		break;
	case conference:
		printf("* Wissenschaftliche Konferenz:\n");
		break;
	case proceedings:
		printf("* Konferenzbericht:\n");
		break;
	case inproceedings:
		printf("* Artikel in einem Konferenzbericht:\n");
		break;
	case manual:
		printf("* Technische Dokumentation:\n");
		break;
	case masterthesis:
		printf("* Abschlussarbeit:\n");
		break;
	case phdthesis:
		printf("* Doktorarbeit:\n");
		break;
	case techreport:
		printf("* Wissenschaftlicher Bericht:\n");
		break;
	case unpublished:
		printf("* Unveroeffentlichtes Dokument:\n");
		break;
	case misc:
		printf("* Sonstiges:\n");
		break;
	}
	if ((strcmp(tmp.author.nachname, "0") != 0) && (strcmp(tmp.author.vorname, "0") != 0)) {
		printf("* - Autor:\t\t%s, %s\n", tmp.author.nachname, tmp.author.vorname);
	}
	if (strcmp(tmp.editor, "0") != 0) {
		printf("* - Editor:\t\t%s\n", tmp.editor);
	}
	if (strcmp(tmp.title, "0") != 0) {
		printf("* - Titel:\t\t%s\n", tmp.title);
	}
	if (strcmp(tmp.journal, "0") != 0) {
		printf("* - Zeitschrift:\t%s\n", tmp.journal);
	}
	if (strcmp(tmp.publisher, "0") != 0) {
		printf("* - Herausgeber:\t%s\n", tmp.publisher);
	}
	if (strcmp(tmp.year, "0") != 0) {
		printf("* - Jahr:\t\t%s\n", tmp.year);
	}
	if (strcmp(tmp.booktitle, "0") != 0) {
		printf("* - Buchtitel:\t\t%s\n", tmp.booktitle);
	}
	if (strcmp(tmp.volume, "0") != 0) {
		printf("* - Ausgabe:\t\t%s\n", tmp.volume);
	}
	if (strcmp(tmp.edition, "0") != 0) {
		printf("* - Edition:\t\t%s\n", tmp.edition);
	}
	if (strcmp(tmp.number, "0") != 0) {
		printf("* - Nummer:\t\t%s\n", tmp.number);
	}
	if (strcmp(tmp.chapter, "0") != 0) {
		printf("* - Kapitel:\t\t%s\n", tmp.chapter);
	}
	if (strcmp(tmp.pages, "0") != 0) {
		printf("* - Seiten:\t\t%s\n", tmp.pages);
	}
	if (strcmp(tmp.series, "0") != 0) {
		printf("* - Serie:\t\t%s\n", tmp.series);
	}
	if (strcmp(tmp.address, "0") != 0) {
		printf("* - Adresse:\t\t%s\n", tmp.address);
	}
	if (strcmp(tmp.howpublished, "0") != 0) {
		printf("* - Veroeffentlichung:\t%s\n", tmp.howpublished);
	}
	if (strcmp(tmp.organization, "0") != 0) {
		printf("* - Organisation:\t%s\n", tmp.organization);
	}
	if (strcmp(tmp.school, "0") != 0) {
		printf("* - Universitaet:\t%s\n", tmp.school);
	}
	if (strcmp(tmp.month, "0") != 0) {
		printf("* - Monat:\t\t%s\n", tmp.month);
	}
	if (strcmp(tmp.note, "0") != 0) {
		printf("* - Notizen:\t\t%s\n", tmp.note);
	}
	printf("*\n* - Schluesselwort:\t%s\n", tmp.keyword);
	printf("**************************************************************\n");
}

//Funktion zum Speichern aller belegten Datensätze
void speichern(Daten tmp[1000]){

	//Variablendeklaration
	int i, anz = 0;
	FILE *Datei;
	char dateiname[20] = "daten.dat";

	clear();
	printf("Datensaetze werden gespeichert... ");

	//Datensätze speichern
	if ((Datei = fopen(dateiname, "w+")) != NULL) {						//Datei öffnen
		for (i = 0; i < 1000; i++) {
			if (tmp[i].belegt == 1) {									//Wenn der Datensatz belegt ist, wird dieser gespeichert
				anz++;
				fwrite(&tmp[i], sizeof(struct Daten), 1, Datei);		//"Blockweise" speichern der Datensätze in die Datei
			}
		}
		printf("Datensaetze wurden erfolgreich gespeichert!\n");
		fclose(Datei);													//Datei wieder schließen
	}
	//Fehlerausgabe beim Scheitern
	else {
		printf("Fehler beim Speichern!\n");
	}
	printf("\nZurueck...");
	getchar();
}

//Funktion für die Eingabe eines Datensatzes
void eingabe(Daten *Datensatz) {

	//Variablendeklarationen
	int i, frei = -1;

	//Nächsten freien Datensatz bestimmen.
	//Alle Datensätze durchgehen, sobald ein Datensatz als frei markiert ist abbrechen.
	for (i = 0; i < 1000; i++) {
		if (Datensatz[i].belegt != 1) {
			frei = i;
			break;
		}
	}
	//Eingeben der neuen Daten je nach Literaturtyp
	if (frei != -1) {
		printf("\nNaechster freier Datensatz: %i\n", frei);
		//Typenabfrage
		switch (abfrage_typ()) {
		//Artikel (article)
		case article: {
			Datensatz[frei].typ = article;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Artikel:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - Autor:\n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);
			printf(" - Zeitschrift: ");
			fgets(Datensatz[frei].journal, 50, stdin);
			entf(Datensatz[frei].journal);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Ausgabe: ");
			fgets(Datensatz[frei].volume, 10, stdin);
			entf(Datensatz[frei].volume);
			printf(" - Nummer: ");
			fgets(Datensatz[frei].number, 10, stdin);
			entf(Datensatz[frei].number);
			printf(" - Seiten: ");
			fgets(Datensatz[frei].pages, 10, stdin);
			entf(Datensatz[frei].pages);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Buch (book)
		case book: {
			Datensatz[frei].typ = book;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Buch:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - Autor:\n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Editor: ");
			fgets(Datensatz[frei].editor, 50, stdin);
			entf(Datensatz[frei].editor);
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);
			printf(" - Herausgeber: ");
			fgets(Datensatz[frei].publisher, 50, stdin);
			entf(Datensatz[frei].publisher);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Ausgabe: ");
			fgets(Datensatz[frei].volume, 10, stdin);
			entf(Datensatz[frei].volume);
			printf(" - Serie: ");
			fgets(Datensatz[frei].series, 50, stdin);
			entf(Datensatz[frei].series);
			printf(" - Edition: ");
			fgets(Datensatz[frei].edition, 10, stdin);
			entf(Datensatz[frei].edition);
			printf(" - Adresse: ");
			fgets(Datensatz[frei].address, 50, stdin);
			entf(Datensatz[frei].address);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Broschuere (booklet)
		case booklet: {
			Datensatz[frei].typ = booklet;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Broschuere:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Autor:\n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Veroeffentlichung: ");
			fgets(Datensatz[frei].howpublished, 50, stdin);
			entf(Datensatz[frei].howpublished);
			printf(" - Adresse: ");
			fgets(Datensatz[frei].address, 50, stdin);
			entf(Datensatz[frei].address);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Wissenschaftliche Konferenz (conference)
		case conference: {
			Datensatz[frei].typ = conference;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Wissenschaftliche Konferenz:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - Autor:\n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);
			printf(" - Booktitle: ");
			fgets(Datensatz[frei].booktitle, 100, stdin);
			entf(Datensatz[frei].booktitle);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Editor: ");
			fgets(Datensatz[frei].editor, 50, stdin);
			entf(Datensatz[frei].editor);
			printf(" - Seiten: ");
			fgets(Datensatz[frei].pages, 10, stdin);
			entf(Datensatz[frei].pages);
			printf(" - Organisation: ");
			fgets(Datensatz[frei].organization, 50, stdin);
			entf(Datensatz[frei].organization);
			printf(" - Herausgeber: ");
			fgets(Datensatz[frei].publisher, 50, stdin);
			entf(Datensatz[frei].publisher);
			printf(" - Adresse: ");
			fgets(Datensatz[frei].address, 50, stdin);
			entf(Datensatz[frei].address);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Teil eines Buches (inbook)
		case inbook: {
			Datensatz[frei].typ = inbook;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Teil eines Buches:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - Autor:\n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Editor: ");
			fgets(Datensatz[frei].editor, 50, stdin);
			entf(Datensatz[frei].editor);
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);
			printf(" - Kapitel: ");
			fgets(Datensatz[frei].chapter, 10, stdin);
			entf(Datensatz[frei].chapter);
			printf(" - Seiten: ");
			fgets(Datensatz[frei].pages, 10, stdin);
			entf(Datensatz[frei].pages);
			printf(" - Herausgeber: ");
			fgets(Datensatz[frei].publisher, 50, stdin);
			entf(Datensatz[frei].publisher);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Ausgabe: ");
			fgets(Datensatz[frei].volume, 10, stdin);
			entf(Datensatz[frei].volume);
			printf(" - Serie: ");
			fgets(Datensatz[frei].series, 50, stdin);
			entf(Datensatz[frei].series);
			printf(" - Adresse: ");
			fgets(Datensatz[frei].address, 50, stdin);
			entf(Datensatz[frei].address);
			printf(" - Edition: ");
			fgets(Datensatz[frei].edition, 10, stdin);
			entf(Datensatz[frei].edition);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Teil eines Buches mit eigenem Titel (incollection)
		case incollection: {
			Datensatz[frei].typ = incollection;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Teil eines Buches mit eigenem Titel:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - Autor:\n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);
			printf(" - Buchtitel: ");
			fgets(Datensatz[frei].booktitle, 50, stdin);
			entf(Datensatz[frei].booktitle);
			printf(" - Herausgeber: ");
			fgets(Datensatz[frei].publisher, 50, stdin);
			entf(Datensatz[frei].publisher);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Editor: ");
			fgets(Datensatz[frei].editor, 50, stdin);
			entf(Datensatz[frei].editor);
			printf(" - Kapitel: ");
			fgets(Datensatz[frei].chapter, 10, stdin);
			entf(Datensatz[frei].chapter);
			printf(" - Seiten: ");
			fgets(Datensatz[frei].pages, 10, stdin);
			entf(Datensatz[frei].pages);
			printf(" - Adresse: ");
			fgets(Datensatz[frei].address, 50, stdin);
			entf(Datensatz[frei].address);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Artikel in einem Konferenzberichts (inproceedings)
		case inproceedings: {
			Datensatz[frei].typ = inproceedings;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Artikel in einem Konferenzberichts:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - Autor:\n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);
			printf(" - Buchtitel: ");
			fgets(Datensatz[frei].booktitle, 50, stdin);
			entf(Datensatz[frei].booktitle);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Editor: ");
			fgets(Datensatz[frei].editor, 50, stdin);
			entf(Datensatz[frei].editor);
			printf(" - Seiten: ");
			fgets(Datensatz[frei].pages, 10, stdin);
			entf(Datensatz[frei].pages);
			printf(" - Organisation: ");
			fgets(Datensatz[frei].organization, 50, stdin);
			entf(Datensatz[frei].organization);
			printf(" - Herausgeber: ");
			fgets(Datensatz[frei].publisher, 50, stdin);
			entf(Datensatz[frei].publisher);
			printf(" - Adresse: ");
			fgets(Datensatz[frei].address, 50, stdin);
			entf(Datensatz[frei].address);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Technische Dokumentation (manual)
		case manual: {
			Datensatz[frei].typ = manual;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Technische Dokumentation:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Autor:\n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Organisation: ");
			fgets(Datensatz[frei].organization, 50, stdin);
			entf(Datensatz[frei].organization);
			printf(" - Adresse: ");
			fgets(Datensatz[frei].address, 50, stdin);
			entf(Datensatz[frei].address);
			printf(" - Edition: ");
			fgets(Datensatz[frei].edition, 10, stdin);
			entf(Datensatz[frei].edition);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Abschlussarbeit (masterthesis)
		case masterthesis: {
			Datensatz[frei].typ = masterthesis;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Abschlussarbeit:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - Autor:\n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);
			printf(" - Universitaet: ");
			fgets(Datensatz[frei].school, 50, stdin);
			entf(Datensatz[frei].school);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Adresse: ");
			fgets(Datensatz[frei].address, 50, stdin);
			entf(Datensatz[frei].address);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Doktorarbeit (phdthesis)
		case phdthesis: {
			Datensatz[frei].typ = phdthesis;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Doktorarbeit:\n", frei);
			printf("Zwingende Felder: \n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);
			printf(" - Universitaet: ");
			fgets(Datensatz[frei].school, 50, stdin);
			entf(Datensatz[frei].school);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Adresse: ");
			fgets(Datensatz[frei].address, 50, stdin);
			entf(Datensatz[frei].address);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Konferenzbericht (proceedings)
		case proceedings: {
			Datensatz[frei].typ = proceedings;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Konferenzbericht:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Editor: ");
			fgets(Datensatz[frei].editor, 50, stdin);
			entf(Datensatz[frei].editor);
			printf(" - Herausgeber: ");
			fgets(Datensatz[frei].publisher, 50, stdin);
			entf(Datensatz[frei].publisher);
			printf(" - Organisation: ");
			fgets(Datensatz[frei].organization, 50, stdin);
			entf(Datensatz[frei].organization);
			printf(" - Adresse: ");
			fgets(Datensatz[frei].address, 50, stdin);
			entf(Datensatz[frei].address);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Veröffentlichter Bericht (techeport)
		case techreport: {
			Datensatz[frei].typ = techreport;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Wissenschaftlicher Bericht:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - Autor:\n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);
			printf(" - Institution: ");
			fgets(Datensatz[frei].institution, 50, stdin);
			entf(Datensatz[frei].institution);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Nummer: ");
			fgets(Datensatz[frei].number, 10, stdin);
			entf(Datensatz[frei].number);
			printf(" - Typ: ");
			fgets(Datensatz[frei].type, 50, stdin);
			entf(Datensatz[frei].type);
			printf(" - Adresse: ");
			fgets(Datensatz[frei].address, 50, stdin);
			entf(Datensatz[frei].address);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Unveröffentlichtes Dokument (unpublished)
		case unpublished: {
			Datensatz[frei].typ = unpublished;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Unveroeffentlichtes Dokument:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - Autor:\n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);
			Datensatz[frei].belegt = 1;
			printf("\nGespeichert!\n");
			break;
		}
		//Sonstiges (misc)
		case misc: {
			Datensatz[frei].typ = misc;
			clear();
			printf("Neuen Datensatz eingeben, Datensatz %i, Sonstiges:\n", frei);
			printf("Zwingende Felder: \n");
			printf(" - keine -\n");

			printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
			printf(" - Autor:\n");
			printf("   - Vorname: ");
			fgets(Datensatz[frei].author.vorname, 25, stdin);
			entf(Datensatz[frei].author.vorname);
			printf("   - Nachname: ");
			fgets(Datensatz[frei].author.nachname, 25, stdin);
			entf(Datensatz[frei].author.nachname);
			printf(" - Titel: ");
			fgets(Datensatz[frei].title, 100, stdin);
			entf(Datensatz[frei].title);
			printf(" - Veroeffentlichung: ");
			fgets(Datensatz[frei].howpublished, 50, stdin);
			entf(Datensatz[frei].howpublished);
			printf(" - Monat: ");
			fgets(Datensatz[frei].month, 10, stdin);
			entf(Datensatz[frei].month);
			printf(" - Jahr: ");
			fgets(Datensatz[frei].year, 10, stdin);
			entf(Datensatz[frei].year);
			printf(" - Notizen: ");
			fgets(Datensatz[frei].note, 100, stdin);
			entf(Datensatz[frei].note);

			if ((strcmp(Datensatz[frei].author.nachname, "0") == 0) && (strcmp(Datensatz[frei].title, "0") == 0) && (strcmp(Datensatz[frei].howpublished, "0") == 0) && (strcmp(Datensatz[frei].month, "0") == 0) && (strcmp(Datensatz[frei].note, "0") == 0) && (strcmp(Datensatz[frei].year, "0") == 0)) {
				printf("\nEs wurden keine Angaben gemacht. Nicht Gespeichert!\n");
				Datensatz[frei].typ = 0;
				Datensatz[frei].belegt = 0;
			}
			else {
				Datensatz[frei].belegt = 1;
				printf("\nGespeichert!\n");
			}
			break;
		}
		//Falsche Eingabe
		default: {
			printf("\nFehlerhafte Eingabe!");
		}
		}

		//Abfrage Schlüsselwort
		printf("\nGeben Sie ein Schluesselwort ein: ");
		fgets(Datensatz[frei].keyword, 20, stdin);
		entf(Datensatz[frei].keyword);

		//Zusammenfassung der eingegebenen Daten ausgeben
		printf("\nZusammenfassung:\n");
		ausgeben(Datensatz[frei]);
		printf("\nZurueck...");
	}
	//Ausgabe, wenn alle Datensätze belegt sind
	else {
		printf("\nAlle Datensaetze sind belegt!\n\nZurueck...");
}
	getchar();
}

//Funktion zum Einlesen der Datensätze
void einlesen(Daten *Datensatz) {
	int i = 0;
	FILE *Datei;
	char dateiname[20] = "daten.dat";			//Dateiname wird fest vergeben

	//Datei öffnen
	printf("Datensaetze werden geladen... ");
	if ((Datei = fopen(dateiname, "r+")) != NULL) {
		while (fread(&Datensatz[i], sizeof(struct Daten), 1, Datei) == 1) {
			i++;								//Datensätze "blockweise" auslesen
		}
		fclose(Datei);							//Datei wieder schließen
	}
	//Wenn die Datei nicht geöffnet werden konnte Fehlermeldung anzeigen
	else {
		printf("Fehler beim Laden!\n\nWeiter...");
		getchar();
	}
}

//Funktion zum Löschen eines Datensatzes
void loeschen(Daten *Datensatz) {

	//Variablendeklarationen
	int auswahl, auswahl2;
	char buf[10];

	auswahl = -1;
	auswahl2 = -1;
	do {
		//Auswahl des zu löschenden Datensatzes
		clear();
		printf("Datensatz loeschen.\n\nWelcher Datensatz soll geloescht werden: ");
		fgets(buf, 10, stdin);					//Auswahl abfragen
		sscanf(buf, "%i", &auswahl);			//Auswahl als Zahl umwandeln
		if ((auswahl < 0) || (auswahl >= 1000)) {
			printf("\nFehlerhafte Eingabe!");	//Fehlerhafte Eingabe abfangen
			getchar();
		}
	} while ((auswahl < 0) || (auswahl >= 1000));

	if (Datensatz[auswahl].belegt != 0) {

		//Anzeigen des zu löschenden Datensatzes
		do {
			clear();
			printf("Datensatz loeschen.\n\nAusgewaehlter Datensatz:\n");
			ausgeben(Datensatz[auswahl]);			//Ausgewählten Datensatz ausgeben
			printf("\nSoll dieser Datensatz wirklich geloescht werden?\n");
			printf("Ja ...... 1\nNein .... 2\n\nAuswahl: ");
			fgets(buf, 10, stdin);					//Auswahl abfragen
			sscanf(buf, "%i", &auswahl2);			//Auswahl als Zahl umwandeln
			if ((auswahl2 != 1) && (auswahl2 != 2)) {
				printf("\nFehlerhafte Eingabe!");	//Fehlerhafte Eingabe abfangen
				getchar();
			}
		} while ((auswahl2 != 1) && (auswahl2 != 2));

		//Ausgewählter Datensatz mit "0" belegen (löschen)
		if (auswahl2 == 1) {
			Datensatz[auswahl].belegt = 0;
			Datensatz[auswahl].typ = 0;
			strcpy(Datensatz[auswahl].address, "0");
			strcpy(Datensatz[auswahl].author.nachname, "0");
			strcpy(Datensatz[auswahl].author.vorname, "0");
			strcpy(Datensatz[auswahl].booktitle, "0");
			strcpy(Datensatz[auswahl].chapter, "0");
			strcpy(Datensatz[auswahl].edition, "0");
			strcpy(Datensatz[auswahl].editor, "0");
			strcpy(Datensatz[auswahl].howpublished, "0");
			strcpy(Datensatz[auswahl].institution, "0");
			strcpy(Datensatz[auswahl].journal, "0");
			strcpy(Datensatz[auswahl].month, "0");
			strcpy(Datensatz[auswahl].note, "0");
			strcpy(Datensatz[auswahl].number, "0");
			strcpy(Datensatz[auswahl].organization, "0");
			strcpy(Datensatz[auswahl].pages, "0");
			strcpy(Datensatz[auswahl].publisher, "0");
			strcpy(Datensatz[auswahl].school, "0");
			strcpy(Datensatz[auswahl].series, "0");
			strcpy(Datensatz[auswahl].title, "0");
			strcpy(Datensatz[auswahl].type, "0");
			strcpy(Datensatz[auswahl].volume, "0");
			strcpy(Datensatz[auswahl].year, "0");
			strcpy(Datensatz[auswahl].keyword, "0");
			printf("\nDer Datensatz %i wurde erfolgreich geloescht.\n\nZurueck...", auswahl);
			getchar();
		}
		//Ausgabe, wenn der Datensatz nicht gelöscht werden soll
		else {
			printf("\nDer Datensatz %i wurde nicht geloescht.\n\nZurueck...", auswahl);
			getchar();
		}
	}
	//Fehlerausgage, wenn der Datensatz nicht vorhanden ist
	else {
		printf("\nDer Datensatz %i ist nicht vorhanden.\n", auswahl);
		printf("\nZurueck...");
		getchar();
	}
}

//Funktion zum Ändern eines Datensatzes
void aendern(Daten *Datensatz) {

	//Variablendeklarationen
	int auswahl, wahl;
	char puffer[100], buf[10];

	auswahl = -1;
	wahl = 0;
	//Schleife für die Auswahl des "richtigen" Datensatzes
	do {
		//Auswahl des zu ändernden Datensatzes
		do {
			clear();
			printf("Datensatz aendern.\n\nWelchen Datensatz moechten Sie aendern: ");
			fgets(buf, 10, stdin);			//Auswahl abfragen
			sscanf(buf, "%i", &auswahl);	//Auswahl als Zahl umwandeln
			if ((auswahl < 0) || (auswahl >= 1000)) {
				printf("\nFehlerhafte Eingabe!");
				getchar();
			}
		} while ((auswahl < 0) || (auswahl >= 1000));

		//Wenn der ausgewählte Datensatz belegt ist, wird er ausgegeben
		if (Datensatz[auswahl].belegt != 0) {
			do {
				clear();
				printf("Datensatz aendern.\n\nAusgewaehlter Datensatz:\n");
				ausgeben(Datensatz[auswahl]);

				//Abfrage, ob der Datensatz der Richtige ist
				printf("\nIst dieser Datensatz richtig?\n");
				printf("Ja ........................ 1\n");
				printf("Nein ...................... 2\n\nAuswahl: ");
				fgets(buf, 10, stdin);			//Auswahl abfragen
				sscanf(buf, "%i", &wahl);		//Auswahl als Zahl umwandeln
				if ((wahl != 1) && (wahl != 2)) {
					printf("\nFehlerhafte Eingabe!");
					getchar();
				}
			} while ((wahl != 1) && (wahl != 2));

			//Datensatz ändern
			if (wahl == 1) {
				clear();
				printf("Datensatz %i aendern.\n\n", auswahl);
				printf("Geben Sie '0' ein, um das Feld zu entfernen (nur fuer optional) oder '-' um das Feld nicht zu aendern.\n\n");

				//Je nach Typ sind unterschiedliche Felder "änderbar", "-" übernimmt die vorherige Eingabe, "0" löscht die Eingabe
				switch (Datensatz[auswahl].typ) {
				case article: {
					printf("Typ: Artikel\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					printf("*  Vorname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}
					printf("\nZeitschrift: %s\n", Datensatz[auswahl].journal);
					printf("Neu: \n");
					printf("* Zeitschrift: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].journal, puffer, 50);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nAusgabe: %s\n", Datensatz[auswahl].volume);
					printf("Neu: \n");
					printf("* Ausgabe: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].volume, puffer, 10);
					}
					printf("\nNummer: %s\n", Datensatz[auswahl].number);
					printf("Neu: \n");
					printf("* Nummer: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].number, puffer, 10);
					}
					printf("\nSeiten: %s\n", Datensatz[auswahl].pages);
					printf("Neu: \n");
					printf("* Seiten: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].pages, puffer, 10);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				case book: {
					printf("Typ: Buch\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					printf("*  Vorname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nEditor: %s\n", Datensatz[auswahl].editor);
					printf("Neu: \n");
					printf("* Editor: ");
					fgets(puffer, 50, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].editor, puffer, 50);
					}
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}
					printf("\nHerausgeber: %s\n", Datensatz[auswahl].publisher);
					printf("Neu: \n");
					printf("* Herausgeber: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].publisher, puffer, 50);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nAusgabe: %s\n", Datensatz[auswahl].volume);
					printf("Neu: \n");
					printf("* Ausgabe: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].volume, puffer, 10);
					}
					printf("\nSerie: %s\n", Datensatz[auswahl].series);
					printf("Neu: \n");
					printf("* Serie: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].series, puffer, 50);
					}
					printf("\nAdresse: %s\n", Datensatz[auswahl].address);
					printf("Neu: \n");
					printf("* Adresse: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].address, puffer, 50);
					}
					printf("\nEdition: %s\n", Datensatz[auswahl].edition);
					printf("Neu: \n");
					printf("* Edition: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].edition, puffer, 10);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				case booklet: {
					printf("Typ: Broschuere\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					printf("*  Vorname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nVeroeffentlichung: %s\n", Datensatz[auswahl].howpublished);
					printf("Neu: \n");
					printf("* Veroeffentlichung: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].howpublished, puffer, 50);
					}
					printf("\nAdresse: %s\n", Datensatz[auswahl].address);
					printf("Neu: \n");
					printf("* Adresse: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].address, puffer, 50);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				case inbook: {
					printf("Typ: Teil eines Buches\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					printf("*  Vorname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nEditor: %s\n", Datensatz[auswahl].editor);
					printf("Neu: \n");
					printf("* Editor: ");
					fgets(puffer, 50, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].editor, puffer, 50);
					}
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}
					printf("\nKapitel: %s\n", Datensatz[auswahl].chapter);
					printf("Neu: \n");
					printf("* Kapitel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].chapter, puffer, 10);
					}
					printf("\nSeiten: %s\n", Datensatz[auswahl].pages);
					printf("Neu: \n");
					printf("* Seiten: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].pages, puffer, 10);
					}
					printf("\nHerausgeber: %s\n", Datensatz[auswahl].publisher);
					printf("Neu: \n");
					printf("* Herausgeber: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].publisher, puffer, 50);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nAusgabe: %s\n", Datensatz[auswahl].volume);
					printf("Neu: \n");
					printf("* Ausgabe: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].volume, puffer, 10);
					}
					printf("\nSerie: %s\n", Datensatz[auswahl].series);
					printf("Neu: \n");
					printf("* Serie: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].series, puffer, 50);
					}
					printf("\nAdresse: %s\n", Datensatz[auswahl].address);
					printf("Neu: \n");
					printf("* Adresse: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].address, puffer, 50);
					}
					printf("\nEdition: %s\n", Datensatz[auswahl].edition);
					printf("Neu: \n");
					printf("* Edition: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].edition, puffer, 10);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				case incollection: {
					printf("Typ: Teil eines Buches mit eigenem Titel\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					printf("*  Vorname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}
					printf("\nBuchtitel: %s\n", Datensatz[auswahl].booktitle);
					printf("Neu: \n");
					printf("* Buchtitel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].booktitle, puffer, 50);
					}
					printf("\nHerausgeber: %s\n", Datensatz[auswahl].publisher);
					printf("Neu: \n");
					printf("* Herausgeber: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].publisher, puffer, 50);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nEditor: %s\n", Datensatz[auswahl].editor);
					printf("Neu: \n");
					printf("* Editor: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].editor, puffer, 50);
					}
					printf("\nKapitel: %s\n", Datensatz[auswahl].chapter);
					printf("Neu: \n");
					printf("* Kapitel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].chapter, puffer, 10);
					}
					printf("\nSeiten: %s\n", Datensatz[auswahl].pages);
					printf("Neu: \n");
					printf("* Seiten: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].pages, puffer, 10);
					}
					printf("\nAdresse: %s\n", Datensatz[auswahl].address);
					printf("Neu: \n");
					printf("* Adresse: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].address, puffer, 50);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				case conference: {
					printf("Typ: Wissenschaftliche Konferenz\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}
					printf("\nBuchtitel: %s\n", Datensatz[auswahl].booktitle);
					printf("Neu: \n");
					printf("* Buchtitel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].booktitle, puffer, 10);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nEditor: %s\n", Datensatz[auswahl].editor);
					printf("Neu: \n");
					printf("* Editor: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].editor, puffer, 50);
					}
					printf("\nSeiten: %s\n", Datensatz[auswahl].pages);
					printf("Neu: \n");
					printf("* Seiten: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].pages, puffer, 10);
					}
					printf("\nOrganisation: %s\n", Datensatz[auswahl].organization);
					printf("Neu: \n");
					printf("* Organisation ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].organization, puffer, 50);
					}
					printf("\nHerausgeber: %s\n", Datensatz[auswahl].publisher);
					printf("Neu: \n");
					printf("* Herausgeber ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].publisher, puffer, 50);
					}
					printf("\nAdresse: %s\n", Datensatz[auswahl].address);
					printf("Neu: \n");
					printf("* Adresse: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].address, puffer, 50);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				case proceedings: {
					printf("Typ: Konferenzbericht\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nEditor: %s\n", Datensatz[auswahl].editor);
					printf("Neu: \n");
					printf("* Editor: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].editor, puffer, 50);
					}
					printf("\nHerausgeber: %s\n", Datensatz[auswahl].publisher);
					printf("Neu: \n");
					printf("* Herausgeber: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].publisher, puffer, 50);
					}
					printf("\nOrganisation: %s\n", Datensatz[auswahl].organization);
					printf("Neu: \n");
					printf("* Organisation: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].organization, puffer, 50);
					}
					printf("\nAdresse: %s\n", Datensatz[auswahl].address);
					printf("Neu: \n");
					printf("* Adresse: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].address, puffer, 50);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				case inproceedings: {
					printf("Typ: Artikel in einem Konferenzbericht\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					printf("*  Vorname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}
					printf("\nBuchtitel: %s\n", Datensatz[auswahl].booktitle);
					printf("Neu: \n");
					printf("* Buchtitel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].booktitle, puffer, 50);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nEditor: %s\n", Datensatz[auswahl].editor);
					printf("Neu: \n");
					printf("* Editor: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].editor, puffer, 50);
					}
					printf("\nSeiten: %s\n", Datensatz[auswahl].pages);
					printf("Neu: \n");
					printf("* Seiten: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].pages, puffer, 10);
					}
					printf("\nOrganisation: %s\n", Datensatz[auswahl].organization);
					printf("Neu: \n");
					printf("* Organisation: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].organization, puffer, 50);
					}
					printf("\nHerausgeber: %s\n", Datensatz[auswahl].publisher);
					printf("Neu: \n");
					printf("* Herausgeber: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].publisher, puffer, 50);
					}
					printf("\nAdresse: %s\n", Datensatz[auswahl].address);
					printf("Neu: \n");
					printf("* Adresse: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].address, puffer, 50);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				case manual: {
					printf("Typ: Technische Dokumentation\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					printf("*  Vorname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nOrganisation: %s\n", Datensatz[auswahl].organization);
					printf("Neu: \n");
					printf("* Organisation: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].organization, puffer, 50);
					}
					printf("\nAdresse: %s\n", Datensatz[auswahl].address);
					printf("Neu: \n");
					printf("* Adresse: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].address, puffer, 50);
					}
					printf("\nEdition: %s\n", Datensatz[auswahl].edition);
					printf("Neu: \n");
					printf("* Edition: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].edition, puffer, 10);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				case masterthesis: {
					printf("Typ: Abschlussarbeit\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					printf("*  Vorname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}
					printf("\nUniversitaet: %s\n", Datensatz[auswahl].school);
					printf("Neu: \n");
					printf("* Universitaet: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].school, puffer, 50);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nAdresse: %s\n", Datensatz[auswahl].address);
					printf("Neu: \n");
					printf("* Adresse: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].address, puffer, 50);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				case phdthesis: {
					printf("Typ: Doktorarbeit\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					printf("*  Vorname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}
					printf("\nUniversitaet: %s\n", Datensatz[auswahl].school);
					printf("Neu: \n");
					printf("* Universitaet: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].school, puffer, 50);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nAdresse: %s\n", Datensatz[auswahl].address);
					printf("Neu: \n");
					printf("* Adresse: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].address, puffer, 50);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				case techreport: {
					printf("Typ: Wissenschaftlicher Bericht\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					printf("*  Vorname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}
					printf("\nInstitution: %s\n", Datensatz[auswahl].institution);
					printf("Neu: \n");
					printf("* Institution: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].institution, puffer, 50);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nTyp: %s\n", Datensatz[auswahl].type);
					printf("Neu: \n");
					printf("* Typ: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].type, puffer, 50);
					}
					printf("\nNummer: %s\n", Datensatz[auswahl].number);
					printf("Neu: \n");
					printf("* Nummer: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].number, puffer, 10);
					}
					printf("\nAdresse: %s\n", Datensatz[auswahl].address);
					printf("Neu: \n");
					printf("* Adresse: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].address, puffer, 50);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				case unpublished: {
					printf("Typ: Unveroeffentlichtes Dokument\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					printf("*  Vorname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}
					break;
				}
				case misc: {
					printf("Typ: Sonstiges\nHinweis: Der Typ kann nicht veraendert werden.\n");
					printf("\nZwingende Felder: \n\n - keine -\n");

					printf("\nOptionale Felder ('0' fuer keine Angabe):\n");
					printf("\nAutor: %s, %s\n", Datensatz[auswahl].author.nachname, Datensatz[auswahl].author.vorname);
					printf("Neu: \n");
					printf("* Autor:\n");
					printf("*  Vorname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.vorname, puffer, 25);
					}
					printf("*  Nachname: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].author.nachname, puffer, 25);
					}
					printf("\nTitel: %s\n", Datensatz[auswahl].title);
					printf("Neu: \n");
					printf("* Titel: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].title, puffer, 100);
					}
					printf("\nVeroeffentlichung: %s\n", Datensatz[auswahl].howpublished);
					printf("Neu: \n");
					printf("* Veroeffentlichung: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].howpublished, puffer, 50);
					}
					printf("\nMonat: %s\n", Datensatz[auswahl].month);
					printf("Neu: \n");
					printf("* Monat: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].month, puffer, 10);
					}
					printf("\nJahr: %s\n", Datensatz[auswahl].year);
					printf("Neu: \n");
					printf("* Jahr: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].year, puffer, 5);
					}
					printf("\nNotizen: %s\n", Datensatz[auswahl].note);
					printf("Neu: \n");
					printf("* Notizen: ");
					fgets(puffer, 100, stdin);
					entf(puffer);
					if (strcmp(puffer, "-") != NULL) {
						strncpy(Datensatz[auswahl].note, puffer, 100);
					}
					break;
				}
				default: {
					printf("\nUngueltiger Datensatz oder ungueltiger Typ!\n");
				}
				}
				printf("\nSchluesselwort: %s\n", Datensatz[auswahl].keyword);
				printf("Neu: \n");
				printf("* Schluesselwort: ");
				fgets(puffer, 100, stdin);
				entf(puffer);
				if (strcmp(puffer, "-") != NULL) {
					strncpy(Datensatz[auswahl].keyword, puffer, 20);
				}
				clear();
				printf("Datensatz aendern.\n\nAenderungen uebernommen!\n\nZusammenfassung:\n");

				//Zusammenfassung der Daten ausgeben
				ausgeben(Datensatz[auswahl]);
			}
		}
		//Fehlermeldung anzeigen, wenn der Datensatz nicht belegt ist.
		else {
			printf("\nDer Datensatz %i ist noch nicht belegt.\n", auswahl);
			break;
		}
	} while (wahl == 2);
	printf("\nZurueck...");
	getchar();
}

//Funktion zum Exportieren der Datensätze im BibTex-Format
void exportbib(Daten tmp[1000]) {

	//Variablendeklarationen
	FILE *Datei;
	char dateiname[50] = "export.bib", sw_misc[100] = "";
	int i, anz = 0;

	//Dateiname abfragen
	do {
		clear();
		printf("Exportieren der Datensaetze im BibTex-Format.\n\nGeben Sie einen Dateinamen ein: ");
		fgets(dateiname, 50, stdin);
		entf(dateiname);
	} while (strlen(dateiname) < 1);
	strncat(dateiname, ".bib", 4);			//Dateiname mit der Dateiendung.bib versehen
	printf("\nDatensaetze werden exportiert nach >%s< ... ", dateiname);

	//Datei erstellen bzw. öffnen
	if ((Datei = fopen(dateiname, "w+")) != NULL) {
		for (i = 0; i < 1000; i++) {
			if (tmp[i].belegt == 1) {
				//Wenn der Datensatz belegt ist speichern, je nach Typ werden andere Felder gespeichert
				switch (tmp[i].typ) {
				case article: {
					fprintf(Datei, "@article{%s,\n\tauthor = {%s, %s},\n\ttitle = {%s},\n\tjournal = {%s},\n\tyear = {%s}", tmp[i].keyword, tmp[i].author.nachname, tmp[i].author.vorname, tmp[i].title, tmp[i].journal, tmp[i].year);
					if (strcmp(tmp[i].volume, "0") != 0) {
						fprintf(Datei, ",\n\tvolume = {%s}", tmp[i].volume);
					}
					if (strcmp(tmp[i].number, "0") != 0) {
						fprintf(Datei, ",\n\tnumber = {%s}", tmp[i].number);
					}
					if (strcmp(tmp[i].pages, "0") != 0) {
						fprintf(Datei, ",\n\tpages = {%s}", tmp[i].pages);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case book: {
					fprintf(Datei, "@book{%s,\n\tauthor = {%s, %s},\n\ttitle = {%s},\n\tpublisher = {%s},\n\tyear = {%s}", tmp[i].keyword, tmp[i].author.nachname, tmp[i].author.vorname, tmp[i].title, tmp[i].publisher, tmp[i].year);
					if (strcmp(tmp[i].editor, "0") != 0) {
						fprintf(Datei, ",\n\teditor = {%s}", tmp[i].editor);
					}
					if (strcmp(tmp[i].volume, "0") != 0) {
						fprintf(Datei, ",\n\tvolume = {%s}", tmp[i].volume);
					}
					if (strcmp(tmp[i].series, "0") != 0) {
						fprintf(Datei, ",\n\tseries = {%s}", tmp[i].series);
					}
					if (strcmp(tmp[i].address, "0") != 0) {
						fprintf(Datei, ",\n\taddress = {%s}", tmp[i].address);
					}
					if (strcmp(tmp[i].edition, "0") != 0) {
						fprintf(Datei, ",\n\tedition = {%s}", tmp[i].edition);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case booklet: {
					fprintf(Datei, "@booklet{%s,\n\ttitle = {%s}", tmp[i].keyword, tmp[i].title);
					if ((strcmp(tmp[i].author.nachname, "0") != 0) && (strcmp(tmp[i].author.vorname, "0") != 0)) {
						fprintf(Datei, ",\n\tauthor = {%s, %s}", tmp[i].author.nachname, tmp[i].author.vorname);
					}
					else if (strcmp(tmp[i].author.nachname, "0") != 0) {
						fprintf(Datei, ",\n\tauthor = {%s}", tmp[i].author.nachname);
					}
					if (strcmp(tmp[i].howpublished, "0") != 0) {
						fprintf(Datei, ",\n\tVeroeffentlichung = {%s}", tmp[i].howpublished);
					}
					if (strcmp(tmp[i].address, "0") != 0) {
						fprintf(Datei, ",\n\taddress = {%s}", tmp[i].address);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].year, "0") != 0) {
						fprintf(Datei, ",\n\tyear = {%s}", tmp[i].year);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case inbook: {
					fprintf(Datei, "@inbook{%s,\n\tauthor = {%s, %s},\n\ttitle = {%s},\n\tchapter = {%s},\n\tpages = {%s},\n\tpublisher = {%s},\n\tyear = {%s}", tmp[i].keyword, tmp[i].author.nachname, tmp[i].author.vorname, tmp[i].title, tmp[i].chapter, tmp[i].pages, tmp[i].publisher, tmp[i].year);
					if (strcmp(tmp[i].editor, "0") != 0) {
						fprintf(Datei, ",\n\teditor = {%s}", tmp[i].editor);
					}
					if (strcmp(tmp[i].volume, "0") != 0) {
						fprintf(Datei, ",\n\tvolume = {%s}", tmp[i].volume);
					}
					if (strcmp(tmp[i].series, "0") != 0) {
						fprintf(Datei, ",\n\tseries = {%s}", tmp[i].series);
					}
					if (strcmp(tmp[i].address, "0") != 0) {
						fprintf(Datei, ",\n\taddress = {%s}", tmp[i].address);
					}
					if (strcmp(tmp[i].edition, "0") != 0) {
						fprintf(Datei, ",\n\tedition = {%s}", tmp[i].edition);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case incollection: {
					fprintf(Datei, "@incollection{%s,\n\tauthor = {%s, %s},\n\ttitle = {%s},\n\tbooktitle = {%s},\n\tpublisher = {%s},\n\tyear = {%s}", tmp[i].keyword, tmp[i].author.nachname, tmp[i].author.vorname, tmp[i].title, tmp[i].booktitle, tmp[i].publisher, tmp[i].year);
					if (strcmp(tmp[i].editor, "0") != 0) {
						fprintf(Datei, ",\n\teditor = {%s}", tmp[i].editor);
					}
					if (strcmp(tmp[i].chapter, "0") != 0) {
						fprintf(Datei, ",\n\tchapter = {%s}", tmp[i].chapter);
					}
					if (strcmp(tmp[i].pages, "0") != 0) {
						fprintf(Datei, ",\n\tpages = {%s}", tmp[i].pages);
					}
					if (strcmp(tmp[i].address, "0") != 0) {
						fprintf(Datei, ",\n\taddress = {%s}", tmp[i].address);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case conference: {
					fprintf(Datei, "@conference{%s,\n\tauthor = {%s, %s},\n\ttitle = {%s},\n\tbooktitle = {%s},\n\tyear = {%s}", tmp[i].keyword, tmp[i].author.nachname, tmp[i].author.vorname, tmp[i].title, tmp[i].booktitle, tmp[i].year);
					if (strcmp(tmp[i].editor, "0") != 0) {
						fprintf(Datei, ",\n\teditor = {%s}", tmp[i].editor);
					}
					if (strcmp(tmp[i].pages, "0") != 0) {
						fprintf(Datei, ",\n\tpages = {%s}", tmp[i].pages);
					}
					if (strcmp(tmp[i].organization, "0") != 0) {
						fprintf(Datei, ",\n\torganization = {%s}", tmp[i].organization);
					}
					if (strcmp(tmp[i].publisher, "0") != 0) {
						fprintf(Datei, ",\n\tpublisher = {%s}", tmp[i].publisher);
					}
					if (strcmp(tmp[i].address, "0") != 0) {
						fprintf(Datei, ",\n\taddress = {%s}", tmp[i].address);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case proceedings: {
					fprintf(Datei, "@proceedings{%s,\n\ttitle = {%s},\n\tyear = {%s}", tmp[i].keyword, tmp[i].title, tmp[i].year);
					if (strcmp(tmp[i].editor, "0") != 0) {
						fprintf(Datei, ",\n\teditor = {%s}", tmp[i].editor);
					}
					if (strcmp(tmp[i].publisher, "0") != 0) {
						fprintf(Datei, ",\n\tpublisher = {%s}", tmp[i].publisher);
					}
					if (strcmp(tmp[i].organization, "0") != 0) {
						fprintf(Datei, ",\n\torganization = {%s}", tmp[i].organization);
					}
					if (strcmp(tmp[i].address, "0") != 0) {
						fprintf(Datei, ",\n\taddress = {%s}", tmp[i].address);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case inproceedings: {
					fprintf(Datei, "@inproceedings{%s,\n\tauthor = {%s, %s},\n\ttitle = {%s},\n\tbooktitle = {%s},\n\tyear = {%s}", tmp[i].keyword, tmp[i].author.nachname, tmp[i].author.vorname, tmp[i].title, tmp[i].booktitle, tmp[i].year);
					if (strcmp(tmp[i].editor, "0") != 0) {
						fprintf(Datei, ",\n\teditor = {%s}", tmp[i].editor);
					}
					if (strcmp(tmp[i].pages, "0") != 0) {
						fprintf(Datei, ",\n\tpages = {%s}", tmp[i].pages);
					}
					if (strcmp(tmp[i].organization, "0") != 0) {
						fprintf(Datei, ",\n\torganization = {%s}", tmp[i].organization);
					}
					if (strcmp(tmp[i].publisher, "0") != 0) {
						fprintf(Datei, ",\n\tpublisher = {%s}", tmp[i].publisher);
					}
					if (strcmp(tmp[i].address, "0") != 0) {
						fprintf(Datei, ",\n\taddress = {%s}", tmp[i].address);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case manual: {
					fprintf(Datei, "@manual{%s,\n\ttitle = {%s}", tmp[i].keyword, tmp[i].title);
					if ((strcmp(tmp[i].author.nachname, "0") != 0) && (strcmp(tmp[i].author.vorname, "0") != 0)) {
						fprintf(Datei, ",\n\tauthor = {%s, %s}", tmp[i].author.nachname, tmp[i].author.vorname);
					}
					else if (strcmp(tmp[i].author.nachname, "0") != 0) {
						fprintf(Datei, ",\n\tauthor = {%s}", tmp[i].author.nachname);
					}
					if (strcmp(tmp[i].organization, "0") != 0) {
						fprintf(Datei, ",\n\torganization = {%s}", tmp[i].organization);
					}
					if (strcmp(tmp[i].address, "0") != 0) {
						fprintf(Datei, ",\n\taddress = {%s}", tmp[i].address);
					}
					if (strcmp(tmp[i].edition, "0") != 0) {
						fprintf(Datei, ",\n\tedition = {%s}", tmp[i].edition);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].year, "0") != 0) {
						fprintf(Datei, ",\n\tyear = {%s}", tmp[i].year);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case masterthesis: {
					fprintf(Datei, "@masterthesis{%s,\n\tauthor = {%s, %s},\n\ttitle = {%s},\n\tschool = {%s},\n\tyear = {%s}", tmp[i].keyword, tmp[i].author.nachname, tmp[i].author.vorname, tmp[i].title, tmp[i].school, tmp[i].year);
					if (strcmp(tmp[i].address, "0") != 0) {
						fprintf(Datei, ",\n\taddress = {%s}", tmp[i].address);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case phdthesis: {
					fprintf(Datei, "@phdthesis{%s,\n\tauthor = {%s, %s},\n\ttitle = {%s},\n\tschool = {%s},\n\tyear = {%s}", tmp[i].keyword, tmp[i].author.nachname, tmp[i].author.vorname, tmp[i].title, tmp[i].school, tmp[i].year);
					if (strcmp(tmp[i].address, "0") != 0) {
						fprintf(Datei, ",\n\taddress = {%s}", tmp[i].address);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case techreport: {
					fprintf(Datei, "@techreport{%s,\n\tauthor = {%s, %s},\n\ttitle = {%s},\n\tinstitution = {%s},\n\tyear = {%s}", tmp[i].keyword, tmp[i].author.nachname, tmp[i].author.vorname, tmp[i].title, tmp[i].institution, tmp[i].year);
					if (strcmp(tmp[i].type, "0") != 0) {
						fprintf(Datei, ",\n\ttype = {%s}", tmp[i].type);
					}
					if (strcmp(tmp[i].number, "0") != 0) {
						fprintf(Datei, ",\n\tnumber = {%s}", tmp[i].number);
					}
					if (strcmp(tmp[i].address, "0") != 0) {
						fprintf(Datei, ",\n\taddress = {%s}", tmp[i].address);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case unpublished: {
					fprintf(Datei, "@unpublished{%s,\n\tauthor = {%s, %s},\n\ttitle = {%s},\n\tnote = {%s}", tmp[i].keyword, tmp[i].author.nachname, tmp[i].author.vorname, tmp[i].title, tmp[i].note);
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].year, "0") != 0) {
						fprintf(Datei, ",\n\tyear = {%s}", tmp[i].year);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				case misc: {
					fprintf(Datei, "@misc{%s", tmp[i].keyword);
					if ((strcmp(tmp[i].author.nachname, "0") != 0) && (strcmp(tmp[i].author.vorname, "0") != 0)) {
						fprintf(Datei, ",\n\tauthor = {%s, %s}", tmp[i].author.nachname, tmp[i].author.vorname);
					}
					else if (strcmp(tmp[i].author.nachname, "0") != 0) {
						fprintf(Datei, ",\n\tauthor = {%s}", tmp[i].author.nachname);
					}
					if (strcmp(tmp[i].title, "0") != 0) {
						fprintf(Datei, ",\n\ttitle = {%s}", tmp[i].title);
					}
					if (strcmp(tmp[i].howpublished, "0") != 0) {
						fprintf(Datei, ",\n\thowpublished = {%s}", tmp[i].howpublished);
					}
					if (strcmp(tmp[i].month, "0") != 0) {
						fprintf(Datei, ",\n\tmonth = {%s}", tmp[i].month);
					}
					if (strcmp(tmp[i].year, "0") != 0) {
						fprintf(Datei, ",\n\tyear = {%s}", tmp[i].year);
					}
					if (strcmp(tmp[i].note, "0") != 0) {
						fprintf(Datei, ",\n\tnote = {%s}", tmp[i].note);
					}
					fprintf(Datei, "\n}\n\n");
					break;
				}
				}
				anz++;
			}
		}
		fclose(Datei);				//Datei schließen
	}

	//Ausgabe beim Scheitern
	else {
		printf("\nFehler beim Exportieren... ");
	}
	printf("Es wurden %i Datensaetze exportiert!\n\nZurueck...", anz);
	getchar();
}

//Funktion zum Durchsuchen der Datensätze
void suchen(Daten *Datensatz) {
	//Variablendeklaration
	char sbegriff[100];
	int i, erg = 0;

	//Suchbegriff eingeben
	clear();
	printf("Datensaetze durchsuchen.\n\nGeben Sie hier einen Suchbegriff ein. Es werden alle belegten Datensaetze vollstaendig durchsucht.\n");
	printf("Achtung: Gross- und Kleinschreibung wird unterschieden!\n\nSuchbegriff: ");
	do {
		fgets(sbegriff, 100, stdin);
		entf(sbegriff);
		if (strlen(sbegriff) == 0) {
			clear();
			printf("Datensaetze durchsuchen.\n\nGeben Sie einen Suchbegriff ein: ");
		}
	} while (strlen(sbegriff) < 1);

	//Jeden belegten Datensatz durchgehen und nach 'sbegriff' suchen
	for (i = 0; i < 1000; i++) {
		if (Datensatz[i].belegt == 1) {
			if ((strstr(Datensatz[i].address, sbegriff) != NULL) || 
				(strstr(Datensatz[i].author.nachname, sbegriff) != NULL) ||
				(strstr(Datensatz[i].author.vorname, sbegriff) != NULL) ||
				(strstr(Datensatz[i].booktitle, sbegriff) != NULL) ||
				(strstr(Datensatz[i].chapter, sbegriff) != NULL) || 
				(strstr(Datensatz[i].edition, sbegriff) != NULL) ||
				(strstr(Datensatz[i].editor, sbegriff) != NULL) ||
				(strstr(Datensatz[i].howpublished, sbegriff) != NULL) ||
				(strstr(Datensatz[i].institution, sbegriff) != NULL) ||
				(strstr(Datensatz[i].journal, sbegriff) != NULL) ||
				(strstr(Datensatz[i].month, sbegriff) != NULL) ||
				(strstr(Datensatz[i].note, sbegriff) != NULL) ||
				(strstr(Datensatz[i].number, sbegriff) != NULL) ||
				(strstr(Datensatz[i].organization, sbegriff) != NULL) ||
				(strstr(Datensatz[i].pages, sbegriff) != NULL) ||
				(strstr(Datensatz[i].publisher, sbegriff) != NULL) ||
				(strstr(Datensatz[i].school, sbegriff) != NULL) ||
				(strstr(Datensatz[i].series, sbegriff) != NULL) ||
				(strstr(Datensatz[i].title, sbegriff) != NULL) ||
				(strstr(Datensatz[i].type, sbegriff) != NULL) ||
				(strstr(Datensatz[i].volume, sbegriff) != NULL) ||
				(strstr(Datensatz[i].year, sbegriff) != NULL) ||
				(strstr(Datensatz[i].keyword, sbegriff)!=NULL)) {
				clear();

				//Suchergebnis ausgeben:
				printf("Datensaetze durchsuchen.\n\nErgebnis %i - Datensatz %i:\n", erg + 1, i);
				ausgeben(Datensatz[i]);
				printf("\nWeitersuchen... ");
				erg++;
				getchar();
			}
		}
	}
	printf("\nSuche abgeschlossen!\nEs wurden %i Suchergebnisse gefunden.\n\nZurueck... ", erg);
	getchar();
}
