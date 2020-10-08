#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "radical.h"
#include "fraction.h"

//tool
Radical initRad(int up, int down, int in){
    Radical tmp = {{ up , down }, in};
    if (down != 0){
        reduceFrac(&(tmp.out));
    }
    Radical res = inttoRad( tmp.in );
    res.out = mulFrac(res.out, tmp.out);
    return res;
}
void printRad(Radical a, char* end){
    printf("(%d/%d)*sqrt(%d)%s", a.out.up, a.out.down, a.in, end);
}
Radical inttoRad( int radicand ){
    Radical res = {.out.up = 0, .out.down = 1, .in = 1};
    if (0 == radicand) {
        return res;
    } else if (radicand < 0) {
        printf("Error: negative number, exiting\n");
        exit(1);
    }
    int flag = 0;
    for (int tmp = floor(sqrt(radicand)) ; tmp-1 ; tmp--) {
        if (0 == radicand % (tmp * tmp)) {
            res.out.up = tmp;
            res.in  = radicand / (tmp * tmp);
            flag = 1;
            break;
        }
    }
    if (!flag) {
        res.out.up = 1;
        res.in  = radicand;
    }
    return res;
}
void printPoly(Polynomial ptrl){
    Polynomial p = ptrl;
    if (p == NULL|| p->next == NULL){
        return;
    }
    else{
        p = p->next;
    }
    if (p->num.out.up < 0)
        printf("- ");
    while(1){
        if (p->num.in == 1){
            if (p->num.out.down == 1)
                printf("%d",(p->num.out.up > 0 ? p->num.out.up : -p->num.out.up));
            else
                printf("(%d/%d)", (p->num.out.up > 0 ? p->num.out.up : -p->num.out.up), p->num.out.down);
        }
        else{
            if (p->num.out.down == 1){
                if (p->num.out.up == 1 || p->num.out.up == -1)
                    printf("sqrt(%d)", p->num.in);
                else
                    printf("%d*sqrt(%d)",(p->num.out.up > 0 ? p->num.out.up : -p->num.out.up), p->num.in);
            }

        }

        if (p->next == NULL){
            break;
        }
        p = p->next;
        if (p->num.out.up >= 0)
            printf(" + ");
        else
            printf(" - ");
    }
}
int isequalRad(Radical a, Radical b){
    if (a.in == b.in && a.out.up == b.out.up && a.out.down == b.out.down)
        return 1;
    else
        return 0;
}
/*
int cmpRad(Radical a, Radical b){
    if (a.in == b.in)
        return cmpFrac(a.out, b.out);

    int gcdn1 = gcd(a.out.up, b.out.up);
    int gcdn2 = gcd(a.out.down, b.out.down);
    a.out.up /= gcdn1;
    b.out.up /= gcdn1;
    a.out.down /= gcdn2;
    b.out.down /= gcdn2;

    a.out.up *= b.out.down;
    a.out.down *= b.out.up;
    b.out.up = a.out.down;
    b.out.down = a.out.up;

    long long   aup = a.out.up * b.out.down ,
                adown = a.out.dowm * b.out.up ,
                bup = a.out.down ,
                bdown = a.out.up ;

    int gcdn3 = (int)lgcd((long long)a.in, adown);
    int gcdn4 = (int)lgcd((long long)b.in, bdown);
    a.in /= gcdn3;
    adown /= gcdn3;
    b.in /= gcdn4;
    bdown /= gcdn4;

    aup *= a.in;
    bup *= b.in;
    printRad(a , "\n");
    printRad(b , "\n");
    return cmpFrac(a.out, b.out);
}
*/
//calculation
Radical divRad(Radical a, Radical b){
    Fraction tmp = divFrac(a.out, b.out);
    int gcdn = gcd(a.in, b.in);
    a.in /= gcdn;
    b.in /= gcdn;
    a.in *= b.in;
    b.out.down = b.in;
    b.out.up = 1;
    a.out = mulFrac(tmp, b.out);
    return a;
}
Radical mulRad(Radical a, Radical b){
    Radical res;
    a.out = mulFrac(a.out, b.out);
    a.in *= b.in;
    res = inttoRad(a.in);
    res.out = mulFrac(a.out, res.out);
    return res;
}

Polynomial addRad(Polynomial ptrl, Radical b) {
    Polynomial p = ptrl;
    if (p == NULL){
        return NULL;
    }
    else if (p->next == NULL){
        insertPoly( b ,1 , ptrl );
        return ptrl;
    }

    int flag = 0;
    int i = 1;
    do {
        p = p->next;
        if (p->num.in == b.in){
            p->num.out = addFrac(p->num.out, b.out);
            flag = 1;
            if (p->num.out.up == 0){
                deletePoly(i, ptrl);
            }
            break;
        }
        i++;
    }while (p->next != NULL);

    if (!flag) {
        insertPoly( b , lenPoly(ptrl) , ptrl );
    }
    return ptrl;
}
Polynomial subRad(Polynomial ptrl, Radical b){
    b.out.up = -b.out.up;
    return addRad(ptrl, b);
}
int gcdPoly(Polynomial ptrl){
    Polynomial p = ptrl;
    if (p == NULL || p->next == NULL){
        return 1;
    }
    p = p->next;
    if (p->next == NULL){
        return p->num.out.up;
    }
    int gcdn = gcd(p->num.out.up, p->next->num.out.up);
    while (gcdn != 1){
        p = p->next;
        if (p->next == NULL)
            break;
        gcdn = gcd(gcdn, p->next->num.out.up);
    }

    return gcdn >= 0 ? gcdn : -gcdn;
}
Polynomial _PolyDivInt(Polynomial ptrl, int* x){
    Polynomial p = ptrl;
    if (p == NULL || p->next == NULL){
        return ptrl;
    }
    int gcdn = gcd(gcdPoly(ptrl), *x);
    *x /= gcdn;
    do {
        p = p->next;
        p->num.out.up /= gcdn;
    }while (p->next != NULL);
    return ptrl;
}
//Raddivint()

//list
Polynomial initPoly(){
    Polynomial head = (Polynomial)malloc(sizeof(Node));
    if (head == NULL){
        printf("initPoly: failed\n");
        return NULL;
    }
    head->next = NULL;
    return head;
}
int lenPoly(Polynomial ptrl){
    Polynomial p = ptrl;
    int j = 0;
    while (p){
        p = p->next;
        j++;
    }
    return j;
}

Polynomial findkthPloy(int k, Polynomial ptrl){
    Polynomial p = ptrl;
    int i = 0;
    while ( i < k && p != NULL ){
        p = p->next;
        i++;
    }
    if ((i) == k)
        return p;
    else
        return NULL;
}

Polynomial findPloy(Radical x, Polynomial ptrl){
    Polynomial p = ptrl;
    while (p != NULL && isequalRad(p->num, x)){
        p = p->next;
    }
    return p;
}

Polynomial insertPoly(Radical x,int i, Polynomial ptrl ){
    Polynomial p,s;
    p = findkthPloy(i-1, ptrl);
    if (p == NULL){
        fprintf(stderr, "insertPloy: value of i error\n");
        return NULL;
    }
    else {
        s = (Polynomial)malloc(sizeof(Node));
        s->num = x;
        s->next = p->next;
        p->next = s;
        return ptrl;
    }
}

Polynomial deletePoly(int i, Polynomial ptrl){
    Polynomial p,s;
    p = findkthPloy(i-1, ptrl);
    if (p == NULL){
        fprintf(stderr, "deletePoly: the %dth node does not exist\n",i-1);
        return NULL;
    }
    else if (p->next == NULL){
        fprintf(stderr, "deletePoly: the %dth node does not exist\n",i);
        return NULL;
    }
    else {
        s = p->next;
        p->next = s->next;
        free(s);
        s = NULL;
        return ptrl;
    }
}
