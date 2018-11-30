// 단 한번의 연산으로 대소문자를 전환
#include <stdio.h>

int main(void)
{
	char ch1 = 'A';
	char ch2 = 'a';
	printf("대문자를 : %c, 소문자로 : %c \n", ch1, (ch1^0x20));
	printf("소문자를 : %c, 대문자로 : %c \n", ch2, (ch2^0x20));
	return 0;
}
