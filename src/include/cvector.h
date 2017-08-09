#ifndef __CVECTOR_H__
#define __CVECTOR_H__

#include "ccommon.h"

typedef struct {
	size_t capacity;
	size_t size;
	size_t sizeof_type;
	void** data;
} cvector;

cvector* cvector_create(size_t sizeof_type);
void cvector_push(cvector* v, void* item);
void cvector_reserve(cvector* v, size_t size);
bool cvector_find(cvector* v, size_t* index, void* item);
void* cvector_at(cvector* v, size_t index);

#endif