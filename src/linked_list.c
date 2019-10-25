#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

struct data
{
	int id;
	char *name;
	char *lastname;
	char *addres;
	int status;
};

struct node
{
	struct data *data_c;       
	struct node *next;
	
};

struct data* create_student(int id, char *name, char *lastname,
			    char *addres, int status)
{
	struct data *tmp = (struct data*) malloc(sizeof(struct data));
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

void print_student(struct data *student)
{
	printf("%-6d", student->id);
	printf("%-20s", student->name);
	printf("%-20s", student->lastname);
	printf("%-30s", student->addres);
	printf("%-6d", student->status);
	printf("\n");
}


void push(struct node **ptrhead, struct data *data)
{
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	if (tmp == NULL) {
		printf("out of memory!\n");
		return;
	}
	tmp->data_c = data;
	tmp->next = NULL;

	if (*ptrhead != NULL) {
		tmp->next = (*ptrhead);		
	}
	*ptrhead = tmp;

}

struct data* pop(struct node **ptrhead)
{
	if (*ptrhead == NULL) {
		return NULL;
	}
	struct node *tmp = *ptrhead;
	struct data *data = (*ptrhead)->data_c;
	*ptrhead = (*ptrhead)->next;
	free(tmp->data_c);
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
		fprintf(fp, "%d,", head->data_c->id);
		fprintf(fp, "%s,", head->data_c->name);
		fprintf(fp, "%s,", head->data_c->lastname);
		fprintf(fp, "%s,", head->data_c->addres);
		fprintf(fp, "%d", head->data_c->status);		
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
	/* 	fwrite(&(head->data_c->id), sizeof(int), 1, fp); */
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
	/* 	fread(&(data_c->id), sizeof(int), 1, fp); */
	/* 	head = head->next; */
	/* } */
	/* fclose(fp); */
}

void print(struct node *ptrhead)
{
	printf("\n");
	print_student_header();
		
	while (ptrhead != NULL) {
		print_student(ptrhead->data_c);
		ptrhead = ptrhead->next;
	}
	printf("\n");
}



void print_recursive_data(struct node *ptrhead)
{	
	if(ptrhead == NULL)		
		return;
	print_student(ptrhead->data_c);
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
	struct data *student;
	student = create_student(101, "masoud", "bolhassani", "Tallinn Estonia", 1);
	push(ptrhead, student);
	
	struct data *student2;
	student2 = create_student(102, "mai", "volka", "Tallinn Estonia", 1);
	push(ptrhead, student2);

	struct data *student3;
	student3 = create_student(103, "miloo", "volf", "Tallinn Estonia", 1);
	push(ptrhead, student3);
}

void free_list(struct node **ptrhead)
{
	struct node *tmp;
	while (*ptrhead != NULL){
		tmp = *ptrhead;
		*ptrhead = (*ptrhead)->next;
		free(tmp->data_c);
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
	struct data *student;
	
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
