#pragma once
#include <stdio.h> 
#define TRUE 1 
#define FALSE 0

typedef struct _Node{ 
	int data; 
	struct _Node* next; 
}Node; 

typedef struct _ListStack{ 
	struct _Node* head; 
}ListStack;

void StackInit(ListStack * pstack);
int SIsEmpty(ListStack * pstack);
void SPush(ListStack * pstack, int data);
int SPop(ListStack * pstack);
int SPeek(ListStack * pstack);