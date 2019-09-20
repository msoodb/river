#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	n = 13;
	for (int i=0; i<n; ++i) {
		int k=0;
		for (int j = n; j>i ; --j) {
			printf(" ");
		}

		while (k <= i) {
			printf("* ");
			k++;
		}
		printf("\n");
	}
	for (int i=n; i>0; --i) {
		int k=0;
		for (int j = n; j>i ; --j) {
			printf(" ");
		}

		while (k <= i) {
			printf("* ");
			k++;
		}
		printf("\n");
	}

	return 0;
}
