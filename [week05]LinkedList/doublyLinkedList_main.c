#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

int main(void) {
	// create doubly linked list & init.
	struct DB_LinkedList list;  int data;
	ListInit(&list);

	// set 8 data
	InsertItem(&list, 1);
	InsertItem(&list, 2);
	InsertItem(&list, 3);
	InsertItem(&list, 4);
	InsertItem(&list, 5);
	InsertItem(&list, 6);
	InsertItem(&list, 7);
	InsertItem(&list, 8);

	// check inserted data into the list
	if (getFirstItem(&list, &data)) {
		printf("%d ", data);

		while (getNextItem(&list, &data)) {
			printf("%d ", data);
		}
		while (getPrevItem(&list, &data)) {
			printf("%d ", data);
		}
		printf("\n\n");
	}
	return 0;
} // end of main()