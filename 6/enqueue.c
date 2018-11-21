#include <stdio.h>
#include <stdlib.h>

typedef struct __queue
{
	int data;
	struct __queue *link;
} queue;

queue *get_queue_node(void)
{
	queue *tmp = (queue *)malloc(sizeof(queue));
	tmp->link = NULL;
	return tmp;
}

void enqueue(queue **head, int data)
{
	if(!(*head))
	{
		*head = get_queue_node();
		(*head)->data = data;
		return;
	}
	enqueue(&((*head)->link), data);
}

void print_queue(queue *head)
{
	queue *tmp = head;
	while(tmp)
	{
		printf("data = %d\n", tmp->data);
		tmp = tmp->link;
	}
}

int main(void)
{
	int i;
	queue *head = NULL;
	for(i=1; i<5; i++)
		enqueue(&head, i*10);
	print_queue(head);
}

