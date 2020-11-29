#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "obsluga_pliku.h"
#include "operacje_matematyczne.h"


void wczytaj(char nazwa[], struct Macierz *m) {
    FILE * fin = fopen(nazwa, "r");
    int i,j;
    
    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);


    m->tab = (float**) malloc(sizeof(float*) * m->r);
    for (i=0;i<m->r;i++) {
        m->tab[i] = (float*) malloc(sizeof(float) * m->c);
        for (j=0;j< m->c; j++)
            m->tab[i][j] = j+1+i;
    }

    for (i=0; i < m->r; i++) {
        for (j=0; j < m->c; j++) {
            fscanf(fin, "%f", &m->tab[i][j]);
        }
    }
}

void zapisz(char nazwa[], struct Macierz m) {
    FILE * fout = fopen(nazwa, "w");
    int i,j;

    fprintf(fout, "%d\n%d\n", m.r, m.c);
    for (i = 0; i < m.r; i++) {
        for (j=0; j < m.c; j++) {
            fprintf(fout, "%f\n", m.tab[i][j]);
        }
    }

    fclose(fout);
}

void wypisz(struct Macierz C) {
    int i, j;
    printf("[ ");
    for (i = 0; i < C.r; i++) {
        for (j=0; j < C.c; j++) {
            printf("%5.1f ", C.tab[i][j]);
        }
        if (i < (C.r-1))
            printf("\n  ");
    }
    printf("]\n");
}

void zwolnij(struct Macierz *m) {
    int i;
    for (i=0;i<m->r;i++){
        free( m->tab[i] );
    } 
        
    free(m->tab);
    free(m);

    
}