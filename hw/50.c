#include <stdio.h>
#include <stdlib.h>

int *make_matrix(int num)
{
	int i,j;
	int data;
	int **A = (int **)malloc(num*sizeof(int *));
	printf("값을 입력하시오\n");
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			A[j] = (int *)malloc(num*sizeof(int)); 
			fflush(stdin);
			scanf("%d", &data);
			A[i][j] = data;
		}
		printf("\n");
	}
	return A;
}

void print_matrix(int arr[num][num], int num)
{
	int i,j;
	for(i=0; i<num; i++)
		for(j=0; j<num; j++)
			printf("%3d ", arr[i][j]);
		printf("\n");
}


int main(void)
{
	int num;
	int arr[3][3] = {0};
	printf("2x2 또는 3x3행렬\n");
	scanf("%d ", &num);
	make_matrix(num);
	
	return 0;

}
