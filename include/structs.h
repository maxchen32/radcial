#ifndef _STRUCTS_H
#define _STRUCTS_H

typedef struct {
	int up;
	int down;
} Fraction;                 //����

typedef struct {
	Fraction out;
	int in;
} Radical;                  //���θ�ʽ

typedef struct Node Node;
typedef Node* Polynomial;   //������ʽ��
struct Node {
	Radical num;
	Polynomial next;
};

#endif
