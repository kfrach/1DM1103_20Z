#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dziekanat.h"

#include "studenci.h"

int wczytaj(student dane[100], char *fnazwa) {
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}



int p_znajdz(char *szukany_przedmiot, char nazwa_przed[100][255], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_przedmiot, nazwa_przed[i]) == 0)
            return i;
    }
    return -1;
}

int s_znajdz(char *szukany_nr, char nr_albumow[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, nr_albumow[i]) == 0)
            return i;
    }
    return -1;
}



int znajdz_przedmioty(char nazwa_przed[100][255], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (p_znajdz(dane[i].nazwa_przed, nazwa_przed, ile_znalazlem ) == -1) {
            strncpy(nazwa_przed[ile_znalazlem], dane[i].nazwa_przed, 244);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}
int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (s_znajdz(dane[i].nr_albumu, nr_albumow, ile_znalazlem ) == -1) {
            strncpy(nr_albumow[ile_znalazlem], dane[i].nr_albumu, 9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}
