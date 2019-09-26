#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

struct vessel
{
	int id;
	char *name;
	char *lastname;
	char *addres;
	int status;
};

struct node
{
	struct vessel *data;
	struct node *prev;
	struct node *next;
	
};

struct vessel* create_student(int id, char *name, char *lastname,
			    char *addres, int status)
{
	struct vessel *tmp = (struct vessel*) malloc(sizeof(struct vessel));
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

void print_student_header()
{
	printf("%-6s", "id");
	printf("%-20s", "name");
	printf("%-20s", "lastname");
	printf("%-30s", "addres");
	printf("%-6s", "status");
	printf("\n");
	printf("------------------------------------------");
	printf("------------------------------------------");
	printf("\n");
}

void print_student(struct vessel *student)
{
	printf("%-6d", student->id);
	printf("%-20s", student->name);
	printf("%-20s", student->lastname);
	printf("%-30s", student->addres);
	printf("%-6d", student->status);
	printf("\n");
}


void push(struct node **ptrhead, struct vessel *data)
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

struct vessel* pop(struct node **ptrhead)
{
	if (*ptrhead == NULL) {
		return NULL;
	}
	struct node *tmp = *ptrhead;
	struct vessel *data = (*ptrhead)->data;
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

void serialize(struct node *head, char *file)
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

void serialize_binary(struct node *head, char *file)
{
	/* FILE *fp = fopen(file, "wb"); */
	/* if (fp == NULL) { */
	/* 	printf("error file : %s\n", file); */
	/* 	return; */
	/* } */
	
	/* while (head != NULL) { */
	/* 	fwrite(&(head->vesselc->id), sizeof(int), 1, fp); */
	/* 	head = head->next; */
	/* } */
	/* fclose(fp); */
}

void deserialize_binary(struct node **ptrhead, char *file)
{
	/* FILE *fp = fopen(file, "rb"); */
	/* if (fp == NULL) { */
	/* 	printf("error file : %s\n", file); */
	/* 	return; */
	/* } */

	/* struct data *student = (struct data *)malloc(sizeof(struct data *));	 */
	
	/* while ( != NULL) { */
	/* 	fread(&(vesselc->id), sizeof(int), 1, fp); */
	/* 	head = head->next; */
	/* } */
	/* fclose(fp); */
}

void print(struct node *ptrhead)
{
	printf("\n");
	print_student_header();
		
	while (ptrhead != NULL) {
		print_student(ptrhead->data);
		ptrhead = ptrhead->next;
	}
	printf("\n");
}



void print_recursive_data(struct node *ptrhead)
{	
	if(ptrhead == NULL)		
		return;
	print_student(ptrhead->data);
	print_recursive_data(ptrhead->next);
}

void print_recursive(struct node *ptrhead)
{
	printf("\n");
	print_student_header();
	print_recursive_data(ptrhead);	
	printf("\n");
}

void init(struct node **ptrhead)
{
	/* create data and push*/
	struct vessel *student;
	student = create_student(101, "masoud", "bolhassani", "Tallinn Estonia", 1);
	push(ptrhead, student);
	
	struct vessel *student2;
	student2 = create_student(102, "mai", "volka", "Tallinn Estonia", 1);
	push(ptrhead, student2);

	struct vessel *student3;
	student3 = create_student(103, "miloo", "volf", "Tallinn Estonia", 1);
	push(ptrhead, student3);
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

int help()
{
	printf("\n");
	printf("   init : initialize list\n");
	printf("   push : push to list\n");
	printf("    pop : pop from list\n");
	printf("reverse : reverse list\n");
	printf("  print : print entire list\n");
	printf("   save : save list on file\n");
	printf("   help : show help\n");
	printf("    q/Q : quit\n");
	printf("\n");
}

int main(int argc, char *argv[])
{
	printf("river:& ");
	struct node *students = NULL;
	struct vessel *student;
	
	char cmd[BUFFER_SIZE];
	fgets(cmd, BUFFER_SIZE, stdin);
	strtok(cmd, "\n");
	while (cmd != "q" && cmd != "Q") {		
		if (strcmp(cmd, "init") == 0) {
			init(&students);
		}else if (strcmp(cmd, "push") == 0) {
			;
		}else if (strcmp(cmd, "pop") == 0) {
			student = pop(&students);
		}else if (strcmp(cmd, "reverse") == 0) {
			reverse(&students);
		}else if (strcmp(cmd, "print") == 0) {
			print_recursive(students);
		}else if (strcmp(cmd, "save") == 0) {
			serialize(students, "students.txt");
		}else if (strcmp(cmd, "help") == 0) {			
			help();
		}else if ((strcmp(cmd, "q") == 0) || (strcmp(cmd, "Q") == 0)) {
			break;
		}else {
			help();
		}
		printf("river:& ");
		fgets(cmd, BUFFER_SIZE, stdin);
		strtok(cmd, "\n");
	}
	
	free_list(&students);
	free(student);
	
	return 0;
}
