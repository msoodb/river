#ifndef LIST_H
#define LIST_H

struct element
{
	int id;
	char *name;
	char *lastname;
	char *addres;
	int status;
};

struct node
{
	struct element *data;
	struct node *prev;
	struct node *next;
	
};

struct element* create_element(int id, char *name, char *lastname,
			       char *addres, int status);
void print_elemtn_header();
void print_element(struct element *data);
void push(struct node **ptrhead, struct element *data);
struct element* pop(struct node **ptrhead);
void reverse(struct node **ptrhead);
void save(struct node *head, char *file);
void print(struct node *ptrhead);
void print_recursive_data(struct node *ptrhead);
void print_recursive(struct node *ptrhead);
void init(struct node **ptrhead);
void free_list(struct node **ptrhead);

#endif //LIST_H
