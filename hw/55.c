#include <stdio.h>

int main(void)
{
	printf("24비트 DAC이며 동작범위 -12V ~ 12V DAC에서 9.7V이다.\n");
	printf("디지털신호 = %f \n", 
		((9.7*1024.0*1024.0*16.0)/12.0));
}
