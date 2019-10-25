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
	struct node *left, *right;
};

int elmcmp(struct element *elm1, struct element *elm2)
{
	return strcmp(elm1->name, elm2->name);
}

struct node *create_node(struct element *e)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL) {
		new = NULL;
		goto out_failure;
	}
	new->data = e;
	new->left = NULL;
	new->right = NULL;
	
out_sucsess:
	return new;	
out_failure:
	return new;
}

void insert(struct node **root, struct element *e)
{
	struct node *new = create_node(e);
	struct node *current = *root;
	struct node *itr;
		
	itr = current;
	while (itr != NULL) {
		current = itr;
		if (e->id > itr->data->id) {			
			itr = itr->right;
		}else if (e->id < itr->data->id){			
			itr = itr->left;
		}else{
			return;
		}
	}

	if (current == NULL) {
		*root = new;		
		return;
	}

	if (e->id > current->data->id) {
		current->right = new;
	}else if (e->id < current->data->id){
		current->left = new;
	}else{
		return;
	}
	return;
}

void print(struct node *root)
{
	if (root == NULL) {
		return;
	}
	printf("%d\n", root->data->id);
	if (root->left != NULL) {
		printf("%d  ", root->left->data->id);
	}else {
		printf("---");
	}
	if (root->right != NULL) {
		printf("%d  ", root->right->data->id);
	}else {
		printf("---");
	}
	printf("\n");
	print(root->left);
	print(root->right);
}

int main(int argc, char *argv[])
{
	struct node *root = NULL;
	struct element *e = NULL;
	
	int i;
	int N = 10;
	int numbers[10] = {10, 6, 3, 7, 12, 11 ,34, 4, 9, 23}; 
	//srand(time(0));
	for (i = 0; i < N; ++i) {
		e = (struct element *)malloc(sizeof(struct element));
		e->id = numbers[i];
		e->name = "root node";
		insert(&root, e);		
	}
	print(root);	
	return 0;
}
