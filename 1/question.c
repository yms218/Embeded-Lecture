#include <stdio.h>

int mult(int a, int b, int c, int d)
{
	return a+b+c+d;
}	

int main(void)
{
	int a,b,c,d;
	a = 1;	b = 2;	c = 3;	d = 4;
	printf("a+b+c+d = %d\n", mult(a,b,c,d));
	return 0;
}

	
	
