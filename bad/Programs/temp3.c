#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
 int u, v, w;
 u = 2; v = -1; w = 10; 
    
 switch (u + v) {
  case 4: 
  case 3: u = v - 1; break;
  case 2: u = u + 1;
  case 1: v = u + 2; break;
  default: w = 0; }

 printf("Line1: %d %d %d\n", u, v, w); 
 
 u = 2; v = -1; w = 10; 
    
 if ((u+v==4) || (u+v==3 )) {u = v - 1;}
 else if ((u+v)==2) {u = u + 1; v = u + 2;}
 else if ((u+v)==1) {v = u + 2;}
 else w = 0;


 printf("Line1: %d %d %d\n", u, v, w);

 system("pause"); 
}

