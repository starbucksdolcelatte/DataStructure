#ifndef STACK_H
#define STACK_H

#define STACK_LEN 100

//����ü Stack ����
typedef struct _Stack {
	int stackArr[STACK_LEN];
	int topIndex;
} Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);
void SPush(Stack * pstack, int data);
int SPop(Stack * pstack);
int SPeek(Stack * pstack);

#endif