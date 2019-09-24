#include <stdio.h>
#include <stdlib.h>

struct data
{
	int id;
	char *name;
	char *lastname;
	char *addres;
	int status;
};

struct data* create_student(int id, char *name, char *lastname, char *addres, int status)
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
	printf("---------------------------------------------------------------------------------------");
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

struct node
{
	struct data *data_c;
	struct node *next;
	
};

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
	struct data *data = (*ptrhead)->data_c;
	*ptrhead = (*ptrhead)->next;
	return data;
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
	FILE *fp = fopen(file, "w");
	if (fp == NULL) {
		printf("error file : %s\n", file);
		return;
	}
	
	while (head != NULL) {
		fwrite(head, sizeof(struct node), 1, fp);
		head = head->next;
	}
	fclose(fp);
}

void print(struct node *ptrhead)
{
	printf("\n");
	print_student_header();
		
	while (ptrhead != NULL) {
		print_student(ptrhead->data_c);
		ptrhead = ptrhead->next;
	}
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

int main(int argc, char *argv[])
{
	struct node *students = NULL;
	init(&students);
	
	print(students);
	serialize_binary(students, "students.dat");
	
	struct data *student4 = pop(&students);	

	print(students);

	return 0;
}
