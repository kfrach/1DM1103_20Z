#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *poprz;
    struct _Student *nast;
} Student;

typedef struct _Przedmiot {
    char * nazwa;
    char * kod_przedmiotu;
    char * semestr;

    struct _Przedmiot *poprz;
    struct _Przedmiot *nast;
 } Przedmiot;


typedef struct _Ocena {
    char * nr_albumu;
    char * kod_przedmiotu;
    float ocena;
    char * komentarz;


    struct _Ocena *poprz;
    struct _Ocena *nast;
 } Ocena;


typedef struct _SBaza {
    Student *lista_studentow; 
} SBaza;

typedef struct _PBaza {
    Przedmiot *lista_przedmiotow; 
} PBaza;

typedef struct _OBaza {
    Ocena *lista_ocen; 
} OBaza;


SBaza * wczytaj_bazeS(char *nazwa_pliku);
PBaza * wczytaj_bazeP(char *nazwa_pliku);
OBaza * wczytaj_bazeO(char *nazwa_pliku);


Student * dodaj_studenta(SBaza *baza, char  *imie, char  *nazwisko, char *numer, char  *email);
Przedmiot * dodaj_przedmiot(PBaza *baza, char  *nazwa, char  *kod_przedmiotu, char *semestr);
Ocena * dodaj_ocene(OBaza *baza, char  *nr_albumu, char  *kod_przedmiotu, char  *ocena, char *komentarz);


int ile_studentow(SBaza *baza);
int ile_przedmiotow(PBaza *baza);
int ile_ocen(OBaza *baza);

void listuj_studentow(SBaza *baza);
void listuj_przedmioty(PBaza *baza);
void listuj_oceny(OBaza *baza);



Student * sortuj_studentow_przez_wybieranie(Student *glowa);
Przedmiot * sortuj_przedmioty_przez_wybieranie_nazwa(Przedmiot *glowa);
Przedmiot * sortuj_przedmioty_przez_wybieranie_kod(Przedmiot *glowa);

void zapisz_baze(char *nazwa_pliku, SBaza * bazaS,PBaza * bazaP,OBaza * bazaO);

void zwolnijS(SBaza *baza);
void zwolnijP(PBaza *baza);
void zwolnijO(OBaza *baza);

#endif