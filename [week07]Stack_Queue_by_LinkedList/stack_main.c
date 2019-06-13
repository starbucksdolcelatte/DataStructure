#include <stdio.h>
#include "stack_linked_list.h"

int main(void) {
	int value = 3; 
	ListStack stack; 
	StackInit(&stack);
	SPush(&stack, value); 
	SPush(&stack, 5); 
	SPush(&stack, 6);
	if (!SIsEmpty(&stack)) { 
		value = SPop(&stack); 
		printf("%d\n", value);
	}
	SPush(&stack, 10);
	while (!SIsEmpty(&stack)) { 
		value = SPop(&stack); 
		printf("%d\n", value);
	} 
	return 0;
} // end of main