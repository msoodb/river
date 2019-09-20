#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int *ptr;
	int num = 8;
	ptr = (int *)malloc(sizeof(int) * num);
	if (ptr == NULL) {
		printf("%s\n", "out of memory!\n");
		exit(1);
	}
	for (int i = 0; i < num; ++i) {
		*(ptr+i) = i+5;
	}
	for (int i = 0; i < num; ++i) {
		printf("*(ptr+%d) :  %d \n", i, *(ptr+i));
	}
	//printf("\n");
	free(ptr);
	return 0;
}
