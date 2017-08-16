#include "include/queue.h"

queue* queue_create(size_t inital_capacity, size_t type_size)
{
	queue* q = (queue*) malloc(sizeof(queue));

	q->type_size = type_size;
	q->vec = vector_create(inital_capacity, type_size);
}

void queue_destroy(queue* q)
{
	assert(q != NULL);

	vector_destroy(q->vec);
	free(q);
}

void queue_push(queue* q, void* item)
{
	vector_push(q->vec, item);
}

void queue_reserve(queue* q, size_t size)
{
	vector_reserve(q->vec, size);
}

void* queue_top(queue* q)
{
	assert(q->vec->size > 0);

	return vector_at(q->vec, q->vec->size - 1);
}

void queue_pop(queue* q)
{
	assert(q->vec->size > 0);

	--(q->vec->size);
}