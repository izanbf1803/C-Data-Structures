#include "include/vector.h"
#include <stdio.h>

int main()
{
	/* VECTOR TEST */
	vector* v_int = vector_create(0, sizeof(int));

	int n = 10;
	vector_push(v_int, &n);
	++n;
	vector_push(v_int, &n);
	++n;
	vector_push(v_int, &n);
	n *= 3;
	vector_push(v_int, &n);

	size_t index_of;
	int value_to_find = 12;
	if (vector_find(v_int, &value_to_find, &index_of, 0)) {
		printf("\n%d found at position %d\n", value_to_find, index_of);
	}

	int i;
	for (i = 0; i < v_int->size; ++i) {
		printf("%d\n", *(int*)vector_at(v_int, i));
	}
	/*****************/

	return 0;
}