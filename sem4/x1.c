#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wczytaj(FILE *fin, float *tablica) {
    
    int dlugosc = 0;
    int i;
    float liczba;
    int s = 0;
    int d = 0;
    

    fscanf(fin, "%d", &dlugosc);
    d = tablica[0];
    s = tablica[1];
        
    for (i=0; i <(d*s)+2; i++) {
        fscanf(fin, "%f", &liczba);
        tablica[i] = liczba;
    }

    return dlugosc;
}

int wczytaj_szerokosc(FILE *fin, float *tablica) {
    
    int dlugosc = 0;
    int i;
    int szerokosc = 0;

    fscanf(fin, "%d", &dlugosc);

    szerokosc = tablica[1];
    

    return szerokosc;
}



//float suma(float *tablica, int dlugosc) {
//    float suma = 0;
//    for (int i=0; i < dlugosc; i++) {
//        suma += tablica[i];
//    }
//
//    return suma;
//}

void wypisz_wektor(float *w, int n) {
    printf("(%d) [", n);
    for (int j=0; j<n; j++)
        printf("%f ", w[j]);
    printf("]\n");
}

// wczytal z pliku wektor liczb i wyswietli na ekranie ich sume!
int main(int argc, char *argv[]) {
    FILE *fin; //
    float wektor[100];
    int dlugosc;
    int szerokosc;

    fin = fopen( argv[1], "r");
    dlugosc = wczytaj(fin, wektor);
    szerokosc = wczytaj_szerokosc(fin, wektor);
    printf("%d %d\n", dlugosc, szerokosc);

    wypisz_wektor(wektor, dlugosc*szerokosc);

 //   printf("Suma %d liczb z pliku %s: %f\n", dlugosc, argv[1], suma(wektor, dlugosc));

    return 0;
}