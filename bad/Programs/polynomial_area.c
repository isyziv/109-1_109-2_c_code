#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void printTerm(int degree, int i, float c) {
     
  if (degree==i) {
    if (c<0) printf("-");
    if (c!=1) printf("%4.3f ", fabs(c));
  }
  else {
    if (c>0) printf(" + %6.4f ", fabs(c)); 
    else if (c<0) printf(" - %6.4f ", fabs(c)); 
    }
  if (i>0 && c!=0) {
    printf("X");
    if (i>1) printf("^%d", i);
  }
}

int main(void) {
  short n, j;
  long T, i;
  const float epsilon = 0.000001;
  float a, b;
  float coeff[100];
  double area, last, interval, poly, point;
  
  srand(time(NULL));
  
  do {
    printf("Enter the degree of polynomial P(x): ");
    scanf("%d", &n);
    printf("\n");
  } while (n<0 || n>10);
  
  do {
    printf("Enter two real numbers a and b such that 0<b-a<=5: ");
    scanf("%f %f", &a, &b);
    printf("\n");
  } while (a>=b || b-a>5);
  
  for (i=n; i>=0; i--) {
    coeff[i] = (rand() % 2000 - 1000) / 1000.0;
  }
    
  printf("Polynomial P(x):\n");
  for (i=n; i>=0; i--) printTerm(n, i, coeff[i]);
  printf("\n\n");
  
  printf("Interval [a, b]: [%6.4f, %6.4f]\n\n", a, b);
  
  T=1;
  area = -1;
  last = -2;  
  while (fabs(area-last)>epsilon) {
    interval = (b - a) / T;
    point = a + interval / 2;
    last = area;
    area = 0;
    for (i=0; i<T; i++) {
      poly = 0;
      for (j=0; j<=n; j++) poly += coeff[j] * pow(point, j);
      area += fabs(poly) * interval;
      point += interval;
    }
    printf("Number of intervals: %d, interval size: %8.6f, area: %8.6f\n", T, interval, area);
    T = T * 2;
  }
  
  printf("\nThe number of intervals: %d\n\n", T/2);
  printf("Area of polynomial P(x) between (%6.4f, 0.0) and (%6.4f, 0.0): %8.6f\n\n", a, b, area);

  system("pause");
  return 0;
}
