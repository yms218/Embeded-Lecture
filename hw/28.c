#include <stdio.h>
#include <stdlib.h> // malloc

typedef struct __stack
{
	int data;
	struct __stack *link;
} stack;

stack *get_stack_node(void)
{
	stack *tmp = (stack *)malloc(sizeof(stack));
	tmp->link = NULL;
	return tmp;
}

void push(stack **top, int data)
{
	stack *tmp = *top;
	*top = get_stack_node();
	(*top)->data = data;
	(*top)->link = tmp;
}

int pop(stack **top)
{
	int res;
	if((*top))
	{
		stack *tmp = *top;
		res = (*top)->data;
		(*top) = (*top)->link;
		free(tmp);
	}
	return res;
}



int main(void)
{
	stack *top = NULL;
	push(&top, 1);
	push(&top, 2);
	printf("data = %d\n", pop(&top));
	return 0;
}
