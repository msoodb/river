#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
	char *buffer;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if(buffer == NULL){
		printf("%s\n", "out of memory!");
		exit(1);
	}
	int proc_id = getpid();
	printf("%d\n", proc_id);
	
	buffer = getlogin();
	printf("%s\n", buffer);

	return 0;
}
