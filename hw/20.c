#include <stdio.h>
// 대문자 S는 10진수로 83 대문자
int main(void)
{
	int i = 0;
	char text[] = "TI Cortex-R5F Safety MCU is very good to Real-Time System";
	printf("%s\n", text);
	while(!(text[i] == 83))
	{
		i++;
	}
	// i=0부터 시작하므로 1을 더함
	printf("Safety Mcu는 배열의 %d번째부터 시작한다\n", i+1);
	return 0;
}
