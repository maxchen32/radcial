#ifndef _RADICAL_H
#define _RADICAL_H
#include "structs.h"

void printRad(Radical a, char* end);
Radical inttoRad( int radicand );

Radical divRad(Radical a, Radical b);
Radical mulRad(Radical a, Radical b);

#endif
