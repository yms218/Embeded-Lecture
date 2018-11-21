#if 0
자료구조 학습의 의의
SW 개발자에 있어서 머리속 생각을 프로그램 코드로 바꾸는 것이 무엇보다 중요하다.
이것이 불가능하다면 단순한 코더가 되고, 이것이 가능해진다면 비로소 그 때 SW
개발자가 될수있다. 자료구조를 학습하는 이유는 머리속에서 생각한 내용을 코드로 
변환하는 훈련을 하는 일련의 절차라고 보면 된다.
익숙해지면 이후에는 생각한 대부분의 모든 것들을 프로그램 코드로 바꿀 수 있다.
#endif
// 가장 마지막에 넣은 40이 제일 먼저 나옴 후입선출
#include <stdio.h>
#include <stdlib.h>

typedef struct __stack
{
	int data; 
	struct __stack *link; // 다른 구조체에 접근
} stack;

stack *get_stack_node(void)
{
	stack *tmp = (stack *)malloc(sizeof(stack)); 
	tmp->link = NULL;

	return tmp;
}

// 재귀는 링크가 top으로

void push(stack **top, int data)
{
	stack *tmp = *top;
 	*top = get_stack_node();
	(*top)->data = data;
	(*top)->link = tmp;
}

/*
void enqueue(stack **top, int data)
{	
	if(*top == NULL)
	{
		*top = get_stack_node();
		(*top)->data = data;
	}
	else
		enqueue(&((*top)->link), data);
}


void dequeue(stack **top, int data)
{
	stack *tmp = (*top)->link;
	if(tmp -> data == data)
	{
		(*top)->link = tmp->link;
		printf("\npop data : %d\n\n", tmp->data);
		free(tmp);
	}
	else	
		dequeue(&(*top)->link, data);

}
*/
void print_stack(stack *top)
{
	stack *tmp = top;
	
	while(tmp)
	{
		printf("tmp->data = %d\n", tmp->data);
		tmp = tmp->link;
	}
}

int pop(stack **top)
{
	int re_value;
	stack *tmp = *top;

	if(!tmp)
	{
		printf("Empty Stack\n");
		return 0;
	}

	re_value = (*top)->data;
	(*top) = (*top)->link;
	free(tmp);        

	return re_value;
}

int main(void)
{
	int i;
	stack *top = NULL;

	for(i=1; i<=4; i++)
		push(&top, i*10);
	print_stack(top);
	for(i=1; i<=4; i++)
		printf("pop data = %d\n", pop(&top));
	return 0;
}






