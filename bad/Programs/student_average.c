/* This program reads in a student's name, id, and scores of six courses.
   It then computes and prints the scores and average of the student.
*/
#include <stdio.h>

typedef struct {
  char   id[10];
  char   first_name[20];
  char   last_name[20];
  int    score[6];
  float  average;
} student;

int main(void) {

  student stu;
  char *course[6] = {"C Programming for Engineering    ",
                     "Analytical Genometry and Calculus",
                     "Mechanics                        ",
                     "Mechanics Laboratory             ",
                     "General Chemistry                ",
                     "General Chemistry Laboratory     "};
  int creditHour[6] = {3, 3, 3, 1, 3, 1};
  int i, totalScore, totalCreditHour;
  
  printf("Enter Student ID: ");
  scanf("%s", stu.id);
  printf("Enter Student Name (frist_name last_name): ");
  scanf("%s %s", stu.first_name, stu.last_name);
  printf("Enter Scores for all Course\n");
  for (i = 0; i < 6; i++) {
    printf("%s ", course[i]);
    scanf("%d", &stu.score[i]);
  }
  
  printf("\nStudent Id: %s     Student Name: %s %s\n", stu.id, stu.first_name, stu.last_name);
  totalScore = 0;
  totalCreditHour = 0;
  
  printf("Course Name                        Score\n");
  for (i = 0; i < 6; i++) {
    printf("%s: %d\n", course[i], stu.score[i]);
    totalScore += stu.score[i] * creditHour[i];
    totalCreditHour += creditHour[i];
  }
  stu.average = (float) totalScore / totalCreditHour;
  
  printf("Average:                           %5.2f\n", stu.average); 
  
  return 0;
}
