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

int (* test_test(void (*p)(void)))(void)
{
	printf("test_test\n");
	p(); // 함수의 인자 
	return num_test;
}

// int (*)(void) test_test(void (*p)(void))
// int (*)(void) (*)(void (*)(void)) 리턴 타입
// void (*)(void) 인자
// int (*)(void) (*)(void (*)(void)) pof_test(void (*p)(void))
// 	pof_test(void (*p)(void))
// int (*)(void) (* pof_test(void (*p)(void)))(void (*)(void))
// int (* (* pof_test(void (*p)(void)))(void (*)(void)))(void) : prototype

int (* (* pof_test(void (*p)(void)))(void(*)(void)))(void)
{
	printf("pof_test\n");
	p();
	return test_test;
}
// ???? pof_test ????
// {
//	return test_test;
// }

int main(void)
{
	int res;

	res = pof_test(test)(test)(); 
	printf("res = %d\n", res);

	return 0;
}

