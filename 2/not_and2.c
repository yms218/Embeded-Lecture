#include <stdio.h>

int check_order(int num)
{
	return num & ~((1<<12) - 1);
}




int main(void)
{
	int num = 4095;


	printf("res = %d\n", check_order(num));
	num = 7183;
	
	printf("res = %d\n", check_order(num));
	num = 9134;

	printf("res = %d\n", check_order(num));
	num = 15423;

	printf("res = %d\n", check_order(num));
	num = 20000;

	return 0;
}
