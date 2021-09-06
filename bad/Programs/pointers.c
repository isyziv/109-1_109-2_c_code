#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a, *b, **c;
  int d[5] = {100, 101 , 102, 103, 104};
  int e[4][4] = {{10, 11, 12, 13},
                 {20, 21, 22, 23},
                 {30, 31, 32, 33},
                 {40, 41, 42, 43}};
  int f[3][3][3] = {0, 1, 2};
 
  b = &a + 2; 
  printf("\nStatement: b = &a + 2;\n");
  printf("Size of integer: %d\n", sizeof(int));
  printf("Address of a (&a): %d\n", &a);
  printf("Content of b (&a + 2): %d\n\n", b);  
  system("pause");
  
  b = d; 
  printf("\nStatement: b = d;\n");
  printf("Address of b (&b): %d\n", &b);
  printf("Address of d (&d): %d\n", &d);
  printf("Content of b: %d\n", b);
  printf("Content of d: %d\n", d);
  printf("Value of *b: %d\n", *b);
  printf("Value of *d: %d\n", *d);
  printf("Value of b[0]: %d\n", b[0]);
  printf("Value of d[0]: %d\n\n", d[0]); 
  system("pause");
  
  b = d + 3; 
  printf("\nStatement: b = d + 3;\n");
  printf("Address of d[3] (&d[3]): %d\n", &d[3]);
  printf("Content of b (d + 3): %d\n", b);
  printf("Value of d[3]: %d\n", d[3]);
  printf("Value of *(d + 3): %d\n", *(d + 3));
  printf("Value of *b: %d\n\n", *b);
  system("pause");
  
  c = (int**) e;
  printf("\nStatement: c = e;\n");
  printf("Address of e[0] (&e[0]): %d\n", &e[0]);
  printf("Content of e: %d\n", e);
  printf("Content of c: %d\n", c);
  printf("Value of c (*c): %d\n", *c);
  printf("Address of e[1] (&e[1]): %d\n", &e[1]);
  printf("Address of e[2] (&e[2]): %d\n", &e[2]);
  printf("Address of e[3] (&e[3]): %d\n\n", &e[3]);
  printf("Address of c[0] (&c[0]): %d\n", &c[0]);
  printf("Address of c[1] (&c[1]): %d\n", &c[1]);
  printf("Address of c[2] (&c[2]): %d\n", &c[2]);
  printf("Address of c[3] (&c[3]): %d\n\n", &c[3]);
  system("pause");
  
  printf("\nContent of e[0] (e[0]): %d\n", e[0]);
  printf("Content of e[1] (e[1]): %d\n", e[1]);
  printf("Content of e[2] (e[2]): %d\n", e[2]);
  printf("Content of e[3] (e[3]): %d\n", e[3]);
  printf("Address of e[0][0] (&e[0][0]): %d\n", &e[0][0]);
  printf("Address of e[1][0] (&e[1][0]): %d\n", &e[1][0]);
  printf("Address of e[2][0] (&e[2][0]): %d\n", &e[2][0]);
  printf("Address of e[3][0] (&e[3][0]): %d\n\n", &e[3][0]);
  printf("Address of c[0][0] (&c[0][0]): %d\n", &c[0][0]);
  printf("Address of c[1][0] (&c[1][0]): %d\n", &c[1][0]);
  printf("Address of c[2][0] (&c[2][0]): %d\n", &c[2][0]);
  printf("Address of c[3][0] (&c[3][0]): %d\n\n", &c[3][0]);
  // Try the next statement and see what happen.
  // printf("Value of c[0][0]: %d\n", c[0][0]);
  system("pause");
  
  printf("\nAddress of e[0][0] (&e[0][0]): %d\n", &e[0][0]);
  printf("Address of e[0][1] (&e[0][1]): %d\n", &e[0][1]);
  printf("Address of e[0][2] (&e[0][2]): %d\n", &e[0][2]);
  printf("Address of e[0][3] (&e[0][3]): %d\n", &e[0][3]);
  printf("Address of e[1][0] (&e[1][0]): %d\n", &e[1][0]);
  printf("Address of e[1][1] (&e[1][1]): %d\n", &e[1][1]);
  printf("Address of e[1][2] (&e[1][2]): %d\n", &e[1][2]);
  printf("Address of e[1][3] (&e[1][3]): %d\n", &e[1][3]);
  printf("Address of e[2][0] (&e[2][0]): %d\n", &e[2][0]);
  printf("Address of e[2][1] (&e[2][1]): %d\n", &e[2][1]);
  printf("Address of e[2][2] (&e[2][2]): %d\n", &e[2][2]);
  printf("Address of e[2][3] (&e[2][3]): %d\n", &e[2][3]);
  printf("Address of e[3][0] (&e[3][0]): %d\n", &e[3][0]);
  printf("Address of e[3][1] (&e[3][1]): %d\n", &e[3][1]);
  printf("Address of e[3][2] (&e[3][2]): %d\n", &e[3][2]);
  printf("Address of e[3][3] (&e[3][3]): %d\n", &e[3][3]);
  printf("Address of c[15] (&c[15]): %d\n\n", &c[15]);
  system("pause");
  
  printf("\nValue of e[0][0]: %d\n", e[0][0]);
  printf("Value of e[0][1]: %d\n", e[0][1]);
  printf("Value of e[0][2]: %d\n", e[0][2]);
  printf("Value of e[0][3]: %d\n", e[0][3]);
  printf("Value of e[1][0]: %d\n", e[1][0]);
  printf("Value of e[1][1]: %d\n", e[1][1]);
  printf("Value of e[1][2]: %d\n", e[1][2]);
  printf("Value of e[1][3]: %d\n", e[1][3]);
  printf("Value of e[2][0]: %d\n", e[2][0]);
  printf("Value of e[2][1]: %d\n", e[2][1]);
  printf("Value of e[2][2]: %d\n", e[2][2]);
  printf("Value of e[2][3]: %d\n", e[2][3]);
  printf("Value of e[3][0]: %d\n", e[3][0]);
  printf("Value of e[3][1]: %d\n", e[3][1]);
  printf("Value of e[3][2]: %d\n", e[3][2]);
  printf("Value of e[3][3]: %d\n", e[3][3]);
  printf("Value of c[15]: %d\n\n", c[15]);
  system("pause");
  
  printf("\nAddress of f (&f): %d\n", &f);
  printf("Content of f: %d \n", f);
  printf("Address of f[0] (&f[0]): %d \n", &f[0]);
  printf("Address of f[1] (&f[1]): %d \n", &f[1]);
  printf("Address of f[2] (&f[2]): %d \n", &f[2]);
  printf("Content of f[0]: %d \n", f[0]);
  printf("Content of f[1]: %d \n", f[1]);
  printf("Content of f[2]: %d \n\n", f[2]);
  system("pause");
  
  printf("\nAddress of f[0][0] (&f[0][0]): %d \n", &f[0][0]);
  printf("Address of f[0][1] (&f[0][1]): %d \n", &f[0][1]);
  printf("Address of f[0][2] (&f[0][2]): %d \n", &f[0][2]);
  printf("Content of f[0][0]: %d \n", f[0][0]);
  printf("Content of f[0][1]: %d \n", f[0][1]);
  printf("Content of f[0][2]: %d \n\n", f[0][2]);
  system("pause");
  
  printf("\nAddress of f[0][0][0] (&f[0][0][0]): %d \n", &f[0][0][0]);
  printf("Address of f[0][0][1] (&f[0][0][1]): %d \n", &f[0][0][1]);
  printf("Address of f[0][0][2] (&f[0][0][2]): %d \n", &f[0][0][2]);
  printf("Content of f[0][0][0]: %d \n", f[0][0][0]);
  printf("Content of f[0][0][1]: %d \n", f[0][0][1]);
  printf("Content of f[0][0][2]: %d \n\n", f[0][0][2]);
  system("pause");
  
}
