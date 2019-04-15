#include <stdio.h>
#include "stack.h"

// 스택 배열의 탑인덱스와 스택 안의 모든 데이터를 출력하는 함수
// 스택의 상태를 확인하기 위해 선언
void print_stack(Stack *pstack) {
	// 스택 배열에 들어간 데이터의 수는 topIndex+1개이므로
	int	num = pstack->topIndex + 1; 
	
	// top index 출력
	printf("\n");
	printf("top index = %d\n", pstack->topIndex);

	if (pstack->topIndex == -1) {
		printf("Stack is Empty.\n");
	}
	else {
		// Stack Array 안에 push되어 있는 데이터 출력
		for (int i = 0; i < num; i++)    // num만큼 반복
		{
			printf("stackArr[%d] : %d\n", i, pstack->stackArr[i]);
		}
	}
}

int main() {
	int value = 3;
	Stack stack;
	StackInit(&stack);
	// 초기화된 스택을 확인
	print_stack(&stack);

	SPush(&stack, value);
	print_stack(&stack);

	SPush(&stack, 5);
	print_stack(&stack); 
	
	SPush(&stack, 6);
	print_stack(&stack); 
	
	if (!SIsEmpty(&stack)) {
		value = SPop(&stack);
		print_stack(&stack);
	}

	SPush(&stack, 10);
	print_stack(&stack);

	while (!SIsEmpty(&stack)) {
		value = SPop(&stack);
		print_stack(&stack);
	}
	return 0;
}