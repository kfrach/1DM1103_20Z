#ifndef _OPERACJE_MATEMATYCZNE_H
#define _OPERACJE_MATEMATYCZNE_H


#include "obsluga_pliku.h"

float norm(struct Macierz A);
void sum(struct Macierz A, struct Macierz B, struct Macierz *C);
void subtract(struct Macierz A, struct Macierz B, struct Macierz *C);
void prod(struct Macierz A, struct Macierz B, struct Macierz *C);
void multiply(struct Macierz A, struct Macierz *C, float x);

#endif

