#ifndef __queue_H__
#define __queue_H__

#include "ccommon.h"
#include "queue.h"

typedef struct {
	size_t type_size;
	size_t capacity;
	size_t size;
	vector* data;
} queue;

queue* queue_create(size_t inital_capacity, size_t type_size);
void queue_destroy(queue* q);
void queue_push(queue* v, void* item);
void queue_reserve(queue* v, size_t size);
bool queue_find(queue* v, size_t* index, void* item);
void* queue_at(queue* v, size_t index);

#endif