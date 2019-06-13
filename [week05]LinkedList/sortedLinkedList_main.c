#include <stdio.h>
#include <stdlib.h>
#include "sortedLinkedList.h"

int main(void) {
	int data;
	// create List & init.  
	struct LinkedList list;
	ListInit(&list);

	// set 6 data
	SortedInsert(&list, 36);
	SortedInsert(&list, 94);
	SortedInsert(&list, 7);
	SortedInsert(&list, 9);
	SortedInsert(&list, 54);
	SortedInsert(&list, 65);

	// check inserted data into the list
	if (getFirstItem(&list, &data)) {
		printf("%d ", data);

		while (getNextItem(&list, &data)) {
			printf("%d ", data);
		}
		printf("\n\n");
	}
	return 0;
} // end of main