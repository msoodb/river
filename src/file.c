#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp = fopen("file.text", "w");
  if (fp == NULL) {
    printf("%s\n", "error open file!");
    exit(1);
  }
  fprintf(fp, "%s", "Hello File!.\n");
  fclose(fp);
  
  fp = fopen("file.text", "r");
  if (fp == NULL) {
    printf("%s\n", "error open file!");
    exit(1);
  }
  char ch;
  while (fscanf(fp, "%c", &ch) != EOF) {
    printf("%c.", ch);    
  }
  printf("\n");
  fclose(fp);
  return 0;
}
