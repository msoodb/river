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

struct data* createStudent(int id, char *name, char *lastname, char *addres, int status)
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

void printStudentHeader()
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

void printStudent(struct data *student)
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

void pop(struct node **ptrhead, struct data *data)
{
	if (*ptrhead == NULL) {
		data = NULL;
		return;
	}
	data = (*ptrhead)->data_c;
	*ptrhead = (*ptrhead)->next;	
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

void print(struct node *ptrhead)
{
	printf("\n");
	printStudentHeader();
		
	while (ptrhead != NULL) {
		printStudent(ptrhead->data_c);
		ptrhead = ptrhead->next;
	}
}

int main(int argc, char *argv[])
{
	struct node *students = NULL;

	/* create data */
	struct data *student;
	student = createStudent(101, "masoud", "bolhassani", "Tallinn Estonia", 1);
	push(&students, student);
	struct data *student2;
	student2 = createStudent(102, "mai", "volka", "Tallinn Estonia", 1);
	push(&students, student2);
	struct data *student3;
	student3 = createStudent(103, "miloo", "volf", "Tallinn Estonia", 1);
	push(&students, student3);
	//serialize(students, "students.txt");
	print(students);
	struct data *student4;
	pop(&students, student4);	
	print(students);
	return 0;
}
