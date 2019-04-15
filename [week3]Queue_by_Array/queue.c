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

// ť �迭�� front, rear�� ť ���� ��� �����͸� ����ϴ� �Լ�
// ť�� ���¸� Ȯ���ϱ� ���� ����
void print_queue(Queue *pq) {
	// ť �迭�� �� �������� ���� rear - front
	int num = pq->rear - pq->front;
	// ���� rear - front�� �����̸�, 
	// (��: front = QUE_LEN-1, rear = 2�� ��, �����ʹ� 3�� ���������,
	// rear - front = 2 - (QUE_LEN-1) = - QUE_LEN + 1 + 2
	// �������� �� = (- QUE_LEN +1 + 2) + QUE_LEN = (rear-front) + QUE_LEN = 3
	if (num < 0) {
		num += QUE_LEN;
	}
	printf("num = %d\n", num);

	// front, rear ���
	printf("front = %d\t rear = %d\n", pq->front, pq->rear);

	if (pq->front == pq->rear) {
		printf("Queue is Empty.\n\n");
	}
	else {
		// Queue Array �ȿ� �ִ� ������ ���
		// i = 1���� �����ϴ� ������ queueArr�� front+1 ���� �����Ͱ� ä������
		// front�� ����ֱ� ����.
		for (int i = 1; i < num+1; i++)    // num�� �ݺ�
		{
			printf("queArr[%d] : %d\n",
				(pq->front + i) % QUE_LEN, pq->queArr[(pq->front + i) % QUE_LEN]);
		}
		printf("\n");
	}
}
