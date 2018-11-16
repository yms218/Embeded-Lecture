#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int init_val(void)
{

	// 1 ~ 9
	// 실제 난수 생성
	return rand() % 9 + 1;
}

// 중첩 if문
void check_num(int num)
{
	if(num == 0)
	{
		printf("num은 0이다\n");
	}
	else
	{
		if(num % 2)
		{
		printf("num은 홀수\n");
		}
		else
		{
		printf("num은 짝수\n");
		}
	}
}

int main(void)
{
	int num;	
	// 난수를 생성하기 위한 초기설정
	srand(time(NULL));
	num = init_val();
	printf("num = %d\n", num);
	check_num(num);
	return 0;
}
