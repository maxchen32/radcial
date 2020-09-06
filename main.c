#include <stdio.h>
#include <stdlib.h>
#include "radical.h"
#include "fraction.h"

int main(int argc , char * argv[]) {
	//Fraction ddd[6] = {{2,1},{41,14},{5,1},{144,1},{3,1}};
	//Fraction eee = subFrac(powFrac(subFrac(mulFrac(ddd[0],ddd[1]),ddd[2]),2) , mulFrac(ddd[3],powFrac(subFrac(ddd[1],ddd[4]),2)));
	//printf("%d/%d",eee.up,eee.down);
	Radical aaa={{1,1},2}, bbb={{1,3},3}, ccc={{1,1},6};
	printRad(mulRad(mulRad(aaa, bbb),ccc),"");
	return 0;
}
