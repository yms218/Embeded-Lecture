#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_arr(int (*arr)[2])
{
	int i, j;

	srand(time(NULL));
	for(i=0; i<2; i++)
		for(j=0; j<2; j++)
		{
			arr[i][j] = rand() % 9 + 1;
			printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
		}
}
// 접근할수없는 메모리 접근 (세그멘테이션 오류 : 포인터 배열쪽에 실수의심)
// 이것은 지역변수를 return하는 것이므로 동작하지 않음
#if 0 
void (* cant_ret_arr(void))[2]
{
	int arr[2][2] = {0};
	init_arr(arr);
	return arr;
}
#endif

void test(void)
{	
	printf("test\n");
}





// prototype : int (*)[2] arr_ret(void)
int (* arr_ret(void))[2]
{
	// (중요) static은 선언된 함수 내에서만 전역 변수처럼 동작
	static int arr[2][2] = {0};

	init_arr(arr);

	return arr;
}

// int (*)[2] arr_ret(void)  arr_pof(void (*p)(void)) 인자는 함수포인터로 받기 때문에
// 보기 쉽게 바꿔놓은 prototype
// int (*)[2]   (*)  (void)  arr_pof(void (*p)(void))
// int (*)[2]   (* arr_pof(void (*p)(void)))(void)
// int (* (* arr_pof(void (*p)(void)))(void))[2]
int (* (* arr_pof(void (*p)(void)))(void))[2]
{
	printf("arr_pof\n");
	p();
	return arr_ret;
}


int main(void)
{
	int i,j;
	int (*p)[2];
	p = arr_ret();
	printf("p[0][0] = %d\n", p[0][0]);
	
	// p = cant_ret_arr();
	// printf("p[0][0] = %d\n", p[0][0]);
	// printf("arr = 0x%x\n", arr);
	p = arr_pof(test)();	
	for(i=0; i<2; i++)
		for(j=0; j<2; j++)
			printf("p[%d][%d] = %d\n", i, j, p[i][j]);			

	return 0;
}

