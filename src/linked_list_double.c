#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

const int BUFFER_SIZE=1024;
const char *program_name;

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

void print_usage(FILE *stream, int exit_b, int exit_code)
{
	fprintf(stream, "river is an interactive linkedlist terminal.\n");
	fprintf(stream, "\n");		
	fprintf(stream, "Usage : %s options [inputfile ...]\n", program_name);
	fprintf(stream,
		"-i --init                  initalize list.\n"
		"-p --print                 print list.\n"
		"-r --reverse               reverse list.\n"
		"   --pop                   pop first element in list.\n"
		"-s --save      filename    save list.\n"
		"-h --help                  display this help and exit.\n"
		"   --version               output version information and exit.\n");
	fprintf(stream, "\n");
	fprintf(stream, "Report bugs to <river-bug@river.org>.\n");

	if (exit_b) {
		exit (exit_code);	
	}
}

void print_version(FILE *stream, int exit_b, int exit_code)
{
	fprintf(stream, "river (rever linked list) %s\n", "1.0.1");
	if (exit_b) {
		exit (exit_code);	
	}
}

void print_help(FILE *stream)
{
	fprintf(stream, "You are using river, the command-line linkedlist terminal.\n");
	fprintf(stream, "\n");
	fprintf(stream, "  type 'help' display this help.\n");
	fprintf(stream, "  type 'init' for initialize list.\n");
	fprintf(stream, "  type 'print' for print list.\n");
	fprintf(stdout, "  type 'reverse' for reversing list.\n");
	fprintf(stdout, "  type 'pop' for pop first element in list.\n");
	fprintf(stream, "  type 'save DEST' for saving file.\n");
	fprintf(stream, "  type 'q' to quit.\n");
	fprintf(stream, "\n");
}

int main(int argc, char *argv[])
{
	struct node *list = NULL;
	struct element *data;
	
	int next_option;
	const char * const short_options = "ipro:h";
	const struct option long_options[] = {
		{"init",       0, NULL, 'i'},
		{"print",      0, NULL, 'p'},
		{"reverse",    0, NULL, 'r'},
		{"pop",        0, NULL, 'o'},
		{"save",       1, NULL, 's'},
		{"help",       0, NULL, 'h'},
		{"version",    0, NULL, 'v' },
		{NULL,         0, NULL,  0 }
	};

	const char* output_filename = NULL;
	program_name = argv[0];

	do
	{
		next_option = getopt_long(argc, argv, short_options,
					  long_options, NULL);
		switch (next_option) {
		case 'i': {
			init(&list);
			break;
		}
		case 'p': {
			print(list);
			break;
		}
		case 'r': {
			reverse(&list);
			break;
		}
		case 'o': {
			pop(&list);
			break;
		}
		case 's': {
			//output_filename = optarg;
			save(list, "filee.txt");
			break;
		}
		case 'h': {
			print_usage(stdout, 1, 0);			
		}
		case 'v': {			
			print_version(stdout, 1, 0);					
		}
		case '?': {
			print_usage(stderr, 1, 1);			
		}
		case -1: {			
			break;
		}
		default:
			abort();
		}
					
		
	} while (next_option != -1);
	
	printf("river (1.0.1)\n");
	printf("Type \"help\" for help.\n");
	printf("\n");

	printf("\033[1;31m");
	printf("river:& ");
	printf("\033[0m");

	
	char buffer[BUFFER_SIZE];
	fgets(buffer, BUFFER_SIZE, stdin);
	strtok(buffer, "\n");
	
	char delim[] = " ";
	char *arguman[5];
	for (int i = 0; i < 5; ++i) {
		arguman[i] = NULL;
	}
	
	char *ptr = strtok(buffer, delim);
	int i=0;
	while(ptr != NULL)
	{
		arguman[i] = ptr;
		ptr = strtok(NULL, delim);
		i++;
	}
	
	char *cmd = arguman[0];

	while (cmd != "q" && cmd != "Q") {
		if (strcmp(cmd, "init") == 0) {
			init(&list);
		}
		else if (strcmp(cmd, "push") == 0) {
			;
		}
		else if (strcmp(cmd, "pop") == 0) {
			data = pop(&list);
		}
		else if (strcmp(cmd, "reverse") == 0) {
			reverse(&list);
		}  
		else if (strcmp(cmd, "print") == 0) {
			print(list);
		}
		else if (strcmp(cmd, "save") == 0) {
			if(arguman[1] != NULL){				
				char *file = arguman[1];
				save(list, file);
			}
			else{
				printf("save: missing file operand\n");
				printf("type 'help' for more information.\n");
			}
			
		}
		else if (strcmp(cmd, "help") == 0) {
			print_help(stdout);
		}
		else if (strcmp(cmd, "version") == 0) {
			print_version(stdout, 0, 0);
		}
		else if ((strcmp(cmd, "q") == 0) || (strcmp(cmd, "Q") == 0)) {
			break;
		}
		else {
			print_help(stderr);
		}
		
		printf("\033[1;31m");
		printf("river:& ");
		printf("\033[0m");
				
		fgets(cmd, BUFFER_SIZE, stdin);
		strtok(cmd, "\n");

		for (int i = 0; i < 5; ++i) {
			arguman[i] = NULL;
		}
		
		ptr = strtok(buffer, delim);
		i=0;
		while(ptr != NULL)
		{
			arguman[i] = ptr;
			ptr = strtok(NULL, delim);
			i++;
		}		
		cmd = arguman[0];
	}
	
	free_list(&list);
	return 0;
}
