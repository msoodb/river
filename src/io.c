#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{  
  // case 0 
 
  int a;
  int result;
  printf("enter a number: " );
  while ((result = scanf("%d", &a)) == 0){
    scanf("%*[^\n]");
    printf("enter a number: ");
  }    
  if (result == EOF) {
    printf("Nothing more to read - and no number found\n");    
  }else {
    printf("you enterd: %d\n", a);
  }
  
  printf("enter another number: " );
  while ((result = scanf("%d", &a)) == 0){
    scanf("%*[^\n]");
    printf("enter another number: ");
  }    
  if (result == EOF) {
    printf("Nothing more to read - and no number found\n");    
  }else {
    printf("you enterd: %d\n", a);
  }
    
  //case 1
  char name[40];
  printf("What's your name? ");
  if(scanf("%*[^\n]%39[^\n]s", name)){    
    printf("you name is: %s\n", name);
  } 
  
  return 0;
}
