#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *fptr = NULL;
  fptr = fopen("numbers.text", "w");
  if(fptr == NULL){
    printf("ERROR!");
    exit(1);
  }
  fprintf(fptr, "hello file! number: %d\n", 42);
  fclose(fptr);
  return 0;
}
