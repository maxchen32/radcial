#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#include <string.h>
#include "radical.h"
#include "fraction.h"

void printRad(Radical a, char* end){
	printf("(%d/%d)*sqrt(%d)%s", a.out.up, a.out.down, a.in, end);
}
Radical inttoRad( int radicand ){
	Radical res = {.out.up = 0, .out.down = 1, .in = 0};
	if (0 == radicand) {
		return res;
	} else if (radicand < 0) {
		printf("Error: negative number, exiting\n");
		exit(1);
	}
	int flag = 0;
	for (int tmp = floor(sqrt(radicand)) ; tmp-1 ; tmp--) {
		if (0 == radicand % (tmp * tmp)) {
			res.out.up = tmp;
			res.in  = radicand / (tmp * tmp);
			flag = 1;
			break;
		}
	}
	if (!flag) {
		res.out.up = 1;
		res.in  = radicand;
	}
	return res;
}

Radical divRad(Radical a, Radical b){
	Fraction tmp = divFrac(a.out, b.out);
	int gcdn = gcd(a.in, b.in);
	a.in /= gcdn;
	b.in /= gcdn;
	a.in *= b.in;
	b.out.down = b.in;
	b.out.up = 1;
	a.out = mulFrac(tmp, b.out);
	return a;
}
Radical mulRad(Radical a, Radical b){
	Radical res;
	a.out = mulFrac(a.out, b.out);
	a.in *= b.in;
	res = inttoRad(a.in);
	res.out = mulFrac(a.out, res.out);
	return res;
}
Ploynomial addRad(Ploynomial a, Radical b){
	Ploynomial front, rear, tmp;
	rear = (Ploynomial)malloc(sizeof(Node));
	front = rear;
	while (a != NULL){
		if (a->num.in == b.in){
			rear->num.out = addFrac(a->num.out, b.out);
			rear->num.in = a->num.in;			
		} else {
			rear = a;
		}
		a = a->next;
		if (a != NULL){
			rear->next = (Ploynomial)malloc(sizeof(Node));
			rear = rear->next;
		}
	}
	rear->next = NULL;
	return front;
}
//Raddivint()
