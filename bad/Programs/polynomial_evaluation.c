#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printTerm(int degree, float coeff) {
     
  switch (degree) {
    case 0: {
      if (coeff>0) printf("+%4.2f", coeff);
      else if (coeff<0) printf("%4.2f", coeff);
      break; 
    } 
    case 1:
    case 2:
    case 3:
    case 4: {
      if (coeff>0) printf("+%4.2fx", coeff);
      else if (coeff<0) printf("%4.2fx", coeff);
      if (degree!=1 && coeff!=0) printf("^%d", degree); 
      break; 
    } 
    case 5: {
      if (coeff!=1) printf("%4.2f", coeff);
      printf("x^5"); 
      break;
    } 
  } 
   
} 

int main(void) {
    
  float a5, a4, a3, a2, a1, a0, x, p;
  float i; 
  
  do {
    printf("Enter coefficient a5: ");
    scanf("%f", &a5);
  } while (a5==0);
  printf("Enter coefficient a4: ");
  scanf("%f", &a4);
  printf("Enter coefficient a3: ");
  scanf("%f", &a3);
  printf("Enter coefficient a2: ");
  scanf("%f", &a2);
  printf("Enter coefficient a1: ");
  scanf("%f", &a1);
  printf("Enter coefficient a0: ");
  scanf("%f", &a0);
  
  printf("\nPolynomial p(x)="); 
  printTerm(5, a5); 
  printTerm(4, a4); 
  printTerm(3, a3); 
  printTerm(2, a2); 
  printTerm(1, a1); 
  printTerm(0, a0);
  printf("\n"); 
         
         
  printf("\nEnter the value of x: ");
  scanf("%f", &x);
         
  p = a5 * pow(x,5) + a4 * pow(x,4) + a3 * pow(x,3) + a2 * pow(x,2) + a1 * x + a0; 
           
  printf("\nThe value of polyomial p(x) is %4.2f.\n\n", p); 

  system("pause");
	return 0;
	}
