#include <stdio.h>
#include <stdlib.h>
#include "radical.h"
#include "fraction.h"

void eyyc(int a, int b, int c);
int main(int argc, char * argv[]) {
    eyyc(1, 2, 1);
    return 0;
}

void eyyc(int a, int b, int c){     //f(x)=ax^2+bx+c
    Polynomial list = initPoly();
    Polynomial list2 = initPoly();
    int delta = b * b - 4 * a * c;
    if (delta >= 0){
        Radical nb = initRad(-b, 1, 1);
        list = addRad(addRad(list, nb), inttoRad(delta));
        int da = 2 * a;
        _PolyIntReduce(list, &da);
        printPoly(list);
        printf("\n");
        if (da != 1)
            printf("%d\n",da);

        da = 2 * a;
        list2 = subRad(addRad(list2, nb), inttoRad(delta));
        _PolyIntReduce(list2, &da);
        printPoly(list2);
        printf("\n");
        if (da != 1)
            printf("%d\n",da);
    }
    else {
        printf("delta = %d < 0\n",delta);
    }

    destoryPoly(list2);
    destoryPoly(list);
}
