#include <stdio.h>
#include <stdlib.h>
#include "radical.h"
#include "fraction.h"

int main(int argc , char * argv[]) {
	//Radical aaa={{1,1},2}, bbb={{1,3},3}, ccc={{1,1},6};
	//printRad(mulRad(mulRad(aaa, bbb),ccc),"");

	Radical aaa = {{2,(int)(1e9+1)},1} , bbb = {{2,(int)(1e9+2)},1};
	int cmp = cmpRad(aaa , bbb);
    printf("%d\n", cmp);

    Fraction ccc = {2,(int)(1e9+1)} , ddd = {2,(int)(1e9+2)};
    int cmp2 = cmpFrac(ccc , ddd);
    printf("%d\n", cmp2);

	return 0;
}
