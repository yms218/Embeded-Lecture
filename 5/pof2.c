#include <stdio.h>

// void (*)(void) : 함수의 이름은 주소
void test(void)
{
	printf("test\n");
}

// int (*p)[3] vs int *p[3] c언어 문법구조상 배열 뒤쪽에다가 포인터 붙일 수 없다.
// int[3](*)   vs (int *)[3] p

// void (*)(void) test_test(void) : 함수포인터 
void (* test_test(void))(void)
{
	printf("test_test\n");
	return test;
}


int main(void)
{

	test_test()(); // test가 호출됨 test();
	return 0;
}

