#include <stdio.h>

int print_arr(int arr[][3])
{
	int i, j;
	for(i=0; i<2; i++){
		for(j=0; j<3; j++)
			printf("%3d", arr[i][j]);
	printf("\n");
	}
}

void func(int arr[][3])
{
	int j;
	for(j=0; j<3; j++)
		arr[1][j] = arr[0][j] * arr[0][j];
}

void sapply(int arr[][3], void (*p)(int arr[][3]))
{
	p(arr);
}

int main(void)
{
	int arr[2][3] = {{1,2,3}, {1,2,3}};
	print_arr(arr);
	sapply(arr, func);
	printf("\n");
	print_arr(arr);
	return 0;
}
