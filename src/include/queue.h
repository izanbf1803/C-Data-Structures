#ifndef __queue_H__
#define __queue_H__

#include "ccommon.h"
#include "vector.h"

typedef struct {
	size_t type_size;
	vector* vec;
} queue;

queue* queue_create(size_t inital_capacity, size_t type_size);
void queue_destroy(queue* q);
void queue_push(queue* q, void* item);
void queue_reserve(queue* q, size_t size);
void* queue_top(queue* q);
void queue_pop(queue* q);

#endif