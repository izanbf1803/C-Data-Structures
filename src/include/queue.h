#ifndef __queue_H__
#define __queue_H__

#include "ccommon.h"

struct __queue_node {
    struct __queue_node* right;
    uint8_t* data;
};

typedef struct {
	size_t type_size;
    size_t size;
	struct __queue_node* front;
    struct __queue_node* back;
} queue;

queue* queue_create(size_t type_size);
void queue_destroy(queue* q);
void queue_push(queue* q, void* item);
void* queue_front(queue* q);
void queue_pop(queue* q);

#endif