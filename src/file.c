#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *fptr = NULL;
  fptr = fopen("numbers.text", "w");
  if(fptr == NULL){
    printf("ERROR!");
    exit(1);
  }
  fprintf(fptr, "hello\n");
  fclose(fptr);

  //------------------------------------------

  FILE *fptrRead = NULL;
  fptrRead = fopen("numbers.text", "r");
  if(fptrRead==NULL){
    printf("error! file does not exist.\n");
    exit(1);
  }
  char c;
  //while((c=fgetc(fptrRead)) != EOF){
  //printf("%c\n", c);  
  //}
  fscanf(fptrRead, "%c", &c);
  printf("%c\n", c);
  return 0;
}
