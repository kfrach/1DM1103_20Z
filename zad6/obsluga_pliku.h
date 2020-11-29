#ifndef _OBSLUGA_PLIKU_H
#define _OBSLUGA_PLIKU_H

#include "operacje_matematyczne.h"


struct Macierz {
    int r;
    int c;
    float **tab;
};


void wczytaj(char nazwa[], struct Macierz *m);
void zapisz(char nazwa[], struct Macierz m);
void wypisz(struct Macierz C);
void zwolnij(struct Macierz *m);

#endif