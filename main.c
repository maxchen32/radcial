#include <stdio.h>
#include <stdlib.h>
#include "radical.h"
#include "fraction.h"

int main(int argc , char * argv[]) {

    Radical a[10] = {initRad(2,1,3) , initRad(-2,1,3), initRad(1,3,2), initRad(-1,-3,4)};
    //a[0] = initRad(2,1,3);
    //a[1] = initRad(3,1,3);
    Polynomial list = initPoly();
    list = addRad(addRad(addRad(addRad(list, a[0]), a[1]), a[2]),a[3]);
    //list = addRad(list, a[1]);

    //list = insertPoly(a[0], 1, list);
    printPoly(list);

	return 0;
}
