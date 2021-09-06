/* This program illustrate the size of structure student and shows how
   field elements are allocated in memory.
*/
#include <stdio.h>

typedef struct {
  char  id[10];
  char  name[20];
  int   score[6];
  float average;
} student;

int main(void) {

  student stu;
  
  printf("Size of student: %d\n", sizeof(student));
  printf("Address of stu: 0X%X\n", &stu);
  printf("Address of stu.id: 0X%X\n", &stu.id);
  printf("Address of stu.name: 0X%X\n", &stu.name);
  printf("Address of stu.score[0]: 0X%X\n", &stu.score[0]);
  printf("Address of stu.average: 0X%X\n", &stu.average);
  
  system("pause");
  return 0; 
}
