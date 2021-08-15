#include <stdio.h>
#include <math.h>
#include "radical/fraction.h"
#include "radical/radical.h"

typedef enum {
	OK,
	NOROOT,
	INFROOT
}Status;
Status xyline(Fraction* res, Fraction a, Fraction b, Fraction m, 
  Fraction c, Fraction d, Fraction n) {
	Fraction h1 = subFrac(mulFrac(a, d), mulFrac(b, c));
	Fraction t1 = subFrac(mulFrac(d, m), mulFrac(b, n));
	Fraction t2 = subFrac(mulFrac(a, n), mulFrac(c, m));

	if (h1.up == 0 && t1.up != 0) {
		return NOROOT;
	} else if(h1.up != 0 && t2.up == 0) {
		return INFROOT;
	} else {
		res[0] = divFrac(t1, h1);
		res[1] = divFrac(t2, h1);
		return OK;
	}
}
int main(){
	Fraction result[2];
	Status sta = xyline(result, initFrac(10,1), initFrac(6,1), initFrac(51,1), 
	  initFrac(-8,1), initFrac(12,1), initFrac(18,1));
	if (sta == OK) {
		printFrac(result[0], "\n");
		printFrac(result[1], "\n");
	} else if (sta == NOROOT) {
		printf("No Root\n");
	} else {
		printf("Inf Root\n");
	}
	return 0;
}
