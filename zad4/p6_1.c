/**
Mamy mini bazę studentów (tabelę z studentami, przedmiotami i ocenami)
Cel: obliczyć ranking.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

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



int znajdz(char *szukany_przedmiot, char nazwa_przed[100][255], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_przedmiot, nazwa_przed[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_przedmioty(char nazwa_przed[100][255], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].nazwa_przed, nazwa_przed, ile_znalazlem ) == -1) {
            strncpy(nazwa_przed[ile_znalazlem], dane[i].nazwa_przed, 244);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}


void najlepszy_przedmiot(student dane[100], int ile_rekordow) {
    char nazwa_przedmiotow[100][255];
    char kod_przedmiotow[100][10];
    int ile_przedmiotow=0;
    
    float sumy_wazonych_ocen[100];
    int i;
    int pozycja=0;
    int najlepsza_pozycja=0;
    int najgorsza_pozycja=0;
    float najlepsza = 0.0f;
    float najgorsza = 0.0f;
    int liczba_ocen[10];

    ile_przedmiotow = znajdz_przedmioty(nazwa_przedmiotow, dane, ile_rekordow);
    

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].nazwa_przed, nazwa_przedmiotow, ile_przedmiotow );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena;
        liczba_ocen[pozycja] = liczba_ocen[pozycja] +1;
        strcpy(kod_przedmiotow[pozycja] ,dane[i].kod_przed);
    }    


    for (i=0; i < ile_przedmiotow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / liczba_ocen[i]) {
            najlepsza = sumy_wazonych_ocen[i] / liczba_ocen[i];
            najlepsza_pozycja = i;
        
        }
    
    
        if (najgorsza > sumy_wazonych_ocen[i] / liczba_ocen[i]) {
            najgorsza = sumy_wazonych_ocen[i] / liczba_ocen[i];
            najgorsza_pozycja = i;
        }
    } 
    
    printf("Najlepsza średnia: %s - %s: %f\n ", 
        nazwa_przedmiotow[najlepsza_pozycja], kod_przedmiotow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / liczba_ocen[najlepsza_pozycja]
    );
    printf("Najgorsza średnia: %s - %s: %f\n ", 
        nazwa_przedmiotow[najgorsza_pozycja], kod_przedmiotow[najgorsza_pozycja],
        sumy_wazonych_ocen[najgorsza_pozycja] / liczba_ocen[najgorsza_pozycja]
    );

}

void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].nr_albumu, nr_albumow, ile_studentow );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    for (i=0;i<ile_studentow; i++) 
        printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], 
        sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );

}

int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    // dane == &dane[0]
    ile = wczytaj(dane, argv[1]);
    

    najlepszy_przedmiot(dane, ile);
    najlepszy_student(dane, ile);

    return 0;
}