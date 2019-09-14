#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fp = fopen("student.csv", "r");
  if (fp == NULL){
    printf("%s\n", "File does not exist");
    exit(1);
  }
  return 0;
}
