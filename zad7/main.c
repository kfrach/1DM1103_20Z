#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

int main(int argc, char ** argv)
 {
    SBaza *bazaS;
    PBaza *bazaP;
    OBaza *bazaO;


    bazaS = wczytaj_bazeS(argv[1]);
    bazaP = wczytaj_bazeP(argv[1]);
    bazaO = wczytaj_bazeO(argv[1]);
    
    printf("Jako 3 argument możesz podać:\nadd_student\nlist_students\ncount_students\nadd_subjects\nlist_subjects\ncount_subjects\nadd_scores\nlist_scores\ncount_scores\n");
    
    
    if (strcmp("list_students", argv[2]) == 0) {
        listuj_studentow(bazaS);
    } else if (strcmp("add_student", argv[2]) == 0) {
        bazaS ->lista_studentow = dodaj_studenta(bazaS, argv[3], argv[4], argv[5], argv[6]);
    } else if (strcmp("count_students", argv[2]) == 0) {
        printf("Liczba studentów: %d\n", ile_studentow(bazaS));
    } else if (strcmp("list_subjects", argv[2]) == 0) {
        listuj_przedmioty(bazaP);
    } else if (strcmp("count_subjects", argv[2]) == 0) {
        printf("Liczba przedmiotów: %d\n", ile_przedmiotow(bazaP));
    } else if (strcmp("list_scores", argv[2]) == 0) {
        listuj_oceny(bazaO);
    } else if (strcmp("count_scores", argv[2]) == 0) {
        printf("Liczba ocen: %d\n", ile_ocen(bazaO));
    } else if (strcmp("add_subjects", argv[2]) == 0) {
        bazaP ->lista_przedmiotow = dodaj_przedmiot(bazaP, argv[3], argv[4], argv[5]);
    } else if (strcmp("add_scores", argv[2]) == 0) {
        bazaO ->lista_ocen = dodaj_ocene(bazaO, argv[3], argv[4], argv[5], argv[6]);
    } 
    

    

    zapisz_baze(argv[1],bazaS,bazaP,bazaO);

    
    
    zwolnijS(bazaS);
    zwolnijP(bazaP);
    zwolnijO(bazaO);

    return 0;
}
