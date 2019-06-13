#pragma once
#include <stdio.h>
#define TRUE 1 
#define FALSE 0

typedef struct _Node{ 
	int data; 
	struct _Node* next; 
}Node;

typedef struct _ListQueue{ 
	struct _Node* front; 
	struct _Node* rear; 
}ListQueue;

int Dequeue(ListQueue * pq);
void Enqueue(ListQueue * pq, int data);
int QIsEmpty(ListQueue * pq);
void QueueInit(ListQueue * pq);
int QPeek(ListQueue * pq);