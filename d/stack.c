#include <stdio.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0


/*
void StackInit(Stack* pstack)
Stack의 초기화를 진행
Stack생성 후 제일 먼저 호출되어야 하는 함수
*/
void StackInit(Stack * pstack) {
	pstack->topIndex = -1;
}

/*
int SIsEmpty(Stack* pstack)
Stack이 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환
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
Stack에 데이터를 저장.
매개변수 data로 전달된 값을 Stack에 저장
*/
void SPush(Stack * pstack, int data) {
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

/*
Data SPop(Stack* pstack)
마지막에 저장 된 요소를 삭제
삭제 된 데이터는 반환
본 함수의 호출을 위해서는 하나 이상의 데이터의 존재가 보장되어야 함
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
마지막에 저장 된 요소를 반환하되 삭제하지 않음
본 함수의 호출을 위해서는 하나 이상의 데이터의 존재가 보장되어야 함
*/
int SPeek(Stack * pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack -> stackArr[pstack -> topIndex];
}
