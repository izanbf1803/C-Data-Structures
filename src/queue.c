#include "include/queue.h"

queue* queue_create(size_t type_size)
{
	queue* q = (queue*) malloc(sizeof(queue));

	q->type_size = type_size;
	q->size = 0;
	q->front = NULL;
	q->back = NULL;

	return q;
}

void queue_destroy(queue* q)
{
	assert(q != NULL);

	while (q->size > 0) {
		queue_pop(q);
	}

	free(q);
}

void queue_push(queue* q, void* item)
{
	assert(q != NULL);
	assert(item != NULL);

	struct __queue_node* node = (struct __queue_node*) malloc(sizeof(struct __queue_node));
	node->right = NULL;
	node->data = (uint8_t*) malloc(q->type_size);
	memcpy(node->data, item, q->type_size);

	if (q->size == 0) {
		q->front = node;
		q->back = node;
	}
	else {
		q->back->right = node;
		q->back = node;
	}

	++(q->size);
}

void* queue_front(queue* q)
{
	assert(q != NULL);
	assert(q->size > 0);

	return q->front->data;
}

void queue_pop(queue* q)
{
	assert(q != NULL);
	assert(q->size > 0);

	struct __queue_node* temp = q->front;
	q->front = temp->right;

	free(temp->data);
	free(temp);

	--(q->size);
}