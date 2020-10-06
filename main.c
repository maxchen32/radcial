#include <stdio.h>
#include <stdlib.h>
#include "radical.h"
#include "fraction.h"

int main(int argc , char * argv[]) {
	//Radical aaa={{1,1},2}, bbb={{1,3},3}, ccc={{1,1},6};
	//printRad(mulRad(mulRad(aaa, bbb),ccc),"");
    //Fraction aaa[10] = {, , ,};
    //Fraction ccc = c('*',c('+',Fraction0(), FractionN(3), Fraction(2,8) ,EE),Fraction(1,5),EE);
    //printFrac(ccc,"\n");
    Radical a[10];
    a[0]=initRad(2,1,3);
    Polynomial list;
    list = addRad(a[0],list);
	return 0;
}
