#include<stdio.h>
#include<stdlib.h> // malloc function
#include<string.h> // memset function

int main(void)
{
	int n, m;
	float *ResultMatrix1xM;
	float **MatrixNxM;

	// N by M Matrix를 입력받는다
	printf("N행 M열 행렬에서 N값과 M값을 차례대로 입력하시오.\n");
	scanf("%d %d", &n, &m);

	// N by M Matrix 동적 메모리 할당
	MatrixNxM = (float **)malloc(m*sizeof(float*));
	for (int i = 0; i < m; i++){
		MatrixNxM[i] = (float*)malloc(n*sizeof(float));
	}

	// 1 by M Matrix 동적 메모리 할당
	ResultMatrix1xM = (float *)malloc(m*sizeof(float));

	// N by M matrix 값을 입력받는다
	printf("%d행 %d열을 차례대로 입력하시오\n", n, m);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
			scanf("%f", &MatrixNxM[i][j]);

	}

	// 결과값을 입력받는다
	printf("결과값 %d를 차례대로 입력하시오\n", m);
	for (int i = 0; i < m; i++)
		scanf("%f", ResultMatrix1xM[i]);

	ShowMatrixNxM(n, m, MatrixNxM);
	// free
	for (int i = 0; i < m; i++){
		free(MatrixNxM[i]);
	}
	free(MatrixNxM);
}



float ShowMatrixNxM(int *row, int *col, float **mat)
{
	for (int i = 0; i < col; i++){
		for (int j = 0; j < row; j++){
			printf("%f  ", mat[i][j]);
		}
		printf("\n");
	}
}



void FindSolution(int row, float **mat, int *result)
{
	// 첫번째 row 에 어떤 값을 곱해서 더하면 1행2열 값이 0이되는 a값

	float a = -1 * (mat[1][0] / mat[0][0]);
	float b = -1 * (mat[2][0] / mat[0][0]);
	float c = -1 * (mat[2][1] / mat[1][1]);

	// 두번째 row 와 첫번째 row * a 를 더한다.

	for (int i = 0; i < row; i++)
		mat[1][i] += mat[0][i] * a;
	result[1] += a*result[0];

	// 세번째 row 의 첫번째 값도 0으로 만든다.

	for (int i = 0; i < row; i++)
		mat[2][i] += mat[0][i] * b;
	result[2] += b*result[0];

	for (int i = 0; i < row; i++)
		mat[2][i] += mat[1][i] * c;
	result[2] += c*result[1];

	result[2] = result[2] / mat[2][2];
}
