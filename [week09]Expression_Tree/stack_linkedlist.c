#include <stdio.h>
#include <stdlib.h>
#include "stack_linkedlist.h"

void StackInit(ListStack * pstack) {
	pstack->head = NULL;
}

int SIsEmpty(ListStack * pstack) {
	if (pstack->head == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void SPush(ListStack * pstack, BTreeNode* data) {
	Node* newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

BTreeNode* SPop(ListStack * pstack) {
	BTreeNode* retData;
	Node* retNode;
	if (SIsEmpty(pstack)) {
		printf("Stack is Empty !!!\n");
		return -1;
	}
	retData = pstack->head->data;
	retNode = pstack->head;
	pstack->head = pstack->head->next;
	free(retNode);
	return retData;
}

BTreeNode* SPeek(ListStack * pstack) {
	BTreeNode* retData;

	if (SIsEmpty(pstack)) {
		printf("Stack is Empty !!!\n");
		return -1;
	}
	retData = pstack->head->data;
	return retData;
}
