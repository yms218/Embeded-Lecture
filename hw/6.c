/* 정적분 프로그램 구현
수치적분을 통해 구현할텐데 가장 쉬운 Rectangle Method으로 이용해보자
*/

#include <stdio.h>
// 적분 구간 a, b, 함수를 받아야함

double numerical_rect(double a, double b, double (*f)(double), int n)
{
	int i;
	double h = (b-a) / n;
	double sum = 0;
	printf("a = %lf, b = %lf, h = %lf, n = %d\n", a,b,h,n);
	for(i=0; i<n; i++)
		sum += f(a+h/2+i*h)*h;
	return sum;
}

double function(double x)
{
	return (3*x*x + 7*x);
}

int main(void)
{
	double a = 1.0, b = 2.0;
	printf("%lf\n", numerical_rect(a,b,function, 100));
	return 0;
}


