#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void wczytaj(FILE * fin, float tab[200][20], int *r, int *c ) {
    int i,j;
    fscanf(fin, "%d", r);
    fscanf(fin, "%d", c);

    for (i=0; i < (*r); i++) {
        for (j=0; j < (*c); j++) {
            fscanf(fin, "%f", &tab[i][j]);
        }
    }
}

void wypisz(float tab[200][20], int r, int c) {
    int i, j;
    printf("[ ");
    for (i = 0; i < r; i++) {
        for (j=0; j < c; j++) {
            printf("%5.1f ", tab[i][j]);
        }
        if (i < (r-1))
            printf("\n  ");
    }
    printf("]\n");
}

float norm(float tab[200][20], int c, int r) {
    float s = 0;
    int i,j;

    for (i = 0; i < r; i++) {
        for (j=0; j < c; j++) {
            s += tab[i][j] * tab[i][j];
        }
    }
    return sqrt(s);
}

// wczytaj plik repezentujacy dwuwymiarowa macierz
// r
// c
// liczby....
int main(int argc, char *argv[]) {
    int r;
    int c;
    float tab[200][20];
    FILE * fin = fopen(argv[1], "r");

    wczytaj(fin, tab, &r, &c);
    wypisz(tab,r,c);
    
    printf("Norma macierzy %s = %f\n", argv[1], norm(tab,c,r));

    fclose(fin);
    return 0;
}