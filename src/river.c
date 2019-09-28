#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <wordexp.h>
#include <assert.h>

const int BUFFER_SIZE=1024;
const char *program_name;
const char *version="1.0.1";

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
	fprintf(stream, "river (rever linked list) %s\n", version);
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

char **split_commandline(const char *cmdline, int *argc)
{
	int i;
	char **argv = NULL;
	assert(argc);

	if (!cmdline){
		return NULL;
	}
	wordexp_t p;
	
	// Note! This expands shell variables.	
	if (wordexp(cmdline, &p, 0))
	{
		return NULL;
	}
	
	*argc = p.we_wordc;

	if (!(argv = calloc(*argc, sizeof(char *)))){
		goto fail;
	}

	for (i = 0; i < p.we_wordc; i++){
		if (!(argv[i] = strdup(p.we_wordv[i])))	{
			goto fail;
		}
	}

	wordfree(&p);
	return argv;
fail:
	wordfree(&p);
	
	if (argv){
		for (i = 0; i < *argc; i++){
			if (argv[i]){
				free(argv[i]);
			}
		}		
		free(argv);
	}
	return NULL;
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
			//init(&list);
			break;
		}
		case 'p': {
			//print(list);
			break;
		}
		case 'r': {
			//reverse(&list);
			break;
		}
		case 'o': {
			//pop(&list);
			break;
		}
		case 's': {
			//output_filename = optarg;
			//save(list, "filee.txt");
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

	char *cmd;
	printf("river (1.0.1)\n");
	printf("Type \"help\" for help.\n");
	printf("\n");
	do
	{		
		printf("\033[1;31m");
		printf("river:& ");
		printf("\033[0m");
				
		char buffer[BUFFER_SIZE];
		fgets(buffer, BUFFER_SIZE, stdin);
		strtok(buffer, "\n");

		int *argumanc = (int *)malloc(sizeof(int));	
		char **argumanv = split_commandline(buffer, argumanc);	
		cmd = *(argumanv+0);

		if (strcmp(cmd, "init") == 0) {
			//init(&list);
		}
		else if (strcmp(cmd, "push") == 0) {
			;
		}
		else if (strcmp(cmd, "pop") == 0) {
			//data = pop(&list);
		}
		else if (strcmp(cmd, "reverse") == 0) {
			//reverse(&list);
		}  
		else if (strcmp(cmd, "print") == 0) {
			//print(list);
		}
		else if (strcmp(cmd, "save") == 0) {
			if(*(argumanv+1) != NULL){				
				char *file =*(argumanv+1);
				//save(list, file);
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
	
		
	} while (cmd != "q" && cmd != "Q");

//free_list(&list);*/
	return 0;
}
