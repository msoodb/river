#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
	int id;
	char *name;
};

struct node
{
	struct element *data;
	struct node *left;
	struct node *right;	
};

int elmcmp(struct element *elm1, struct element *elm2)
{
	return strcmp(elm1->name, elm2->name);
}

void insert(struct node **root, struct element *e)
{
	if (*root == NULL) {
		*root = (struct node *)malloc(sizeof(struct node));
		(*root)->data = e;
	}
}

void print(struct node *root)
{
	printf("%s\n", root->data->name);
}

int main(int argc, char *argv[])
{
	struct node *root = NULL;
	struct element *e = NULL;
	e = (struct element *)malloc(sizeof(struct element));
	e->id = 1;
	e->name = "root node";
	insert(&root, e);
	print(root);
	
	return 0;
}
