#include <stdio.h>

// void (*)(void) : 함수의 이름은 주소
void test(void)
{
	printf("test\n");
}

int num_test(void)
{
	printf("num_test\n");
	return 7;
}

// void (*)(void) test_test(void) : 함수포인터 
// prototype : int (*)(void) test_test(void (*p)(void)) 인자, 리턴 둘다 함수포인터
int (* test_test(void (*p)(void)))(void)
{
	printf("test_test\n");
	p(); // 함수의 인자 
	return num_test;
}


int main(void)
{
	int res;

	res = test_test(test)(); 
	printf("res = %d\n", res);

	return 0;
}

