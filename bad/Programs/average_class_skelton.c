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
// Print the table head.
}

void printStudent(student* stu, char** course, int* creditHour) {
// Print a student's record.
}

void printAverage(student* students, int count) {
// Print anc compute average scores.
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
  
// Body of the main program.
}
