#ifndef __stack_H__
#define __stack_H__

#include "ccommon.h"
#include "vector.h"

typedef struct {
	size_t type_size;
    size_t size;
	vector* vec;
} stack;

stack* stack_create(size_t type_size);
void stack_destroy(stack* s);
void stack_push(stack* s, void* item);
void* stack_top(stack* s);
void stack_pop(stack* s);

#endif