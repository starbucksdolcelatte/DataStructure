#pragma once

#define QUE_LEN 4

// Circular Queue structure
typedef struct _Queue {
	int front;
	int rear;
	int queArr[QUE_LEN];
}Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
int QIsFull(Queue* pq);
void Enqueue(Queue * pq, int data);
int Dequeue(Queue * pq);
int QPeek(Queue * pq);
void print_queue(Queue *pq);