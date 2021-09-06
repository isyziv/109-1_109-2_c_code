#include <stdio.h>
#include <string.h>

typedef struct {
  char   id[10];
  char   name[20];
  int    score[6];
  float  average;
} student;

int readStudentScore(student* students) {
  FILE* fptr;
  int count = 0, i;
  
  fptr = fopen("student_score.txt", "r");
  while (feof(fptr) == 0) {
    fscanf(fptr, "%s", &students[count].id);
    fscanf(fptr, "%s", &students[count].name);
    for (i = 0; i < 6; i++) {
      fscanf(fptr, "%d", &students[count].score[i]);
    }
    count++;
  }
  fclose(fptr);
  return (count);
}

void printHead (char** course) {
  int i;

  printf("\n學號     姓名     ");
  for (i = 0; i < 6; i++) {
    printf("%s ", course[i]);
  }
  printf(" 平均\n");
  printf("------------------------------------------------------------------------------\n");
}

void printStudent(student* stu, int* creditHour) {
  int i, totalScore = 0, totalCreditHour = 0;
  
  printf("%s ", stu->id);
  printf("%s", stu->name);
  if (strlen(stu->name) == 4) printf("     ");
  else if (strlen(stu->name) == 6) printf("   ");
  else if (strlen(stu->name) == 8) printf(" ");
  for (i = 0; i < 6; i++) {
    printf("%3d      ", stu->score[i]);  
    totalScore += stu->score[i] * creditHour[i];
    totalCreditHour += creditHour[i];
  }
  stu->average = (float) totalScore / totalCreditHour;
  
  printf(" %5.2f\n", stu->average); 

}

void printAverage(student* students, int count) {
  int totalScore, i, j;
  float totalAverage;

  printf("\n         平均      ");
  for (i = 0; i < 6; i++) {
    totalScore = 0;
    for (j = 0; j < count; j++) {
      totalScore += students[j].score[i];
    }
    printf("%5.2f    ", (float) totalScore / count);
  }
  totalAverage = 0;
  for (j = 0; j < count; j++) {
    totalAverage += students[j].average;
  }
  printf("%5.2f\n\n", (float) totalAverage / count);
}

int main(void) {

  student students[20];
  char *course[6] = {"計概    ",
                     "計概實習",
                     "微積分  ",
                     "線代    ",
                     "普物    ",
                     "普物實驗"};
  int creditHour[6] = {3, 1, 4, 3, 3, 1};
  int totalStudent, i;
  
  totalStudent = readStudentScore(students);
  
  printHead(course);
  for (i = 0; i < totalStudent; i++) {
    printStudent(&students[i], creditHour);
  }
  printAverage(students, totalStudent);
  
  system("pause");  
  exit(1);
}
