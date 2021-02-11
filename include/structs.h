#ifndef _STRUCTS_H
#define _STRUCTS_H

typedef struct {
	int up;
	int down;
} Fraction;                 //分数

typedef struct {
	Fraction out;
	int in;
} Radical;                  //二次根式

typedef struct Node Node;
typedef Node* Polynomial;   //链表（算式）
struct Node {
	Radical num;
	Polynomial next;
};

#endif
