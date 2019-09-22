#include <stdio.h>
#include <stdlib.h>

struct data
{
	int key;
	int value;
};
	

struct node
{
	struct data *n_data;
	struct node *next;
};

struct node* push(struct node *head, int key, int value)
{
	struct node *node_c = (struct node *)malloc(sizeof(struct node));
	if (node_c == NULL) {
		printf("%s\n", "out of memory!");
		return NULL;
	}
	struct data *data_c = (struct data*)malloc(sizeof(struct data));
	if (data_c == NULL) {
		printf("%s\n", "out of memory!");
		return NULL;
	}
	data_c->key = key;
	data_c->value = value;
	node_c->n_data = data_c;
	node_c->next = head;

	return node_c;
};

int print(struct node* head)
{
	do
	{
		printf("key : %d, value : %d\n", head->n_data->key, head->n_data->value);
		head = head->next;
	} while (head->next != NULL);
	return 1;
}

int main(int argc, char *argv[])
{
	struct node *head;
	head = (struct node *)malloc(sizeof(struct node));
	if (head == NULL) {
		printf("%s\n", "out of memory!");
		exit(1);
	}
	struct data *d = (struct data*)malloc(sizeof(struct data));
	if (d == NULL) {
		printf("%s\n", "out of memory!");
		exit(1);
	}
	d->key = 0;
	d->value = 42;
	head->n_data = d;

	struct node *second = push(head, 1, 43);
	struct node *current = push(second, 2, 44);
	
	if (current == NULL) {
		printf("%s\n", "out of memory!");
		exit(1);	
	}
	print(current);
	return 0;
}
