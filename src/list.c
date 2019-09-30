/*
 * This is the simple implementaion of linked list.
 * Please use it consistently and contribite on it.
 *
 * Description: data structure to store a linked list.
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	
};

struct node *create_node(int data)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node == NULL) {
		new_node = NULL;
		goto out;
	}	
	new_node->data = data;
	new_node->next = NULL;
out:
	return new_node;
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
	if (*ptr_head == NULL) {
		goto out;
	}
	struct node *current;
	current = *ptr_head;

	*ptr_head = (*ptr_head)->next;
	*data = current->data;
	free(current);

out:
	return;
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

int is_empty(struct node *head)
{
	return head == NULL;
}

void delete (struct node **ptr_head)
{
	struct node *current;
	current = *ptr_head;
	
	while (*ptr_head) {
		current = *ptr_head;
		*ptr_head = (*ptr_head)->next;
		free(current);
	}
}

void print(struct node *head)
{
	while (head != NULL) {
		printf("%d\n", head->data);
		head = head->next;
	}	
}

int main(int argc, char *argv[])
{
	struct node *head;

        /* check list is empty or not */
	if (is_empty(head)) {
		printf("list is empty\n");
	}else {
		printf("list is not empty\n");
	}


        /* push to list */
	push(&head, 4);
	push(&head, 6);

	/* append to end of list */
	append(&head, 7);

	/* print entire list */
	print(head);

	/* reverse list */	
	reverse(&head);

	/* print entire list */
	print(head);

	/* check list is empty or not */
	if (is_empty(head)) {
		printf("list is empty\n");
	}else {
		printf("list is not empty\n");
	}
	
	/* delete list */
	delete(&head);


	return 0;
}
