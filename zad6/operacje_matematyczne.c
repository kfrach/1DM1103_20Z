#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "operacje_matematyczne.h"
#include "obsluga_pliku.h"

float norm(struct Macierz A) {
    float s = 0;
    int i,j;

    for (i = 0; i < A.r; i++) {
        for (j=0; j < A.c; j++) {
            s += A.tab[i][j] * A.tab[i][j];
        }
    }
    return sqrt(s);
}

void sum(struct Macierz A, struct Macierz B, struct Macierz *C)
{
    int i,j;
    float l;
    C->c = A.c;
    C->r = A.r;

    C->tab = (float**) malloc(sizeof(float*) * C->r);
    for (i=0;i<C->r;i++) {
        C->tab[i] = (float*) malloc(sizeof(float) * C->c);
        for (j=0;j< C->c; j++)
            C->tab[i][j] = j+1+i;
    }

    if((A.r != B.r) || (A.c != B.c))
    {
        printf("Błąd: Rozmiary macierzy nie są sobie równe\n");
    }
    else
    {
        for (i = 0; i < A.r; i++)
        {
            for (j = 0; j < A.c; j++)
            {
                l = A.tab[i][j] + B.tab[i][j];
                C -> tab[i][j] = l;
                
            }
        }
    }
    
}

void subtract(struct Macierz A, struct Macierz B, struct Macierz *C)
{
    int i,j;
    float l;
    C->c = A.c;
    C->r = A.r;

    C->tab = (float**) malloc(sizeof(float*) * C->r);
    for (i=0;i<C->r;i++) {
        C->tab[i] = (float*) malloc(sizeof(float) * C->c);
        for (j=0;j< C->c; j++)
            C->tab[i][j] = j+1+i;
    }

    if((A.r != B.r) || (A.c != B.c))
    {
        printf("Błąd: Rozmiary macierzy nie są sobie równe\n");
    }
    else
    {
        for (i = 0; i < A.r; i++)
        {
            for (j = 0; j < A.c; j++)
            {
                l = A.tab[i][j] - B.tab[i][j];
                C -> tab[i][j] = l;
            }
        }
    }
    
}

void prod(struct Macierz A, struct Macierz B, struct Macierz *C)
{
    int i,j,k;
    float l;
    C->c = A.c;
    C->r = A.r;

    C->tab = (float**) malloc(sizeof(float*) * C->r);
    for (i=0;i<C->r;i++) {
        C->tab[i] = (float*) malloc(sizeof(float) * C->c);
        for (j=0;j< C->c; j++)
            C->tab[i][j] = j+1+i;
    }

    if(A.c != B.r)
    {
        printf("Błąd: Rozmiary macierzy są nieprawidłowe\n");
    }
    else
    {
        for (i = 0; i < A.r; i++)
        {
            for (j = 0; j < B.c; j++)
            {
                for (k = 0; k < B.r; k++){

                    l = l + (A.tab[i][k] * B.tab[k][j]);

                    C -> tab[i][j] = l;
                }
            
            }
        }
    }
    
}

void multiply(struct Macierz A, struct Macierz *C, float x)
{
    int i,j;
    float l;
    C->c = A.c;
    C->r = A.r;

    C->tab = (float**) malloc(sizeof(float*) * C->r);
    for (i=0;i<C->r;i++) {
        C->tab[i] = (float*) malloc(sizeof(float) * C->c);
        for (j=0;j< C->c; j++)
            C->tab[i][j] = j+1+i;
    }

    for (i = 0; i < A.r; i++)
        {
            for (j = 0; j < A.c; j++)
            {
                l = A.tab[i][j] * x;
                C -> tab[i][j] = l;
            }
        }
}