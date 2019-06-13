#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(void) {
	// create List & init.  
	struct LinkedList list;
	ListInit(&list);

	// set 6 data
	UnsortedInsert(&list, 36);
	UnsortedInsert(&list, 94);
	UnsortedInsert(&list, 7);
	UnsortedInsert(&list, 9);
	UnsortedInsert(&list, 54);
	UnsortedInsert(&list, 65);
	printf("data# = %d\n",
		ListItemsCount(&list));

	if (Find(&list, 36))
		printf("Found !!!\n");
	else
		printf("Not Found T.T...\n");

	if (Find(&list, 99))
		printf("Found !!!\n");
	else
		printf("Not Found T.T...\n");

	if (Find(&list, 65))
		printf("Found !!!\n");
	else
		printf("Not Found T.T...\n");
	return 0;
} // end of main
