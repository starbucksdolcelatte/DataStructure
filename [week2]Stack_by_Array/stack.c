#include <stdio.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0


/*
void StackInit(Stack* pstack)
Stack�� �ʱ�ȭ�� ����
Stack���� �� ���� ���� ȣ��Ǿ�� �ϴ� �Լ�
*/
void StackInit(Stack * pstack) {
	pstack->topIndex = -1;
}

/*
int SIsEmpty(Stack* pstack)
Stack�� �� ��� TRUE(1)��, �׷��� ���� ��� FALSE(0)�� ��ȯ
*/
int SIsEmpty(Stack * pstack) {
	if (pstack->topIndex == -1) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/*
void SPush(Stack* pstack, Data data)
Stack�� �����͸� ����.
�Ű����� data�� ���޵� ���� Stack�� ����
*/
void SPush(Stack * pstack, int data) {
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

/*
Data SPop(Stack* pstack)
�������� ���� �� ��Ҹ� ����
���� �� �����ʹ� ��ȯ
�� �Լ��� ȣ���� ���ؼ��� �ϳ� �̻��� �������� ���簡 ����Ǿ�� ��
*/
int SPop(Stack * pstack) {
	int rIdx;
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	rIdx = pstack -> topIndex;
	pstack -> topIndex -= 1;

	return pstack -> stackArr[rIdx];
}

/*
Data SPeek(Stack* pstack)
�������� ���� �� ��Ҹ� ��ȯ�ϵ� �������� ����
�� �Լ��� ȣ���� ���ؼ��� �ϳ� �̻��� �������� ���簡 ����Ǿ�� ��
*/
int SPeek(Stack * pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack -> stackArr[pstack -> topIndex];
}
