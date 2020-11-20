#include <stdio.h>
#include <stdlib.h>


void wczytaj(char *nazwa_pliku,int dlugosc, int szerokosc, float macierz[dlugosc][szerokosc])
{
    FILE *fin;
    fin = fopen(nazwa_pliku, "r");   
    float wartosc;
    int i;
    int j;
    for(i=1; i < szerokosc + 3; i++)
    {   if (i < 3)
        fscanf(fin, "%f", &wartosc);
         else 
         {
            for(j=0; j<dlugosc; j++)            
            fscanf(fin, "%f", &macierz[i-3][j]);                
         }
    }  
}

int dlugosc(char *nazwa_pliku)
{
    int dlugosc;
    int szerokosc;
    FILE *fin;
    fin = fopen(nazwa_pliku, "r");  
    fscanf(fin, "%d %d", &dlugosc, &szerokosc);    
    return dlugosc;

}

int szerokosc(char *nazwa_pliku)
{
    int dlugosc;
    int szerokosc;
    FILE *fin;
    fin = fopen(nazwa_pliku, "r");      
    fscanf(fin, "%d %d", &dlugosc, &szerokosc);    
    return szerokosc;
}





int main(int argc, char *argv[])
{   
    int wiersze_macierz = dlugosc(argv[1]);
    int kolumny_macierz = szerokosc(argv[1]);
    float macierz[wiersze_macierz][kolumny_macierz];
    wczytaj(argv[1],wiersze_macierz, kolumny_macierz, macierz);


    int wiersze_wektor = dlugosc(argv[2]);
    int kolumny_wektor = szerokosc(argv[2]);
    float wektor[wiersze_macierz][kolumny_wektor];
    wczytaj(argv[2],wiersze_wektor, kolumny_wektor, wektor);

    
    int i;
    int j;
    int l;
    float suma = 0;
    
    float wynik[wiersze_macierz][kolumny_wektor];
       
    for(i=0; i < wiersze_macierz ; i++)
    {
        for(j=0; j < kolumny_wektor; j++)        
        {
            for (l=0; l < wiersze_macierz; l++)
            {
                suma += macierz[i][l] * wektor[j][l];
            }
            wynik[i][j] = suma;
            suma = 0;
        }
    }
    
    printf("(%d)", wiersze_macierz);
    printf("[");
    for (i=0; i < wiersze_macierz; i++)
    {            
        for (j=0; j < kolumny_wektor; j++) 
        printf(" %lf ",wynik[i][j]);
    }
    printf("]\n");
    
    
   
    
    

    return 0;