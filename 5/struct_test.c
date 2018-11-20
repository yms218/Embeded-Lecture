#include <stdio.h>
#define FIX_CONST 20

typedef struct __test // user define data type
{
	int num_int;
	float num_float;
	double num_double;
	char name[FIX_CONST];	
}test;


int main(void)
{
	test t = {3, 7.7f, 3.3, "gogogo"};
	printf("t.num = %d\n", t.num_int);
	printf("t.float = %f\n", t.num_float);
	printf("t.double = %lf\n", t.num_double);
	printf("t.name = %s\n", t.name);

	return 0;
}

