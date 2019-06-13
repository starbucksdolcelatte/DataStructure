#pragma once
#include <stdio.h> 
#include "binary_tree.h"

#define TRUE 1 
#define FALSE 0

typedef struct _Node {
	BTreeNode* data;
	struct _Node* next;
}Node;

typedef struct _ListStack {
	struct _Node* head;
}ListStack;

void StackInit(ListStack * pstack);
int SIsEmpty(ListStack * pstack);
void SPush(ListStack * pstack, BTreeNode* data);
BTreeNode* SPop(ListStack * pstack);
BTreeNode* SPeek(ListStack * pstack);