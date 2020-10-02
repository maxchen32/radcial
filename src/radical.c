#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#include <string.h>
#include "radical.h"
#include "fraction.h"

//tool
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
int isequalRad(Radical a, Radical b){
    if (a.in == b.in && a.out.up == b.out.up && a.out.down == b.out.down)
        return 1;
    else
        return 0;
}
/*
int cmpRad(Radical a, Radical b){
    if (a.in == b.in)
        return cmpFrac(a.out, b.out);

    int gcdn1 = gcd(a.out.up, b.out.up);
    int gcdn2 = gcd(a.out.down, b.out.down);
    a.out.up /= gcdn1;
    b.out.up /= gcdn1;
    a.out.down /= gcdn2;
    b.out.down /= gcdn2;
*
    a.out.up *= b.out.down;
    a.out.down *= b.out.up;
    b.out.up = a.out.down;
    b.out.down = a.out.up;
*
    long long  aup = a.out.up * b.out.down,
                adown = a.out.dowm * b.out.up,
                bup = a.out.down,
                bdown = a.out.up;

    int gcdn3 = (int)lgcd((long long)a.in, adown);
    int gcdn4 = (int)lgcd((long long)b.in, bdown);
    a.in /= gcdn3;
    adown /= gcdn3;
    b.in /= gcdn4;
    bdown /= gcdn4;

    aup *= a.in;
    bup *= b.in;
    printRad(a , "\n");
    printRad(b , "\n");
    return cmpFrac(a.out, b.out);
}*/

//calculation
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
Polynomial addRad(Polynomial a, Radical b){
	Polynomial front, rear;
	rear = (Polynomial)malloc(sizeof(Node));
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
			rear->next = (Polynomial)malloc(sizeof(Node));
			rear = rear->next;
		}
	}
	rear->next = NULL;
	return front;
}
//Raddivint()

//list
int lenPoly(Polynomial ptrl){
	Polynomial p = ptrl;
	int j = 0;
	while (p){
		p = p->next;
		j++;
	}
	return j;
}

Polynomial findkthPloy(int k, Polynomial ptrl){
	Polynomial p = ptrl;
	int i = 1;
	while ( p != NULL && i < k){
		p = p->next;
		i++;
	}
	if (i==k)
		return p;
	else
		return NULL;
}
/*
Polynomial findPloy(Radical x, Polynomial ptrl){
    Polynomial p = ptrl;
    while (p != NULL && p->num){

    }
}
*/
