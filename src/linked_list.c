#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void push(struct node** ptrhead, int data)
{		
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	if (tmp == NULL) {
		printf("%s\n", "out of memory!");
		return;
	}

	tmp->data = data;
	tmp->next = NULL;

	if (*ptrhead != NULL) {
		tmp->next = *ptrhead;
	}	
	*ptrhead = tmp;
}

void insert(struct node** ptrhead, int position, int data)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	if (tmp == NULL) {
		printf("%s\n", "out of memory!");
		return;
	}
	tmp->data = data;
	tmp->next = NULL;
	
	if (position == 1) {
		tmp->next = *ptrhead;
		*ptrhead = tmp;
		return;
	}
	struct node *tmp2 = *ptrhead;
	for (int i = 0; i < position-2; ++i) {
		tmp2 = tmp2->next;			
	}
	tmp->next = tmp2->next;
	tmp2->next = tmp;
}

int pop(struct node** head)
{
}

void print(struct node* head)
{		
	do
	{
		printf("%d ", head->data);
		head = head->next;
		
	} while (head != NULL);
	printf("\n");
}

int main(int argc, char *argv[])
{
	struct node* numbers = NULL;
	
	push(&numbers, 14);
	push(&numbers, 98);
	push(&numbers, 42);
	print(numbers);
	insert(&numbers,3, 99);
	print(numbers);

	//printf("pop: %d\n", pop(numbers));
	//printf("pop: %d\n", pop(numbers));	
	//print(numbers);
	return 0;
}
