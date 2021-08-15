#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include "radical/fraction.h"

#define serious_error {\
	printf("Serious error: Maybe 0(zero) appered in denominators.");\
	exit(1);\
}

//math
int gcd(int a, int b){
	if (0 == a || 0 == b){
		return 1;
	}
	int tmp;
	while ((tmp = a % b)){
		a = b;
		b = tmp;
	}
	return b > 0 ? b : -b;
}
long long lgcd(long long a, long long b){
	if (0 == a || 0 == b){
		return 1;
	}
	long long tmp;
	while ((tmp = a % b)){
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

//tool
Fraction initFrac(int up, int down){
    Fraction res = {up , down};
    if (down != 0)
        reduceFrac(&res);
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
void reduce(int* a, int* b){
    int gcdn = gcd(*a, *b);
    *a /= gcdn;
    *b /= gcdn;
}
void printFrac(Fraction a, char* end){
	//printf("(%d/%d)%s", a.up, a.down, end);
	printf("(%d", a.up);
	if (a.down != 1) {
		printf("/%d", a.down);
	}
	printf(")%s", end);
}
int cmpFrac(Fraction a, Fraction b){
    if (b.down == 0){
        return 2;
    }
	if ((a.up == b.up && a.down == b.down) || (a.up == 0 && b.up == 0))
		return 0;
    else if (a.up < 0 && b.up > 0)
        return -1;
    else if (a.up > 0 && b.up < 0)
        return 1;
    reduce(&a.up, &b.up);
    reduce(&a.down, &b.down);
    long long resup = a.up * b.down;
    long long resdown = a.down * b.up;
    if (resup < resdown)
        return -1;
    else if (resup > resdown)
        return 1;
}
bool isDownZero(Fraction a){
    return a.down == 0 ? true : false;
}
Fraction c(char myope, ...){
    va_list alist;
    va_start(alist, myope);
    Fraction argval = va_arg(alist, Fraction);
    Fraction res = argval;
    argval = va_arg(alist, Fraction);
    switch (myope){
    case '+' :
        while (!isDownZero(argval)){
            res = addFrac(res, argval);
            argval = va_arg(alist, Fraction);
        }
        break;
    case '-' :
        while (!isDownZero(argval)){
            res = subFrac(res, argval);
            argval = va_arg(alist, Fraction);
        }
        break;
    case '*' :
        while (!isDownZero(argval)){
            res = mulFrac(res, argval);
            argval = va_arg(alist, Fraction);
        }
        break;
    case '/' :
        while (!isDownZero(argval)){
            res = divFrac(res, argval);
            argval = va_arg(alist, Fraction);
        }
        break;
    default:
        fprintf(stderr,"calc: Invalid Operator\n");
        exit(1);
    }
    va_end(alist);
    return res;
}

//calculation
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

