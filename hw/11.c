#include <stdio.h>

int main(void)
{
	int i;
	int arr[4] = {0};
	for(i=1; i<=100; i++)
	{
		arr[0] += i;
		if(i%2)
			arr[1] += i;
		if(!(i%2))
			arr[2] += i;
		if(!(i%4))
			arr[3] += i;
	}
	printf(" sum = %d\n", arr[0] + arr[1] + arr[2] + arr[3]);
}
