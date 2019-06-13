#include <stdio.h>
#include "queue.h"


int main(void) {
	// Create & init Queue
	Queue q;
	QueueInit(&q);
	print_queue(&q);

	// data enqueue
	Enqueue(&q, 100);
	print_queue(&q);

	Enqueue(&q, 200);
	print_queue(&q);

	Enqueue(&q, 300); 
	print_queue(&q);

	Enqueue(&q, 400);
	print_queue(&q);

	// data dequeue
	while (!QIsEmpty(&q)) {
		printf("Dequeue value : %d\n", Dequeue(&q));
		print_queue(&q);
	}

	Enqueue(&q, 20);
	print_queue(&q);

	Dequeue(&q);
	print_queue(&q);

	Enqueue(&q, 40);
	print_queue(&q);

	printf("end of main()\n");
	return 0;
}
