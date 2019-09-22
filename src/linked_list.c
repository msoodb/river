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

int push(struct node *head, int key, int value)
{
	struct node *node_c = (struct node *)malloc(sizeof(struct node));
	if (node_c == NULL) {
		printf("%s\n", "out of memory!");
		return 1;
	}
	struct data *data_c = (struct data*)malloc(sizeof(struct data));
	if (data_c == NULL) {
		printf("%s\n", "out of memory!");
		return 1;
	}
	data_c->key = key;
	data_c->value = value;
	node_c->n_data = data_c;
	node_c->next = head;
	return 0;
}

int print(struct node* head)
{
	do
	{
		printf("key : %d, value : %d\n", head->n_data->key, head->n_data->value);
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

	push(head, 1, 43);
	print(head);
	
	return 0;
}
