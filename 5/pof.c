#include <stdio.h>

// void (*)(void) : 함수의 이름은 주소
void test(void)
{
	printf("test\n");
}


int main(void)
{
	void (*p)(void) = test; // void 인자로 받고 void return하는 포인터가 오른쪽 test를 받음
	p(); // test가 호출됨 test();
	
	return 0;
}

