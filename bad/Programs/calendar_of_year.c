/* The program performs the following operations:
    a. Enter a year between 1901 and 2050.
    b. Print calendar of that year.
   The reference date is Tuesday, January 1, 2013.
*/

#include <stdio.h>

int main(void) {
  const int yy = 2015, mm = 1, dd = 1, ww = 4; // Reference day
  const char *name_of_month[12] = {"January", "February", "March",     "April",   "May",      "June",
                                   "July",    "August",   "September", "October", "November", "December"};
  const int days_of_month[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  int year, month, day, weekday;
  int count, i;
  
  // Enter a year between 1901 and 2050.
  do {
    printf(">>>>Enter the year of calendar: ");
    scanf("%d", &year);
  } while (year<1901 || year>2050);
  
  // Calculate the number of days from January 1 of 2015 to January 1 of the selected year.
  count = 0;
  if (year<=yy) { // The year of 2015 or before 2015.
    for (i = year; i < yy; i++)
      if (i%4!=0) count = count - 365;
      else count = count - 366;
  }
  else { // The year after 2015.
    for (i = year; i > yy; i--)
      if ((i-1)%4!=0) count = count + 365;
      else count = count + 366;
  }  
  
  month = 1;
  weekday = (ww + count) % 7; // Compute the day of week of January 1 of the entered year.
  if (weekday<0) weekday +=7;
    
  printf("\nCalendar of the Year of %d\n\n", year);
  while (month<=12) {
    printf("    %s\n", name_of_month[month-1]);
    printf("    Sun Mon Tue Wed Thu Fri Sat\n");
    printf("    ");
    count = days_of_month[month-1]; // Get number of days in the month.
    if (month==2 && year%4==0) count = 29; // If it is February of a leap year, the month has 29 days.
    day = 1;
    for (i=0; i<weekday; i++) printf("    "); // Move the cursor to the weekday of day one.
    while (count>0) {
      printf(" %2d ", day); // Print the day. Each day takes four characters (including two spaces).
      day++;
      weekday = (weekday + 1) % 7; 
      if (weekday==0) printf("\n    "); // Starts from Sunday. Output a output a newline.
      count--;
    }
    if (weekday!=0) printf("\n"); // If the last day is not saturday, Output a newline.
    printf("\n");
    month++;
  }
  
  system("pause");
  return 0; 
}
