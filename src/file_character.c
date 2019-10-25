#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char ch;

  //write to file 
  FILE *fp = fopen("file_character.text", "a");
  if (fp == NULL) {
    printf("error opening file\n");
    exit(1);
  }
  while ((ch = getchar()) != EOF) {
    fputc(ch, fp);
    //printf("%c", ch);
  }
  fclose(fp);
  
  //read from file
  printf("--------------------------------------\n");
  FILE *fpr = fopen("file_character.text", "r");
  if (fpr == NULL) {
    printf("error readin file\n");
    exit(1);
  }
    
  char chr;
  while ((chr = fgetc(fpr)) != EOF) {
    printf("%c", chr);
  }
  fclose(fpr);
  return 0;
}
