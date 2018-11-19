#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// void 타입  = 아무것도 받지 않음

int rand_init(void)
{	
	srand(time(NULL));
	return rand() % 3 + 1;
}

// return type  없으므로 void
void switch_test(int num)
{
	switch (num) 
	{
		case 1:
			printf("1 Detected\n");
		        break; // 여기서 강제로 멈추란 뜻 없으면 밑에것도 실행됨
		case 2:
			printf("2 Detected\n");
			break;
		default:
			printf("Wrong Number\n");
	}
}

int main(void)
{
	int num = rand_init();	
	printf("num = %d\n", num);
	switch_test(num);
	return 0;
}
