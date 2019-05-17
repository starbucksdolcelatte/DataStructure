#include <stdio.h>
#include <stdlib.h>
#include "stack_linked_list.h"

void StackInit(ListStack * pstack) { 
	pstack->head = NULL; 
}

int SIsEmpty(ListStack * pstack) { 
	if (pstack->head == NULL) { 
		return TRUE; 
	} else { 
		return FALSE; 
	} 
}

void SPush(ListStack * pstack, int data) {
	Node* newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data; 
	newNode->next = pstack->head;
	pstack->head = newNode;
}

int SPop(ListStack * pstack) {
	int retData; 
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
