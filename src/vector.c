#include "include/vector.h"

vector* vector_create(size_t sizeof_type)
{
	assert(sizeof_type > 0);

	vector* v = (vector*) malloc(sizeof(vector));
	v->sizeof_type = sizeof_type;
	v->capacity = 2;
	v->size = 0;
	v->data = (void**) malloc(v->sizeof_type << 1); // Reserve 2 items
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
	assert(v != NULL && item != NULL);

	++v->size;
	vector_reserve(v, v->size);
	size_t offset = (v->size - 1) * v->sizeof_type;
	memcpy(v->data + offset, item, v->sizeof_type);
}

void vector_reserve(vector* v, size_t size)
{
	assert(v != NULL && size > 0);

	if (size > v->capacity) {
		while (size > v->capacity) {
			v->capacity <<= 1; // Double the size
		}
		v->data = (void**) realloc(v->data, v->capacity * v->sizeof_type);
	}
}

bool vector_find(vector* v, size_t* index, void* item)
{
	assert(v != NULL && index != NULL && item != NULL);

	size_t i;
	for (i = 0; i < v->size; ++i) {
		void* it = v->data + i * v->sizeof_type;
		if (!memcmp(it, item, v->sizeof_type)) {
			*index = i;
			return true;
		}
	}
	return false;
}

void* vector_at(vector* v, size_t index)
{
	assert(v != NULL && index < v->size);

	return v->data + index * v->sizeof_type;
}