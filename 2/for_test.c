#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int rand_init(void)
{
	srand(time(NULL));
	return rand() % 9 + 1;
}

void for_test(int num)
{
	int i;

	/* 윈도우는 for(int i = 0; ~~~)와 같은 것을 허용하는 반면 리눅스나 표준 C언어는 허용하지않음
	C언어는 철저한 설계하에 프로그래밍을 한다는 가정을 하기 때문에 변수 선언은 처음에 다 해둬야함
	증감식은 한번 수행된 이후 진행*/
	for(i = 0; i < num; i++)
		printf("num = %d\n", i);
}

int main(void)
{
	int num = rand_init();
	for_test(num);
	return 0;
}

