#include <stdio.h>
#include <stdlib.h>
//#include "radical.h"
#include "fraction.h"

int main(int argc , char * argv[]) {
	//Radical aaa={{1,1},2}, bbb={{1,3},3}, ccc={{1,1},6};
	//printRad(mulRad(mulRad(aaa, bbb),ccc),"");
    Fraction aaa[10] = {{1,2},{1,3},{1,4},{1,5} };
    Fraction ccc = c('*',c('+',aaa[0], aaa[1], aaa[2] ,EE),aaa[3],EE);
    printFrac(ccc,"\n");
	return 0;
}
