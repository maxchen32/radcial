#include <stdio.h>
#include <stdlib.h>
#include "radical.h"
#include "fraction.h"

int main(int argc , char * argv[]) {
/*
    Radical a[10] = {initRad(2,1,3) , initRad(1,2,5), initRad(1,3,2), initRad(-1,-3,4)};
    //a[0] = initRad(2,1,3);
    //a[1] = initRad(3,1,3);
    Polynomial list = initPoly();
    list = addRad(addRad(addRad(addRad(list, a[0]), a[1]), a[2]),a[3]);
    //list = addRad(list, a[1]);

    //list = insertPoly(a[0], 1, list);
    printPoly(list);
*/
    int a[3];
    scanf("%d%d%d",a[0],a[1],a[2]);
    Polynomial list = initPoly();
    
    int delta = a[1] * a[1] - 4 * a[0] * a[2];
    Radical nb = initRad(-delta, 1, 1);
    list = addRad(addRad(list, nb), inttoRad(delta));
    
    return 0;
}
