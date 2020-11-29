#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "obsluga_pliku.h"
#include "operacje_matematyczne.h"


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

    zwolnij(&A);
    zwolnij(&B);
    zwolnij(&C);
    
    return 0;
}