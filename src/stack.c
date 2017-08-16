#include "include/stack.h"

stack* stack_create(size_t type_size)
{
	stack* s = (stack*) malloc(sizeof(stack));

	s->type_size = type_size;
	s->size = 0;
	s->vec = vector_create(2, type_size);

	return s;
}

void stack_destroy(stack* s)
{
	assert(s != NULL);

	vector_destroy(s->vec);
	free(s);
}

void stack_push(stack* s, void* item)
{
	assert(s != NULL && item != NULL);

	vector_push(s->vec, item);

	++(s->size);
}

void* stack_top(stack* s)
{
	assert(s != NULL && s->size > 0);

	return vector_at(s->vec, s->vec->size - 1);
}

void stack_pop(stack* s)
{
	assert(s != NULL && s->size > 0);

	--(s->vec->size);
	--(s->size);
}