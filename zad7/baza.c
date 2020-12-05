#include "baza.h"

Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}


Przedmiot * wczytaj_przedmioty(FILE *fin)
 {
    char bufor[255];
    int n, i, l;
    char *s;
    Przedmiot *last_student = NULL;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);   
    for(int k =0; k<n; k++)
    {
    fgets(bufor, 254, fin);
    }    
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &l); 

    for (i=0; i<l; i++)
    {
        Przedmiot *stud = (Przedmiot*) malloc(sizeof(Przedmiot));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->kod_przedmiotu, s);       

        s = strtok(NULL, ";");
        stud->nazwa = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwa, s);

        s = strtok(NULL, "\n");
        stud->semestr = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->semestr, s);

        
    }

    return glowa;
}

Ocena * wczytaj_ocene(FILE *fin) {
    char bufor[255];
    int n, i, l, nn;
    char *s;
    Ocena *last_student = NULL;
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for(int k =0; k<n; k++)
    {
    fgets(bufor, 254, fin);
    }    
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &l);

    for(int o = 0; o<l; o++)
    {
    fgets(bufor, 254, fin);
    }
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &nn); 

    for (i=0; i<nn; i++) {
        Ocena *stud = (Ocena*) malloc(sizeof(Ocena));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->kod_przedmiotu, s);
       

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, ";");        
        stud->ocena=atof(s);

        s = strtok(NULL, "\n");
        stud->komentarz = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->komentarz, s);
    }

    return glowa;
}


SBaza * wczytaj_bazeS(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);

    fclose(fin);
    return baza;
}
PBaza * wczytaj_bazeP(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    PBaza *baza = (PBaza*) malloc( sizeof(PBaza) );
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);

    fclose(fin);
    return baza;
}
OBaza * wczytaj_bazeO(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    OBaza *baza = (OBaza*) malloc( sizeof(OBaza) );
    baza->lista_ocen = wczytaj_ocene(fin);

    fclose(fin);
    return baza;
}



Student * dodaj_studenta(SBaza *baza, char  *imie, char  *nazwisko, char *numer, char  *email)
{
    
    Student *glowa = NULL;

    Student *nowy = (Student*) malloc(sizeof(Student));

    nowy->imie = imie;
    nowy->nazwisko = nazwisko;
    nowy->nr_albumu = numer;
    nowy->email = email; 
    nowy->nast = baza->lista_studentow;  
    glowa = nowy;
    
    return glowa;
    
    
}

Przedmiot * dodaj_przedmiot(PBaza *baza, char  *nazwa, char  *kod_przedmiotu, char *semestr)
{

    
    Przedmiot *glowa = NULL;

    Przedmiot *nowy = (Przedmiot*) malloc(sizeof(Przedmiot));

    nowy->nazwa = nazwa;
    nowy->kod_przedmiotu = kod_przedmiotu;
    nowy->semestr = semestr;
    nowy->nast = baza->lista_przedmiotow;
    glowa = nowy;
    
    return glowa;
    
    
}

Ocena * dodaj_ocene(OBaza *baza, char  *nr_albumu, char  *kod_przedmiotu, char  *ocena, char *komentarz)
{

    
    Ocena *glowa = NULL;

    Ocena *nowy = (Ocena*) malloc(sizeof(Ocena));

    nowy->nr_albumu = nr_albumu;
    nowy->kod_przedmiotu = kod_przedmiotu;
    nowy->ocena = atof(ocena);
    nowy->nast = baza->lista_ocen; 
    glowa = nowy;
    
    return glowa;
    
    
}




int ile_studentow(SBaza *baza) {
    int n = 0;
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

int ile_przedmiotow(PBaza *baza) {
    int n = 0;
    Przedmiot * stud = baza->lista_przedmiotow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

int ile_ocen(OBaza *baza) {
    int n = 0;
    Ocena * stud = baza->lista_ocen;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

void listuj_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void listuj_przedmioty(PBaza *baza) {
    Przedmiot * stud = baza->lista_przedmiotow;
    while (stud != NULL) {
        printf("%s %s %s \n", stud->nazwa, stud->kod_przedmiotu, stud->semestr);
        stud = stud->nast;
    }
}


void listuj_oceny(OBaza *baza) {
    Ocena * stud = baza->lista_ocen;
    while (stud != NULL) {
        printf("%s %s %f %s\n", stud->kod_przedmiotu, stud->nr_albumu, stud->ocena, stud->komentarz);
        stud = stud->nast;
    }
}

void zapisz_baze(char *nazwa_pliku, SBaza * bazaS,PBaza * bazaP,OBaza * bazaO) {
    int s,p,o;
    FILE *fin = fopen(nazwa_pliku, "w");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }
    Student * stud = bazaS->lista_studentow;
    Przedmiot * przed = bazaP->lista_przedmiotow;
    Ocena * ocena = bazaO->lista_ocen;

    s=ile_studentow(bazaS);
    p=ile_przedmiotow(bazaP);
    o=ile_ocen(bazaO);   

    fprintf(fin,"%d\n",s);
    while (stud != NULL) {
        fprintf(fin,"%s;%s;%s;%s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
    fprintf(fin,"%d\n",p);
    while (przed != NULL) {
        fprintf(fin,"%s;%s;%s\n", przed->nazwa, przed->kod_przedmiotu, przed->semestr);
        przed = przed->nast;
    }
    fprintf(fin,"%d\n",o);
    while (ocena != NULL) {
        fprintf(fin,"%s;%s;%f;%s\n", ocena->kod_przedmiotu,
         ocena->nr_albumu, ocena->ocena, ocena->komentarz);
        ocena = ocena->nast;
    }
    fclose(fin);
}

void zwolnij_student(Student *s) {
    
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
    
    
}

void zwolnij_przedmiot(Przedmiot *p) {
    free(p->nazwa);
    free(p->kod_przedmiotu);
    free(p->semestr);
    
    free(p);
}

void zwolnij_oceny(Ocena *o) {
    free(o->nr_albumu);
    free(o->kod_przedmiotu);
    
    free(o->komentarz);
    free(o);
}

void zwolnij_liste_studentow(Student *s) {
    Student *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij_liste_ocen(Ocena *o) {
    Ocena *n;
    while (o != NULL) {
        n = o->nast;
        zwolnij_oceny(o);
        o = n;
    }
}

void zwolnij_liste_przedmiotow(Przedmiot *p) {
    Przedmiot *n;
    while (p != NULL) {
        n = p->nast;
        zwolnij_przedmiot(p);
        p = n;
    }
}

void zwolnijS(SBaza *baza) {
    zwolnij_liste_studentow(baza->lista_studentow);
    free(baza);
}
void zwolnijP(PBaza *baza) {
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    free(baza);
}
void zwolnijO(OBaza *baza) {
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}