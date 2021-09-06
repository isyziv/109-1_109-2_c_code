/* This program reads read the number of students (between 1 and 20) in a class
   and data of these students. The data include student's identification number,
   student's name, and scores of the six courses. Compute the average score of
   each student and the average of each course and the entire class.
   Print the name, identification number, scores six courses, and average
   of each student in a line. Then in the last line print the average of each
   course and the class average. Suppose student's identification number is an
   English letter followed by seven digits, student's name is of three Chinese
   characters, a score is between 0 and 100, and the average is calculated to
   two digits after the decimal points.
*/
#include <stdio.h>

typedef struct {
  char   id[10];
  char   name[20];
  int    score[6];
  float  average;
} student;

int main(void) {

  student stu[20];
  char *course[6] = {"計概    ",
                     "計概實習",
                     "微積分  ",
                     "線代    ",
                     "普物    ",
                     "普物實驗"};
  int creditHour[6] = {3, 1, 4, 3, 3, 1};
  int i, j, count, totalScore, totalCreditHour;
  
  do {
    printf("請輸入學生人數： ");
    scanf("%d", &count);
  } while (count<1 || count>20);
  for (i=0; i<count; i++) {
    printf("\n請輸入學生學號： ");
    scanf("%s", stu[i].id);
    printf("請輸入學生姓名： ");
    scanf("%s", stu[i].name);
    printf("請輸入各科課程分數：\n");
    for (j=0; j<6; j++) {
      printf("%s ", course[j]);
      scanf("%d", &stu[i].score[j]);
    }
  }
  
  printf("\n學號     姓名     ");
  for (i = 0; i < 6; i++) {
    printf("%s ", course[i]);
  }
  printf("平均\n");
  
  for (i=0; i<count; i++) {
    totalScore = 0;
    totalCreditHour = 0;  
    printf("%s %s   ", stu[i].id, stu[i].name);
    for (j= 0; j<6; j++) {
      printf("%3d      ", stu[i].score[j]);
      totalScore += stu[i].score[j] * creditHour[j];
      totalCreditHour += creditHour[j];
    }
    stu[i].average = (float) totalScore / totalCreditHour;  
    printf("%5.2f\n", stu[i].average);
  }
  
  printf("\n         平均     ");
  for (i=0; i<6; i++) {
    totalScore = 0;
    for (j = 0; j < count; j++) {
      totalScore += stu[j].score[i];
    }
    printf("%6.2f   ", (float) totalScore / count);
  }
  totalScore = 0;
  for (j=0; j<count; j++) {
    totalScore += stu[j].average;
  }
  printf("%5.2f\n\n", (float) totalScore / count);
  
  system("pause");
  return 0;
}
