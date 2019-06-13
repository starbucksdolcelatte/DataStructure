#include <stdio.h>
#include <stdlib.h>
#include "queue_linked_list.h"

void QueueInit(ListQueue * pq) { 
	pq->front = NULL; 
	pq->rear = NULL; 
}

int QIsEmpty(ListQueue * pq) { 
	if (pq->front == NULL) { 
		return TRUE; 
	} else { 
		return FALSE; 
	} 
}

void Enqueue(ListQueue * pq, int data) {
	Node* newNode = (Node *)malloc(sizeof(Node)); 
	newNode->next = NULL; 
	newNode->data = data;
	if (QIsEmpty(pq)) { 
		pq->front = newNode; 
		pq->rear = newNode; 
	} else { 
		pq->rear->next = newNode; 
		pq->rear = newNode; 
	}
} // end of Enqueue.

int Dequeue(ListQueue * pq) {
	Node* delNode; 
	int retData;
	if (QIsEmpty(pq)) { 
		printf("Queue is Empty !!!\n");
		return -1;
	}
	delNode = pq->front; 
	retData = delNode->data; 
	pq->front = pq->front->next;
	free(delNode);
	return retData;
}

int QPeek(ListQueue * pq) {
	int retData;
	if (QIsEmpty(pq)) {
		printf("Queue is Empty !!!\n");
		return -1;
	}
	retData = pq->front->data;
	return retData;
}