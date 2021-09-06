/* 1. Read the values of three integer variables a1, a2, and a3.
   2. Sort a1, a2, and a3 in ascending order. 
      (Use if-then and if-then-else conditional statements.)
   3. Print the sorted sequence of  a1, a2, and a3.
   4. If the value of variable a1 is negative, then set a1 to its absolute value.
      If the value of variable a2 is negative, then set a2 to be its square.
      If the value of a3 is negative, then set it to a3+100.
      (Use ternary operations)
   5. Print the new values of a1, a2, and a3  
   6. Sort a1, a2, and a3 in descending order.
      (Use if-then and if-then-else conditional statements.)
   7. Print the sorted sequence of a1, a2, and a3
*/

#include <stdio.h>

int main(void) {
  
  int a1, a2, a3;
  int temp1, temp2;
  
  printf("Enter the values of a1, a2, and a3: ");
  scanf("%d %d %d", &a1, &a2, &a3);
  
  if (a1>=a2 && a2>=a3) {temp1 = a3; temp2 = a2; a3 = a1; a2 = temp2; a1= temp1;}
  else if (a1>=a3 && a3>=a2) {temp1 = a2; temp2 = a3; a3 = a1; a2 = temp2; a1= temp1;}
  else if (a2>=a1 && a1>=a3) {temp1 = a3; temp2 = a1; a3 = a2; a2 = temp2; a1= temp1;}
  else if (a2>=a3 && a3>=a1) {temp1 = a1; temp2 = a3; a3 = a2; a2 = temp2; a1= temp1;}
  else if (a3>=a1 && a1>=a2) {temp1 = a2; temp2 = a1; a3 = a3; a2 = temp2; a1= temp1;}
  
  printf("\nPrint the sorted sequence of a1, a2, and a3 in ascending order: ");
  printf("%d, %d, %d\n\n", a1, a2, a3);
  
  printf("If a1<0, set a1 to its absolute value.\n");
  printf("If a2<0, set a2 to its square.\n");
  printf("If a3<0, set a3 to a3+100.\n");
  a1 = a1<0 ? -a1 : a1;
  a2 = a2<0 ? a2 * a2 : a2;
  a3 = a3< 0 ? a3 + 100 : a3;
  printf("\nPrint the new values of a1, a2, and a3: ");
  printf("%d, %d, %d\n", a1, a2, a3);
  
  if (a1<=a2 && a2<=a3) {temp1 = a3; temp2 = a2; a3 = a1; a2 = temp2; a1= temp1;}
  else if (a1<=a3 && a3<=a2) {temp1 = a2; temp2 = a3; a3 = a1; a2 = temp2; a1= temp1;}
  else if (a2<=a1 && a1<=a3) {temp1 = a3; temp2 = a1; a3 = a2; a2 = temp2; a1= temp1;}
  else if (a2<=a3 && a3<=a1) {temp1 = a1; temp2 = a3; a3 = a2; a2 = temp2; a1= temp1;}
  else if (a3<=a1 && a1<=a2) {temp1 = a2; temp2 = a1; a3 = a3; a2 = temp2; a1= temp1;}
  
  printf("\nPrint the sorted sequence of a1, a2, and a3 in descending order: ");
  printf("%d, %d, %d\n\n", a1, a2, a3);
  
  system("pause");
  return 0; 
}
