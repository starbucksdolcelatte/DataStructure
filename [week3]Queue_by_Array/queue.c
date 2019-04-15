#include <stdio.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0

void QueueInit(Queue * pq) {
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue * pq) {
	if (pq->front == pq->rear) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int QIsFull(Queue* pq) {
	if (((pq->rear + 1) % QUE_LEN) == pq->front) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void Enqueue(Queue * pq, int data) {
	if (QIsFull(pq)) {
		printf("Queue Memory Error!\n");
		return;
	}
	pq->rear = (pq->rear + 1) % QUE_LEN;
	pq->queArr[pq->rear] = data;
}

int Dequeue(Queue * pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!\n");
		return 0;
	}
	pq->front = (pq->front + 1) % QUE_LEN;
	return pq->queArr[pq->front];
}

int QPeek(Queue * pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!\n");
		return 0;
	}
	return pq->queArr[(pq->front + 1) % QUE_LEN];
}

// 큐 배열의 front, rear와 큐 안의 모든 데이터를 출력하는 함수
// 큐의 상태를 확인하기 위해 선언
void print_queue(Queue *pq) {
	// 큐 배열에 들어간 데이터의 수는 rear - front
	int num = pq->rear - pq->front;
	// 만약 rear - front가 음수이면, 
	// (예: front = QUE_LEN-1, rear = 2일 때, 데이터는 3개 들어있으며,
	// rear - front = 2 - (QUE_LEN-1) = - QUE_LEN + 1 + 2
	// 데이터의 수 = (- QUE_LEN +1 + 2) + QUE_LEN = (rear-front) + QUE_LEN = 3
	if (num < 0) {
		num += QUE_LEN;
	}
	printf("num = %d\n", num);

	// front, rear 출력
	printf("front = %d\t rear = %d\n", pq->front, pq->rear);

	if (pq->front == pq->rear) {
		printf("Queue is Empty.\n\n");
	}
	else {
		// Queue Array 안에 있는 데이터 출력
		// i = 1부터 시작하는 이유는 queueArr의 front+1 부터 데이터가 채워지고
		// front는 비어있기 때문.
		for (int i = 1; i < num+1; i++)    // num번 반복
		{
			printf("queArr[%d] : %d\n",
				(pq->front + i) % QUE_LEN, pq->queArr[(pq->front + i) % QUE_LEN]);
		}
		printf("\n");
	}
}
