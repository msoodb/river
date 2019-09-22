#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void push(struct node *head, int data)
{	
	/* create tmp node */
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	if (tmp == NULL) {
		printf("%s\n", "out of memory!");
		return;
	}
	tmp->data = data;
	tmp->next = NULL;

	/* insert tmp node in list */
	tmp->next = head->next;
	head->next = tmp;

	/* return tmp node */
	return;
};

int print(struct node* head)
{
	if(head == NULL){
		return 0;
	}
	struct node* tmp = head->next;
	do
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
		
	} while (tmp != NULL);	
}

int main(int argc, char *argv[])
{
	struct node *numbers = NULL;
	numbers  = (struct node *)malloc(sizeof(struct node));
	if (numbers == NULL) {
		printf("%s\n", "out of memory!");
		return 1;
	}
	push(numbers, 14);
	push(numbers, 98);
	push(numbers, 42);
	print(numbers);
	return 0;
}
