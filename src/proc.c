#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int proc_id = getpid();
	int parent_proc_id = getppid();
	printf("%d\n", proc_id);
	printf("%d\n", parent_proc_id);
	return 0;
}
