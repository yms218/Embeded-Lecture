#include <stdio.h>

void init_arr(int (*arr)[2]) // int (*)[2] : (*)은 i파트 [2] 는 j파트
{
	int i, j, cnt = 1;

	for(i=0; i<3; i++)
		for(j=0; j<2; j++)
			arr[i][j] = cnt++;
}
// int (*)[3] p의 데이터타입임
void test_arr_pnt(int (*p)[3])
{
	int i, j;

	for(i=0; i<2; i++)
		for(j=0; j<3; j++)
			printf("p[%d][%d] = %d\n", i, j, p[i][j]);
}


void print_arr(int (*arr)[2])
{
	int i, j;
	for(i=0; i<3; i++)
		for(j=0; j<2; j++)
			printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
}

void init_pnt_arr(int **pnt_arr, int (*arr)[2]) // 주소의 주소를 받으니까 더블 포인터
{
	int i;
	
	for(i=0; i<3; i++)
		pnt_arr[i] = arr[i]; //왼쪽 오른쪽 둘다 8바이트 배열의 이름은 주소(시작주소) 
				     //시작주소의 값을 저장하는 중
}

void test_arr_func(int (*p)[2])
{
	printf("*(*p+1) = %d\n", *(*p+1));
	printf("*(*p+3) = %d\n", *(*p+3));
	printf("**p = %d\n", **p);
	printf("**(p+1) = %d\n", **(p+1));
	printf("**(p+2) = %d\n", **(p+2));
}




int main(void)
{
	int i;
	int arr[3][2] = {0}; // * int(*)[2] arr : int 2개짜리 array
	// ([][])([][])([][]) 뒤쪽의 대괄호는 가장 작은 단위가 몇개 있는지
	// 그 앞쪽의 대괄호는 그 작은 단위의 묶음이 몇 개 있는지를 나타낸다.
	int *pnt_arr[3] = {0}; // 포인터 배열 : 포인터를 저장하는 배열(주소값들이 옴)
			       // 데이터 타입 : ((int *)[]) *
	int (*p)[4] = NULL;    // 배열 포인터
			       // 데이터 타입 : (int (*)[3]) : int형 3개짜리 배열을 가리킴
	
	init_arr(arr);
	print_arr(arr);

	init_pnt_arr(pnt_arr, arr);
	
	for(i=0; i<3; i++)
		printf("*pnt_arr[%d] = %d 0x%x\n",i, *pnt_arr[i], pnt_arr[i]);	

	p = arr;
	printf("p[0] = %d", *p[0]);
	printf("p[1] = %d", *p[1]);
  	// *만 있으면 참조연산 저 주소에 접근하라 데이터 타입이 없기 때문에

	test_arr_pnt(p);	
	test_arr_func(arr);
	return 0;
}
