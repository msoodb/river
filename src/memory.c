#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int *ptr;
	int num = 8;
	ptr = (int *)malloc(sizeof(int) * num);
	//ptr = (int *)calloc(num, sizeof(int));
	if (ptr == NULL) {
		printf("%s\n", "out of memory!\n");
		exit(1);
	}
	int new_num = 18;
	ptr = realloc (ptr, 18 * sizeof(int));
	for (int i = 0; i < new_num; ++i) {
		*(ptr+i) = i;
	}
	for (int i = 0; i < num+50; ++i) {
		printf("*(ptr+%d) :  %d \n", i, *(ptr+i));
	}
	//printf("\n");
	free(ptr);
	return 0;
}
