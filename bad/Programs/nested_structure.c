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
  
  printf("�п�J�ǥͪ��m�G ");
  scanf("%s", stu.name.last);
  printf("�п�J�ǥͪ��W�G ");
  scanf("%s", stu.name.first);
  
  printf("�ǥͩm�W: %s%s\n", stu.name.last, stu.name.first);
  
  system("pause");
  return 0; 
}
