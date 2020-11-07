#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Macierz {
    int r;
    int c;
    float tab[20][20];
};

void wczytaj(char nazwa[], struct Macierz *m) {
    FILE * fin = fopen(nazwa, "r");
    int i,j;
    
    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);

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
    for (i = 0; i < A.r; i++)
        {
            for (j = 0; j < A.c; j++)
            {
                l = A.tab[i][j] * x;
                C -> tab[i][j] = l;
            }
        }
}

int main(int argc, char *argv[]) {
    
    struct Macierz A;
    wczytaj(argv[2], &A);
    struct Macierz B;
    struct Macierz C;

    if ( strcmp( argv[1], "sum") == 0) 
    {
        wczytaj(argv[3], &B);
        sum(A,B,&C);
        if (argc == 5)
        {
            zapisz(argv[4], C);
        }   else 
            {
                wypisz(C);
            }
    } 
    
    else if ( strcmp( argv[1], "subtract") == 0) 
    {
        wczytaj(argv[3], &B);
        subtract(A,B,&C);
        if (argc == 5)
        {
            zapisz(argv[4], C);
        }   else 
            {
                wypisz(C);
            }
    }    
    else if ( strcmp( argv[1], "prod") == 0) 
    {
        wczytaj(argv[3], &B);
        prod(A,B,&C);
        if (argc == 5)
        {
            zapisz(argv[4], C);
        }   else 
            {
                wypisz(C);
            }
    }
    else if ( strcmp( argv[1], "multiply") == 0) 
    {
        multiply(A, &C, atof(argv[3]));
        if (argc == 5)
        {
            zapisz(argv[4], C);
        }   else 
            {
                wypisz(C);
            }
    }
    else if ( strcmp( argv[1], "norm") == 0) 
    {
        float norma;
        norma = norm(A);
        if (argc == 4)
        {
            FILE * fin = fopen(argv[3], "w");
            fprintf(fin,"[%f]", norma);
        }
           else 
            {
                printf("Norma podanej macierzy = [%f]", norma);
            }
    }
    else {
        printf("Błąd: Podaj inna wartosc");
    }

    return 0;
}