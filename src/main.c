#include "include/vector.h"
#include "include/queue.h"
#include "include/stack.h"
#include <stdio.h>

int main()
{
	// vector TEST
	/*
	vector* v_int = vector_create(0, sizeof(int));

	int n = 10;
	vector_push(v_int, &n);
	++n;
	vector_push(v_int, &n);
	++n;
	vector_push(v_int, &n);
	n *= 3;
	vector_push(v_int, &n);

	size_t index_of;
	int value_to_find = 12;
	if (vector_find(v_int, &value_to_find, &index_of, 0)) {
		printf("\n%d found at position %d\n", value_to_find, index_of);
	}

	int i;
	for (i = 0; i < v_int->size; ++i) {
		printf("%d\n", *(int*)vector_at(v_int, i));
	}

	vector_destroy(v_int);
	*/


	// queue TEST 
	/*
	queue* q = queue_create(sizeof(int));

	int n = 10;
	queue_push(q, &n);
	++n;
	queue_push(q, &n);
	++n;
	queue_push(q, &n);
	n *= 3;
	queue_push(q, &n);

	while (q->size > 0) {
		printf("%d\n", *(int*)queue_front(q));
		queue_pop(q);
	}

	queue_destroy(q);
	*/


	// stack TEST
	/*
	stack* s = stack_create(sizeof(int));

	int n = 10;
	stack_push(s, &n);
	++n;
	stack_push(s, &n);
	++n;
	stack_push(s, &n);
	n *= 3;
	stack_push(s, &n);

	while (s->size > 0) {
		printf("%d\n", *(int*)stack_top(s));
		stack_pop(s);
	}

	stack_destroy(s);
	*/



	return 0;
}