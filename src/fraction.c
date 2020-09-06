#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"
#include "radical.h"

#define serious_error {\
	printf("Serious error: Maybe 0(zero) appered in denominators.");\
	exit(1);\
}

int gcd(int a, int b){
	if (0 == a || 0 == b){
		return 1;
	}
	int tmp;
	while (tmp = a % b){
		a = b;
		b = tmp;
	}
	return b > 0 ? b : -b;
}
int lcm(int a, int b){
	return a / gcd(a, b) * b ;
}
int qpow(int base, int expt){
	int res = 1;
	while (expt){
		if (expt & 1)
			res *= base ;
		base *= base;
		expt >>= 1;
	}
	return res;
}

void fixsignFrac(Fraction* a){
	if (0 == a->down){
		serious_error;
	}
	if (0 == a->up){
		a->down = 1;
		return;
	}	
	if (a->down < 0){
		a->up = -(a->up);
		a->down = -(a->down);
		return;
	}
}
void reduceFrac(Fraction* a){
	fixsignFrac(a);
	int gcdn = gcd(a->up, a->down);
	a->up /= gcdn;
	a->down /= gcdn;
}
void printFrac(Fraction a, char* end){
	printf("(%d/%d)%s", a.up, a.down, end);
}


Fraction addFrac(Fraction a, Fraction b){
	int lcmn = lcm(a.down, b.down);
	a.up = lcmn / a.down * a.up + lcmn / b.down * b.up;
	a.down = lcmn;
	reduceFrac(&a);
	return a;
}
Fraction subFrac(Fraction a, Fraction b){
	b.up = -b.up;
	return addFrac(a, b);
}
Fraction mulFrac(Fraction a, Fraction b){
	int gcdn1 = gcd(a.up, b.down);
	int gcdn2 = gcd(a.down, b.up);
	a.up /= gcdn1;
	b.down /= gcdn1;
	a.down /= gcdn2;
	b.up /= gcdn2;
	a.up *= b.up;
	a.down *= b.down;
	fixsignFrac(&a);
	return a;
}
Fraction divFrac(Fraction a, Fraction b){
	b.up ^= b.down ^= b.up ^= b.down;
	return mulFrac(a, b);	
}
Fraction powFrac(Fraction a, int expt){
	a.up = qpow(a.up, expt);
	a.down = qpow(a.down, expt);
	return a;
}
Radical sqrtFrac(Fraction a){
	Radical u = inttoRad(a.up) , d = inttoRad(a.down);
	Fraction tmp = divFrac(u.out, d.out);
	u.in *= d.in;
	d.out.down = d.in;
	d.out.up = 1;
	u.out = mulFrac(tmp, d.out);
	return u;
}
