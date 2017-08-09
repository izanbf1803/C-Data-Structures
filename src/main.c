#include "include/cvector.h"
#include <stdio.h>

int main()
{
	cvector* v_int = cvector_create(sizeof(int));

	int n = 10;
	cvector_push(v_int, &n);

	n++;
	cvector_push(v_int, &n);

	n++;
	cvector_push(v_int, &n);

	printf("%d\n", v_int->size);

	return 0;
}