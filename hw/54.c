#include <stdio.h>

int main(void)
{
	double x;
	printf("ADC에서 읽은 값 12677 양수값\n");
	x = (5.0*12677.0)/(1024.0*64.0);
	printf("전압값 : %lfV\n", x);
	return 0;

}
