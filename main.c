#include <stdio.h>
#include <stdlib.h>
#include "radical.h"
#include "fraction.h"

int main(int argc , char * argv[]) {
	//Radical aaa={{1,1},2}, bbb={{1,3},3}, ccc={{1,1},6};
	//printRad(mulRad(mulRad(aaa, bbb),ccc),"");
	Fraction aaa = {998,999}, bbb = {8,9};
	int cmp;
    cmp = cmpFrac(aaa, bbb);
    printf("%d\n", cmp);
	return 0;
}
