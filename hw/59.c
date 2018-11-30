#include <stdio.h>
#include <math.h>
#define PI 3.141592
// 복소수 구조체
struct Complex
{
	int rNumber;
	int iNumber;
};



int main(void)
{
	int i, j;
	struct Complex w[4][4] = {
	{{1,0}, {1,0}, {1,0}, {1,0}},
	{{1,0}, {0,-1}, {-1,0}, {0,1}},
	{{1,0}, {-1,0}, {1,0}, {-1,0}},
	{{1,0}, {0,1}, {-1,0}, {0,-1}}
	};
	double x[4] = {0,1,2,3};
	double X[4] = {0};

	printf("x[4] = {0,1,2,3}\n");

	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++)
			printf("%d + %di   ", w[i][j].rNumber, w[i][j].iNumber);
	printf("\n");	
	}
	return 0;		

	
}
