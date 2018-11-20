#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct __person
{
	int age;
	char name[28];
} person;

typedef struct __score
{
	int math;
	int english;
	int physics;
} score;


typedef struct __school // score는 school과 같이 동적할당 받음 person은 따로 동적할당 해줘야함
{
	person *p; 
	score s;
	char name[24];	
} school;

school *init_struct(void)
{
	school *tmp = (school *)malloc(sizeof(school));
	tmp->p = (person *)malloc(sizeof(person));
	
	tmp->p->age = 22;
	strcpy(tmp->p->name, "Jesica");

	tmp->s.math = 70;
	tmp->s.english = 80;
	tmp->s.physics = 20;

	strcpy(tmp->name, "Test Univ");
	return tmp;
}

void print_struct(school *s)
{
	printf("School Name = %s\n", s->name);
	printf("Student Name = %s\n", s->p->name);
	printf("Age = %d\n", s->p->age);

	printf("Student Score\n");
	printf("Math - %d, English - %d, Physics - %d\n", s->s.math, s->s.english, s->s.physics);

}



int main(void)
{
	school *s = NULL;
	s = init_struct();
	printf("sizeof(school) = %d byte\n", sizeof(school));
	printf("sizeof(score) = %d byte\n", sizeof(score));
	printf("sizeof(person) = %d byte\n", sizeof(person));
	print_struct(s);
	init_struct();
	// 지우는 순서 : 작은거부터 큰
	free(s->p);
	free(s);
	return 0;
}
