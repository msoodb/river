#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	n = 13;
	for (int i = 0; i < n; ++i) {
		int k=0;
		while (k < n) {
			printf("* ");
			k++;
		}
		printf("\n");
	}

	return 0;
}
