#ifndef __vector_H__
#define __vector_H__

#include "ccommon.h"

typedef struct {
	size_t capacity;
	size_t size;
	size_t sizeof_type;
	void** data;
} vector;

vector* vector_create(size_t sizeof_type);
void vector_push(vector* v, void* item);
void vector_reserve(vector* v, size_t size);
bool vector_find(vector* v, size_t* index, void* item);
void* vector_at(vector* v, size_t index);

#endif