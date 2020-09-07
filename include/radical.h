#ifndef _RADICAL_H
#define _RADICAL_H
#include "structs.h"

//tool
void printRad(Radical a, char* end);
Radical inttoRad( int radicand );

//calculation
Radical divRad(Radical a, Radical b);
Radical mulRad(Radical a, Radical b);
Polynomial addRad(Polynomial a, Radical b);

//list
int lenPoly(Polynomial ptrl);
Polynomial findkthPloy(int k, Polynomial ptrl);

#endif
