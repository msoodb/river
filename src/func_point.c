#include <stdio.h>
#include <stdlib.h>

int *fu(){
  int *pt=NULL;
  pt = (int *)malloc(sizeof(int));
  if(pt==NULL){
    printf("out of memory!\n");
  }
  return pt;
}

int main(){
  int *ptr;
  ptr = fu();
  *ptr = 13;
  printf("*ptr = %d\n", *ptr);
  free(ptr);
  return 0;
}
