/*
 * This is the simple implementaion of linked list.
 * Please use it consistently and contribite on it.
 * Description: data structure to store a linked list.
 */

/*
 * create_node
 * push
 * append
 * is_empty
 * pop
 * top
 * reverse
 * print
 * erase   erase entire list
 * lenght
 * delete  delete given node
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	struct node *prev, *next;
};

struct node *create_node(int data)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node == NULL) {
		new_node = NULL;
		goto out;
	}	
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
out:
	return new_node;
}

int is_empty(struct node *head)
{
	return head == NULL;
}

void push(struct node **ptr_head, int data)
{
	struct node *new_node = create_node(data);
	struct node *current;

	current = *ptr_head;
	*ptr_head = new_node;
	new_node->next = current;
}

void append(struct node **ptr_head, int data)
{
	if (*ptr_head == NULL) {
		push(ptr_head, data);
		goto out;
	}
	
	struct node *current;
	struct node *itr;

	current = *ptr_head;
	itr = current;

	while (itr != NULL) {
		current = itr;
		itr = itr->next;
	}
	push(&current->next, data);
out:
	return;
}

void pop(struct node **ptr_head, int *data)
{
	if (*ptr_head == NULL)
		goto out;
	
	struct node *current;
	current = *ptr_head;

	*ptr_head = (*ptr_head)->next;
	*data = current->data;
	free(current);
out:
	return;
}

int top(struct node *head, int *data)
{
	if (head != NULL) {
		*data = head->data;
		return 1;
	}
	
	return 0;
}

void reverse(struct node **ptr_head)
{
	struct node *prev;
	struct node *current;
	struct node *itr;

	prev = NULL;
	current = *ptr_head;

	itr = current;
	while (itr != NULL) {
		current = itr;
		itr = itr->next;		
		current->next = prev;
		prev = current;		
	}
	
	*ptr_head = current;
}

int delete (struct node **ptr_head, int location)
{
	struct node *current;
	struct node *itr;
	
	current = *ptr_head;
	itr = current;

	int i = 0;
	while (itr->next != NULL) {
		current = itr;
		if (i++ == location-1) {
			itr = itr->next;
			current->next = itr->next;
			free(itr);
			goto out_success;
		}
		itr = itr->next;
	}

out_failure:
	return 0;
out_success:
	return 1;

}

void erase(struct node **ptr_head)
{
	struct node *current;
	current = *ptr_head;
	
	while (*ptr_head) {
		current = *ptr_head;
		*ptr_head = (*ptr_head)->next;
		free(current);
	}
}

int lenght(struct node *head)
{
	int lenght = 0;
	struct node *current;
	current = head;
	while (current != NULL) {
		++lenght;
		current = current->next;
	}
	return lenght;
}

void print(struct node *head)
{
	int node_number = 0;
	while (head != NULL) {
		printf("node %d = %d\n", node_number++, head->data);
		head = head->next;
	}	
}

int main(int argc, char *argv[])
{
	struct node *head;

	if (is_empty(head))
		printf("list is empty\n");
	else 
		printf("list is not empty\n");

	push(&head, 4);
	push(&head, 6);
	push(&head, 12);
	push(&head, 5);
	push(&head, 9);
	push(&head, 2);

	print(head);
	
	delete(&head, 0);

	printf("\n");
	
	print(head);

	return 0;
	
	
	int t;
	if (top(head, &t)) {
		printf("top is %d\n", t);
	}
			
	append(&head, 7);

	print(head);

	reverse(&head);

	print(head);

	if (is_empty(head))
		printf("list is empty\n");
	else
		printf("list is not empty\n");
	
	printf("lenght of head is : %d\n", lenght(head));
	
	erase(&head);

	return 0;
}
