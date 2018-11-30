// 1~100 홀수만 더해서 출력
#include <stdio.h>

int main(void)
{
	int i, sum = 0;
	for(i=1; i<=100; i++){
		if(i%2)
			sum += i;
	}
	printf("sum = %d\n", sum);
	return 0;
}
