#ifndef __vector_H__
#define __vector_H__

#include "ccommon.h"

typedef struct {
	size_t type_size;
	size_t capacity;
	size_t size;
	uint8_t* data;
} vector;

vector* vector_create(size_t inital_capacity, size_t type_size);
void vector_destroy(vector* v);
void vector_push(vector* v, void* item);
void vector_reserve(vector* v, size_t size);
bool vector_find(vector* v, void* item, size_t* index, size_t start_index);
void* vector_at(vector* v, size_t index);

#endif