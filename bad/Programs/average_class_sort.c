#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char   id[10];
  char   name[20];
  int    score[6];
  float  average;
} student;

int readStudentScore(student *students) {
  FILE *fptr;
  int count = 0, i;
  
  fptr = fopen("student_score.txt", "r");
  while (feof(fptr) == 0) {
    fscanf(fptr, "%s", &students[count].id);
    fscanf(fptr, "%s", &students[count].name);
    for (i = 0; i < 6; i++) {
      fscanf(fptr, "%d", &students[count].score[i]);
    }
    students[count].average = -1;
    count++;
  }
  fclose(fptr);
  return count;
}

void printHead (char **course) {
  int i;

  printf("\n學號     姓名     ");
  for (i = 0; i < 6; i++) {
    printf("%s ", course[i]);
  }
  printf(" 平均\n\n");
}

void printStudent(student *stu, char **course, int *creditHour) {
  int i, totalScore = 0, totalCreditHour = 0;
  
  printf("%s ", stu->id);
  printf("%s", stu->name);
  if (strlen(stu->name) == 4) printf("     ");
  else if (strlen(stu->name) == 6) printf("   ");
  else if (strlen(stu->name) == 8) printf(" ");
  for (i = 0; i < 6; i++) printf("%3d      ", stu->score[i]);  
  if (stu->average<0) {
    for (i = 0; i < 6; i++) {      
      totalScore += stu->score[i] * creditHour[i];
      totalCreditHour += creditHour[i];
    }
    stu->average = (float) totalScore / totalCreditHour;
  }
  
  printf(" %5.2f\n", stu->average); 
}

void printAverage(student *students, int count) {
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

void copyStudent(student *stu1, student *stu2) {
  int i;
  
  strcpy(stu1->id, stu2->id);
  strcpy(stu1->name, stu2->name);
  for (i = 0; i < 6; i++) stu1->score[i] = stu2->score[i];
  stu1->average = stu2->average;
}

void cs(student *stu1, student *stu2, int key, int *creditHour) {
  student temp;
  int swap = 0, i;
  int totalScore, totalCreditHour;
  
  if (key == 0) {
    if (strcmp(stu1->id, stu2->id) > 0) swap = 1; 
  }
  else if (key > 0 && key < 7) {
    if (stu1->score[key - 1] > stu2->score[key - 1]) swap = 1;
  }
  else {
    if (stu1->average<0) {
      totalScore = 0;
      totalCreditHour = 0;
      for (i = 0; i < 6; i++) {
        totalScore += stu1->score[i] * creditHour[i];
        totalCreditHour += creditHour[i]; }
      stu1->average = (float) totalScore / totalCreditHour;
    }
    if (stu2->average<0) {
      totalScore = 0;
      totalCreditHour = 0;
      for (i = 0; i < 6; i++) {
        totalScore += stu2->score[i] * creditHour[i];
        totalCreditHour += creditHour[i]; }
      stu2->average = (float) totalScore / totalCreditHour;
    }
    if (stu1->average > stu2->average) swap = 1;
  }
  
  if (swap) {
    copyStudent(&temp, stu1);
    copyStudent(stu1, stu2);
    copyStudent(stu2, &temp);
  }
}

void sortStudents(student *stu, int cnt, int key, int *creditHour) {
  int i, j;
  
  for (i = cnt; i > 0; i--) 
    for (j = 1; j < i; j++) cs(&stu[j-1], &stu[j], key, creditHour);
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
  int totalStudent, i, key;
  
  totalStudent = readStudentScore(students);
  
  do {
    printf("\n    0: 學號\n"); 
    for (i = 1; i <= 6; i++) printf("    %d: %s\n", i, course[i - 1]);
    printf("    7: 平均\n\n");
    printf("Enter a sorting key (0 to 7): "); 
    scanf("%d", &key);
  } while (key < 0 || key > 7);
  
  sortStudents(students, totalStudent, key, creditHour);
  
  printHead(course);
  for (i = 0; i < totalStudent; i++) {
    printStudent(&students[i], course, creditHour);
  }
  printAverage(students, totalStudent);
  
  system("pause");
  return 0;
}
