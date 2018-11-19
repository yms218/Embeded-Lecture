#include <stdio.h>

#if 0
unsigned 가 붙으면 무조건 양수
없으면 음수와 양수가 양립
char는 1byte = 8bit = 256개
부호비트를 하나 만들었고 부호비트는 최상위에 배치됨
부호비트가 1이면 음수, 0이면 양수
#endif

int main(void)
{
	char num2 = 10;	
	unsigned char num1 = 10;
	printf("not num = %u\n", (unsigned char)~num1);
	printf("not num = %d\n", (char)~num2);
	return 0;
}

