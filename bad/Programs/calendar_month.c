/* This program read a month, a day, and a weekday, and then,
   outputs a monthly calendar of that month.
   Weekdays are denoted as:
     0: Sunday    1: Monday  2: Tuesday   3: Wednesday
     4: Thursday  5: Friday  6: Saturday
   The program will check validity of day of the month being input.
   Assume non-leap years, i.e., February is of 28 days. 
   Repeat the process until the input month is zero.
*/

#include <stdio.h>

int main(void) {
  int mm, dd, ww;
  int count, i;
  char name_of_month[12][10] = {"January", "February", "March",     "April",   "May",      "June",
                                "July",    "August",   "September", "October", "November", "December"};
  int days_of_month[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  // Enter a month.
  do {
    printf(">>>> Enter a month (0 to quit): ");
    scanf("%d", &mm);
    if (mm==0) return 0;
    else if (mm>=1 && mm<=12) {
      // Enter a day.
      printf("\n>>>> Enter a day (between 1 and %d): ", days_of_month[mm-1]);
      scanf("%d", &dd);
      if (dd>=1 && dd<=days_of_month[mm-1]) {
        // Enter a weekday.
        printf("\n0: Sunday    1: Monday  2: Tuesday  3: Wednesday\n");
        printf("4: Thursday  5: Friday  6: Saturday\n");
        printf(">>>> Enter a weekday (between 0 and 6): ");
        scanf("%d", &ww);
        if (ww>=0 && ww<=6) {
          ww = (ww - dd + 1) % 7;
          if (ww<0) ww = ww + 7;
          dd = 1;
          printf("\n    %s\n", name_of_month[mm-1]);
          printf("    Sun Mon Tue Wed Thu Fri Sat\n");
          printf("    ");
          count = days_of_month[mm-1]; // Get number of days in the month.
          
          for (i=0; i<ww; i++) printf("    "); // Move the cursor to the weekday of day one.
          while (count>0) {
            printf(" %2d ", dd); // Print the day. Each day taks four characters (including two spaces).
      dd++;
      ww= (ww + 1) % 7; 
      if (ww==0) printf("\n    "); // Starting from Sunday, again, output a newline.
      count--;
    }
    if (ww!=0) printf("\n"); // If the next day is not Sunday, output a newline.
          
        }
        else {
          printf("****Error: %d is not a valid weekday.\n", ww);
        }
      }
      else {   
        printf("****Error: %d is not a valid day for the month of %s.\n", dd, name_of_month[mm-1]);
      }
    }
    else {
      printf("****Error: %d is not a valid month.\n", mm);
    }
    printf("\n---------------------------------------------------------------\n\n");
  } while (1);
}
