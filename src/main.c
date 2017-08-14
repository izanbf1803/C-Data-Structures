#include "include/vector.h"
#include <stdio.h>

int main()
{
	vector* v_int = vector_create(sizeof(int));

	int n = 10;
	vector_push(v_int, &n);

	n++;
	vector_push(v_int, &n);

	n++;
	vector_push(v_int, &n);

	printf("%d\n", v_int->size);

	return 0;
}