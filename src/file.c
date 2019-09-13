#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fptr = NULL;
  fptr = fopen("list.text", "w");
  if (fptr == NULL) {
    printf("%s\n", "error!");
    exit(1);
  }
  fprintf(fptr, "%s\n", "Hello File!.");
  fclose(fptr);

  printf("%s\n", "---------------------");
  FILE *fp = fopen("list.text", "r");
  if (fp == NULL) {
    printf("%s\n", "error!");
    exit(1);
  }
  char ch;
  while (fscanf(fp, "%c", &ch) != EOF ) {
    printf("%c\n", ch);
  }
  fclose(fp);

  return 0;
}
