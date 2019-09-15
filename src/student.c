#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int id;
  char *name;
  char *lastname;  
}student;

student * initStudent(){
  student *st = NULL;
  st = (student *)malloc(sizeof(student));
  if (st == NULL) {
    return NULL;
  }
  st->name = (char *)malloc(sizeof(char) * 20);
  st->lastname = (char *)malloc(sizeof(char) * 30);
  return st;
}

int main(int argc, char *argv[])
{
  // Read student.csv  file
  FILE *fp = fopen("student.csv", "r");
  if (fp == NULL){
   printf("%s\n", "File does not exist");
   exit(1);
   }
  char ch;
  while ((ch = fgetc(fp)) != EOF){
    //printf("%c", ch);
  }
  fclose(fp);

  //add student to student.text
  FILE *fpStudent = fopen("student.text", "w");
  if (fpStudent == NULL) {
    printf("out of memory\n");
    exit(1);
  }
  student *new = initStudent();
  if (new == NULL) {
    printf("out of memory\n");    
    exit(1);
  }
  new->id = 1;
  strcpy(new->name, "masoud");
  strcpy(new->lastname, "bolhassani");
  fprintf(fpStudent, "%d", new->id);
  fprintf(fpStudent, "%c", ',');
  fprintf(fpStudent, "%s", new->name);
  fprintf(fpStudent, "%c", ',');
  fprintf(fpStudent, "%s", new->lastname);
  fprintf(fpStudent, "\n");  
  fclose(fpStudent);
  return 0;
}
