#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	struct node *prev, *next;
};

struct node *create_node(int data);
int is_empty(struct node *head);
void push(struct node **ptr_head, int data);
void append(struct node **ptr_head, int data);
void pop(struct node **ptr_head, int *data);
int top(struct node *head, int *data);
void reverse(struct node **ptr_head);
int delete (struct node **ptr_head, int location);
void erase(struct node **ptr_head);
int lenght(struct node *head);
void print(struct node *head);

#endif //LIST_H
