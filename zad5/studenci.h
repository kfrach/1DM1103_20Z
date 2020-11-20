#ifndef _STUDENCI_H
#define _STUDENCI_H

#include "dziekanat.h"


typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

int wczytaj(student dane[100], char *fnazwa);
int p_znajdz(char *szukany_przedmiot, char nazwa_przed[100][255], int n);
int s_znajdz(char *szukany_nr, char nr_albumow[100][10], int n);
int znajdz_przedmioty(char nazwa_przed[100][255], student dane[100], int n);
int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n);

#endif