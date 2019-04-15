#include <stdio.h>
#include "stack.h"

// ���� �迭�� ž�ε����� ���� ���� ��� �����͸� ����ϴ� �Լ�
// ������ ���¸� Ȯ���ϱ� ���� ����
void print_stack(Stack *pstack) {
	// ���� �迭�� �� �������� ���� topIndex+1���̹Ƿ�
	int	num = pstack->topIndex + 1; 
	
	// top index ���
	printf("\n");
	printf("top index = %d\n", pstack->topIndex);

	if (pstack->topIndex == -1) {
		printf("Stack is Empty.\n");
	}
	else {
		// Stack Array �ȿ� push�Ǿ� �ִ� ������ ���
		for (int i = 0; i < num; i++)    // num��ŭ �ݺ�
		{
			printf("stackArr[%d] : %d\n", i, pstack->stackArr[i]);
		}
	}
}

int main() {
	int value = 3;
	Stack stack;
	StackInit(&stack);
	// �ʱ�ȭ�� ������ Ȯ��
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