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
	push(&head, 4);
	push(&head, 6);
	print(head);
	return 0;
}
