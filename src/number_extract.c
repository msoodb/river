#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	char *s;
	s = (char *) malloc(sizeof(char) * 1024);
	scanf("%s", s);
	int l = strlen(s);
	s = realloc(s, l*sizeof(char));
	int *arr = (int *)calloc(10, sizeof(int));
	char ch;
	for(int i=0; i<l; i++){
		ch = *(s+i);
		if(isdigit(ch)){
			//printf("%d\n", ch);
			(*(arr+ch-48))++;
		}
	}
	for(int j=0; j<10; j++){
		printf("%d ", *(arr+j));
	}
	return 0;
}
