#ifndef _FRACTION_H
#define _FRACTION_H
#include "structs.h"

//数学
int gcd(int a, int b);						//最大公因数
int lcm(int a, int b);						//最小公倍数
int qpow(int base, int expt);				//快速幂

//工具
void fixsignFrac(Fraction* a);				//符号修正、错误处理
void reduceFrac(Fraction *a);				//约分
void printFrac(Fraction a, char* end);      //打印
int compareFrac(Fraction a, Fraction b);

//运算
Fraction addFrac(Fraction a, Fraction b);	//加法
Fraction subFrac(Fraction a, Fraction b);	//减法
Fraction mulFrac(Fraction a, Fraction b);	//乘法
Fraction divFrac(Fraction a, Fraction b);	//除法
Fraction powFrac(Fraction a, int expt);		//乘方
Radical sqrtFrac(Fraction a);               //开方

#endif

