#ifndef _FRACTION_H
#define _FRACTION_H

#include "structs.h"
#define Fraction0() initFrac(0, 1)
#define FractionN(up) initFrac(up, 1)
#define Fraction(up, down) initFrac(up, down)
#define EE initFrac(0, 0)
#define iszeroFrac(a) ((a).up == 0 ? 1 : 0)
//��ѧ
int       gcd(int a, int b);						//�������
long long lgcd(long long a, long long b);
int       lcm(int a, int b);						//��С������
int       qpow(int base, int expt);				//������

//����
Fraction initFrac(int up ,int down);       //��ʼ��
void     fixsignFrac(Fraction* a);				//����������������
void     reduceFrac(Fraction* a);				//����Լ��
void     reduce(int* a, int* b);              //��Լ��
void     printFrac(Fraction a, char* end);    //��ӡ
int      cmpFrac(Fraction a, Fraction b);       //�Ƚ� ����-1 , 0 , 1
Fraction c(char myope, ...);               //������

//����
Fraction addFrac(Fraction a, Fraction b);	//�ӷ�
Fraction subFrac(Fraction a, Fraction b);	//����
Fraction mulFrac(Fraction a, Fraction b);	//�˷�
Fraction divFrac(Fraction a, Fraction b);	//����
Fraction powFrac(Fraction a, int expt);		//�˷�
Radical  sqrtFrac(Fraction a);               //����

#endif

