#ifndef _STRUCTS_H
#define _STRUCTS_H

typedef struct {
	int up;
	int down;
} Fraction;

typedef struct {
	Fraction out;
	int in;
} Radical;

struct Node {
	Radical num;
	struct Node* next;
};
typedef struct Node Node;
typedef Node* Ploynomial;

#endif
