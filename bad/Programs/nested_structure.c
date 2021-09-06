/* This program illustrate a nested structure student. Field name is
   divided into two subfields: last and first which is represented as
   another structure.
*/
#include <stdio.h>

typedef struct {
  char  id[10];
  struct {
    char last[5];
    char first[5];
  } name;
  int   score[6];
  float average;
} student;

int main(void) {

  student stu;
  
  printf("請輸入學生的姓： ");
  scanf("%s", stu.name.last);
  printf("請輸入學生的名： ");
  scanf("%s", stu.name.first);
  
  printf("學生姓名: %s%s\n", stu.name.last, stu.name.first);
  
  system("pause");
  return 0; 
}
