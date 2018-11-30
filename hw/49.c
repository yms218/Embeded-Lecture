#include <stdio.h>
#include <stdlib.h>

void print_vec(int vec3[])
{
	int i;
	for(i=0; i<3; i++)
		printf("vec[%d] = %d\n", i, vec3[i]);
	printf("\n");
}

void add_vec(int vec1[], int vec2[], int vec3[])
{
	int i;
	for(i=0; i<3; i++)
		vec3[i] = vec1[i] + vec2[i];
}

int inner_product(int vec1[], int vec2[])
{
	int i;
	int sum = 0;
	for(i=0; i<3; i++)
		sum += vec1[i]*vec2[i];
	return sum;
}

int ex_product(int vec1[], int vec2[], int vec3[])
{
	vec3[0] = vec1[1]*vec2[2] - vec1[2]*vec2[1];
	vec3[1] = -(vec1[0]*vec2[2] - vec1[2]*vec2[0]);
	vec3[2] = vec1[0]*vec2[1] - vec1[1]*vec2[0];
}


int main(void)
{
	int scalar = 0;
	int vec1[3] = {1,2,3};
	int vec2[3] = {-1,0,2};
	int vec3[3] = {0};
	print_vec(vec1);
	print_vec(vec2);
	printf("덧셈 : \n");
	add_vec(vec1, vec2, vec3);
	print_vec(vec3);
	printf("내적 : %d\n", inner_product(vec1, vec2));
	printf("외적 : \n");
	ex_product(vec1, vec2, vec3);
	print_vec(vec3);
	return 0;
}
