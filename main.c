#include <stdio.h>
#include <stdlib.h>
#include "radical.h"
#include "fraction.h"

int main(int argc , char * argv[]) {
	//Radical aaa={{1,1},2}, bbb={{1,3},3}, ccc={{1,1},6};
	//printRad(mulRad(mulRad(aaa, bbb),ccc),"");

	Radical aaa = {{1,2},73} , bbb = {{1,3},101};
	int cmp = cmpRad(aaa , bbb);
    printf("%d\n", cmp);
	return 0;
}
