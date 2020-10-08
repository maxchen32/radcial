#include <stdio.h>
#include <stdlib.h>
#include "radical.h"
#include "fraction.h"

void eyyc();
int main(int argc , char * argv[]) {
    eyyc();
    return 0;
}

void eyyc(){
    int a[3];
    scanf("%d%d%d",a, a+1, a+2);
    Polynomial list = initPoly();
    Polynomial list2 = initPoly();
    int delta = a[1] * a[1] - 4 * a[0] * a[2];
    if (delta >= 0){
        Radical nb = initRad(-a[1], 1, 1);
        list = addRad(addRad(list, nb), inttoRad(delta));
        int da = 2 * a[0];
        _PolyDivInt(list, &da);
        printPoly(list);
        printf("\n");
        if (da != 1)
            printf("%d\n",da);

        da = 2 * a[0];
        list2 = subRad(addRad(list2, nb), inttoRad(delta));
        _PolyDivInt(list2, &da);
        printPoly(list2);
        printf("\n");
        if (da != 1)
            printf("%d\n",da);
    }
    else {
        printf("delta = %d < 0\n",delta);
    }
}
