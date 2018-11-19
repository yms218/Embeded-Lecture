#include <stdio.h>

int main(void)
{
	int *p = NULL; // 포인터의 크기는 레지스터의 비트수 64비트니까 8바이트 할당
	int num = 3;
	p = &num;

	// tap size adjustment = :set ts=4
	printf("num = %d\n", num);
	printf("*p = %d\n", *p);
	
	return 0;
}

