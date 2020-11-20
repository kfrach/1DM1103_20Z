#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dziekanat.h"

#include "studenci.h"



int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    // dane == &dane[0]
    ile = wczytaj(dane, argv[1]);
    
    if (argc == 3)
        {   
            if ( strcmp( argv[2], "przedmiot") == 0) 
            {
                najlepszy_przedmiot(dane, ile);
                
            } 
    
            else if ( strcmp( argv[2], "student") == 0) 
            {
                najlepszy_student(dane, ile);
            } 
            
        } else 
            {
            printf("Błąd: Podaj dodatkowo komende: przedmiot lub student\n");
            }
    
    

    return 0;
}