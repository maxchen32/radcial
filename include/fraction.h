#ifndef _FRACTION_H
#define _FRACTION_H
#include "structs.h"

//��ѧ
int gcd(int a, int b);						//�������
int lcm(int a, int b);						//��С������
int qpow(int base, int expt);				//������

//����
void fixsignFrac(Fraction* a);				//����������������
void reduceFrac(Fraction *a);				//Լ��
void printFrac(Fraction a, char* end);      //��ӡ
int compareFrac(Fraction a, Fraction b);

//����
Fraction addFrac(Fraction a, Fraction b);	//�ӷ�
Fraction subFrac(Fraction a, Fraction b);	//����
Fraction mulFrac(Fraction a, Fraction b);	//�˷�
Fraction divFrac(Fraction a, Fraction b);	//����
Fraction powFrac(Fraction a, int expt);		//�˷�
Radical sqrtFrac(Fraction a);               //����

#endif

