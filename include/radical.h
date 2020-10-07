#ifndef _RADICAL_H
#define _RADICAL_H
#include "structs.h"

//tool
Radical initRad(int up, int down, int in);
void printRad(Radical a, char* end);
Radical inttoRad( int radicand );
void printPoly(Polynomial ptrl);
int cmpRad(Radical a, Radical b);
int isequalRad(Radical a, Radical b);

//calculation
Radical divRad(Radical a, Radical b);
Radical mulRad(Radical a, Radical b);
Polynomial addRad(Polynomial a, Radical b);

//list
Polynomial initPoly();
int lenPoly(Polynomial ptrl);
Polynomial findPloy(Radical x, Polynomial ptrl);
Polynomial findkthPloy(int k, Polynomial ptrl);
Polynomial insertPoly(Radical x,int i, Polynomial ptrl );
Polynomial deletePoly(int i, Polynomial ptrl);

#endif
