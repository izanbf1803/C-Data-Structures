#include "include/vector.h"

vector* vector_create(size_t inital_capacity, size_t type_size)
{
	assert(inital_capacity >= 0);

	vector* v = (vector*) malloc(sizeof(vector));
	v->type_size = type_size;
	v->capacity = _MAX_(inital_capacity, 2);
	v->size = 0;
	v->data = (uint8_t*) malloc(v->capacity * v->type_size); // Reserve 2 items
	return v;
}

void vector_destroy(vector* v)
{
	assert(v != NULL);

	free(v->data);
	free(v);
}

void vector_push(vector* v, void* item)
{
	assert(v != NULL);
	assert(item != NULL);

	vector_reserve(v, v->size + 1);
	memcpy(v->data + v->size * v->type_size, item, v->type_size);
	++(v->size);
}

void vector_reserve(vector* v, size_t size)
{
	assert(v != NULL && size > 0);

	if (size > v->capacity) {
		while (size > v->capacity) {
			v->capacity <<= 1; // Double the size
		}
		v->data = (uint8_t*) realloc((void*)v->data, v->capacity * v->type_size);
	}
}

bool vector_find(vector* v, void* item, size_t* index, size_t start_index)
{
	assert(v != NULL);
	assert(index != NULL);
	assert(item != NULL);

	size_t i;
	for (i = start_index; i < v->size; ++i) {
		uint8_t* it = v->data + i * v->type_size;
		if (!memcmp(it, item, v->type_size)) {
			*index = i;
			return true;
		}
	}
	return false;
}

void* vector_at(vector* v, size_t index)
{
	assert(v != NULL);
	assert(index < v->size);

	return v->data + index * v->type_size;
}