#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element* create_element(int id, char *name, char *lastname,
			    char *addres, int status)
{
	struct element *tmp = (struct element*) malloc(sizeof(struct element));
	if(tmp == NULL){
		printf("out of memory\n");
		return NULL;
	}		
	tmp->id = id;
	tmp->name = name;
	tmp->lastname = lastname;
	tmp->addres = addres;
	tmp->status = status;

	return tmp;
}

void print_elemtn_header()
{
	printf("%-6s", "id");
	printf(" | ");
	printf("%-20s", "name");
	printf(" | ");
	printf("%-20s", "lastname");
	printf(" | ");
	printf("%-30s", "addres");
	printf(" | ");
	printf("%-6s", "status");
	printf("\n");
	printf("----------------------------------------------");
	printf("----------------------------------------------");
	printf("\n");
}

void print_element(struct element *data)
{
	printf("%-6d", data->id);
	printf(" | ");
	printf("%-20s", data->name);
	printf(" | ");
	printf("%-20s", data->lastname);
	printf(" | ");
	printf("%-30s", data->addres);
	printf(" | ");
	printf("%-6d", data->status);
	printf("\n");
}

void push(struct node **ptrhead, struct element *data)
{
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	if (tmp == NULL) {
		printf("out of memory!\n");
		return;
	}
	tmp->data = data;
	tmp->prev = NULL;
	tmp->next = NULL;

	if (*ptrhead != NULL) {
		tmp->next = (*ptrhead);
		(*ptrhead)->prev = tmp;
	}
	*ptrhead = tmp;
}

struct element* pop(struct node **ptrhead)
{
	if (*ptrhead == NULL) {
		return NULL;
	}
	struct node *tmp = *ptrhead;
	struct element *data = (*ptrhead)->data;
	*ptrhead = (*ptrhead)->next;
	(*ptrhead)->prev = NULL;
	free(tmp->data);
	free(tmp);
	return data;
}

void reverse(struct node **ptrhead)
{	
	struct node *previous = NULL;
	struct node *current = *ptrhead;
	struct node *next = NULL;
		
	while (current != NULL) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*ptrhead = previous;	
}

void save(struct node *head, char *file)
{
	FILE *fp = fopen(file, "w");
	if (fp == NULL) {
		printf("error file : %s\n", file);
		return;
	}
	
	while (head != NULL) {
		fprintf(fp, "%d,", head->data->id);
		fprintf(fp, "%s,", head->data->name);
		fprintf(fp, "%s,", head->data->lastname);
		fprintf(fp, "%s,", head->data->addres);
		fprintf(fp, "%d", head->data->status);		
		fprintf(fp, "\n");
		head = head->next;
	}
	fclose(fp);
}

void print(struct node *ptrhead)
{
	printf("\n");
	print_elemtn_header();
	int rows=0;	
	while (ptrhead != NULL) {
		print_element(ptrhead->data);
		ptrhead = ptrhead->next;
		rows++;
	}
	printf(" (%d rows)\n",rows);
	printf("\n");
}

void print_recursive_data(struct node *ptrhead)
{	
	if(ptrhead == NULL)		
		return;
	print_element(ptrhead->data);
	print_recursive_data(ptrhead->next);
}

void print_recursive(struct node *ptrhead)
{
	printf("\n");
	print_elemtn_header();
	print_recursive_data(ptrhead);	
	printf("\n");
}

void init(struct node **ptrhead)
{	
	struct element *data1;
	data1 = create_element(101, "masoud", "bolhassani", "Tallinn Estonia", 1);
	push(ptrhead, data1);
	
	struct element *data2;
	data2 = create_element(102, "mai", "volka", "Tallinn Estonia", 1);
	push(ptrhead, data2);

	struct element *data3;
	data3 = create_element(103, "miloo", "volf", "Tallinn Estonia", 1);
	push(ptrhead, data3);
}

void free_list(struct node **ptrhead)
{
	struct node *tmp;
	while (*ptrhead != NULL){
		tmp = *ptrhead;
		*ptrhead = (*ptrhead)->next;
		free(tmp->data);
		free(tmp);
	}
}
