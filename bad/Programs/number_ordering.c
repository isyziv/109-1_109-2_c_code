#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a, b, c, d, cmd;
  
  //  read four integer values of variables a, b, c, and d 
  printf("Enter the value of a: ");
  scanf("%d", &a);
  printf("Enter the value of b: ");
  scanf("%d", &b);
  printf("Enter the value of c: ");
  scanf("%d", &c);
  printf("Enter the value of d: ");
  scanf("%d", &d);
  
  /* Read a command cmd of integer value between 1 and 6 (included).
     If cmd is 1 then output the largest value of a, b, c, and d;
     if cmd is 2 then output the second largest value of a, b, c, and d;
     if cmd is 3 then output the second smallest value of a, b, c, and d;
     if cmd is 4 then output the smallest value of a, b, c, and d;
     if cmd is 5 then output the values of a, b, c, and d in the ascending order;
     if cmd is 6 then output the values of a, b, c, and d in the descending order. 
  */ 
  do {
    printf("\n"); 
    printf("Command 1: output the largest value of a, b, c, and d\n");
    printf("Command 2: output the second largest value of a, b, c, and d\n");
    printf("Command 3: output the second smallest value of a, b, c, and d\n");
    printf("Command 4: output the smallest value of a, b, c, and d\n");
    printf("Command 5: output the values of a, b, c, and d in the ascending order\n");
    printf("Command 6: the values of a, b, c, and d in the descending order\n");
    printf("\n");
    printf("Enter command (1 to 6): ");
    scanf("%d", &cmd);
  } while (cmd<1 || cmd>6);
  
  switch (cmd) {
    case 1: {
      if (a>=b && a>=c && a>=d) printf("\nThe largest value of a, b, c, and d: %d\n\n", a);
      else if (b>=a && b>=c && b>=d) printf("\nThe largest value of a, b, c, and d: %d\n\n", b);
      else if (c>=a && c>=b && c>=d) printf("\nThe largest value of a, b, c, and d: %d\n\n", c);
      else if (d>=a && d>=a && d>=c) printf("\nThe largest value of a, b, c, and d: %d\n\n", c); 
      break; 
    } 
    case 2: {
      if ((a<=b || a<=c || a<=d) &&
          ((a>=c && a>=d) || (a>=b && a>=d) || (a>=b && a>=c))) 
         printf("\nThe second largest value of a, b, c, and d: %d\n\n", a);
      else if ((b<=a || b<=c || b<=d) &&
          ((b>=c && b>=d) || (b>=a && b>=d) || (b>=a && b>=c))) 
         printf("\nThe second largest value of a, b, c, and d: %d\n\n", b);
      else if ((c<=a || c<=b || c<=d) &&
          ((c>=b && c>=d) || (c>=a && c>=d) || (c>=a && c>=b))) 
         printf("\nThe second largest value of a, b, c, and d: %d\n\n", c);
      else if ((d<=a || d<=b || d<=c) &&
          ((d>=b && d>=c) || (d>=a && d>=c) || (d>=a && d>=b))) 
         printf("\nThe second largest value of a, b, c, and d: %d\n\n", d); 
      break; 
    }  
    case 3: {
      if ((a>=b || a>=c || a>=d) &&
          ((a<=c && a<=d) || (a<=b && a<=d) || (a<=b && a<=c))) 
         printf("\nThe second smallest value of a, b, c, and d: %d\n\n", a);
      else if ((b>=a || b>=c || b>=d) &&
          ((b<=c && b>=d) || (b<=a && b>=d) || (b<=a && b<=c))) 
         printf("\nThe second smallest value of a, b, c, and d: %d\n\n", b);
      else if ((c>=a || c>=b || c>=d) &&
          ((c<=b && c<=d) || (c<=a && c<=d) || (c<=a && c<=b))) 
         printf("\nThe second smallest value of a, b, c, and d: %d\n\n", c);
      else if ((d>=a || d>=b || d>=c) &&
          ((d<=b && d<=c) || (d<=a && d<=c) || (d<=a && d<=b))) 
         printf("\nThe second smallest value of a, b, c, and d: %d\n\n", d); 
      break; 
    } 
    case 4: {
      if (a<=b && a<=c && a<=d) printf("\nThe smallest value of a, b, c, and d: %d\n\n", a);
      else if (b<=a && b<=c && b<=d) printf("\nThe smallest value of a, b, c, and d: %d\n\n", b);
      else if (c<=a && c<=b && c<=d) printf("\nThe smallest value of a, b, c, and d: %d\n\n", c);
      else if (d<=a && d<=a && d<=c) printf("\nThe smallest value of a, b, c, and d: %d\n\n", c); 
      break; 
    }  
    case 5: {
      if (a<=b && b<=c && c<=d) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", a, b, c, d);
      else if (a<=b && b<=d && d<=c) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", a, b, d, c);
      else if (a<=c && c<=b && b<=c) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", a, c, b, d);      
      else if (a<=c && c<=d && d<=b) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", a, c, d, b);      
      else if (a<=d && d<=b && b<=c) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", a, d, b, c);      
      else if (a<=d && d<=c && c<=b) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", a, d, c, b);      
      else if (b<=a && a<=c && c<=d) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", b, a, c, d);      
      else if (b<=a && a<=d && d<=c) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", b, a, d, c);      
      else if (b<=c && c<=a && a<=d) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", b, c, a, d);      
      else if (b<=c && c<=d && d<=a) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", b, c, d, a);      
      else if (b<=d && d<=a && a<=c) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", b, d, a, c);      
      else if (b<=d && d<=c && c<=a) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", b, d, c, a);      
      else if (c<=a && a<=b && b<=d) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", c, a, b, d);      
      else if (c<=a && a<=d && d<=b) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", c, a, d, b);      
      else if (c<=b && b<=a && a<=d) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", c, b, a, d);      
      else if (c<=b && b<=d && d<=a) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", c, b, d, a);      
      else if (c<=d && d<=a && a<=b) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", c, d, a, b);      
      else if (c<=d && d<=b && b<=a) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", c, d, b, a);      
      else if (d<=a && a<=b && b<=c) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", d, a, b, c);      
      else if (d<=a && a<=c && c<=b) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", d, a, c, b);      
      else if (d<=b && b<=a && a<=c) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", d, b, a, c);      
      else if (d<=b && b<=c && c<=a) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", d, b, c, a);      
      else if (d<=c && c<=a && a<=b) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", d, c, a, b);      
      else if (d<=c && c<=b && b<=a) printf("\nThe values of a, b, c, and d in the ascending order: %d, %d, %d, %d\n\n", d, c, b, a);
      break;
    }  
    case 6: {
      if (a>=b && b>=c && c>=d) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", a, b, c, d);
      else if (a>=b && b>=d && d>=c) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", a, b, d, c);
      else if (a>=c && c>=b && b>=c) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", a, c, b, d);      
      else if (a>=c && c>=d && d>=b) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", a, c, d, b);      
      else if (a>=d && d>=b && b>=c) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", a, d, b, c);      
      else if (a>=d && d>=c && c>=b) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", a, d, c, b);      
      else if (b>=a && a>=c && c>=d) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", b, a, c, d);      
      else if (b>=a && a>=d && d>=c) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", b, a, d, c);      
      else if (b>=c && c>=a && a>=d) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", b, c, a, d);      
      else if (b>=c && c>=d && d>=a) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", b, c, d, a);      
      else if (b>=d && d>=a && a>=c) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", b, d, a, c);      
      else if (b>=d && d>=c && c>=a) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", b, d, c, a);      
      else if (c>=a && a>=b && b>=d) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", c, a, b, d);      
      else if (c>=a && a>=d && d>=b) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", c, a, d, b);      
      else if (c>=b && b>=a && a>=d) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", c, b, a, d);      
      else if (c>=b && b>=d && d>=a) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", c, b, d, a);      
      else if (c>=d && d>=a && a>=b) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", c, d, a, b);      
      else if (c>=d && d>=b && b>=a) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", c, d, b, a);      
      else if (d>=a && a>=b && b>=c) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", d, a, b, c);      
      else if (d>=a && a>=c && c>=b) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", d, a, c, b);      
      else if (d>=b && b>=a && a>=c) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", d, b, a, c);      
      else if (d>=b && b>=c && c>=a) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", d, b, c, a);      
      else if (d>=c && c>=a && a>=b) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", d, c, a, b);      
      else if (d>=c && c>=b && b>=a) printf("\nThe values of a, b, c, and d in the descending order: %d, %d, %d, %d\n\n", d, c, b, a);
      break;
    }  
  } 

  system("pause");
	return 0;
}
