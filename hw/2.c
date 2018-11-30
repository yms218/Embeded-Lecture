// 임의의 값 x를 4096 단위로 정렬
// 4096 = 2의 12승
#include <stdio.h>
int and_not(int num)
{
	return num & ~((1<<12) - 1);
}


int main(void)
{
	int x = 10000;
	printf("%d\n", and_not(x));
 	return 0;	
}
