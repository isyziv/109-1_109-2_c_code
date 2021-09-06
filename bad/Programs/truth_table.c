#include<stdio.h>
#include<stdlib.h>

int XOR(int P, int Q) {
  switch (P) {
    case 0: {
      switch (Q) {
        case 0: {
          return 0;
          break;
        }
        default: {
          return 1;
          break;
        }
      }
    }
    default: {
      switch (Q) {
        case 0: {
          return 1;
          break;
        }
        default: {
          return 0;
          break;
        }
      }
    }
  }  
}

int IMPLY(int P, int Q) {
  switch (P) {
    case 0: {
      switch (Q) {
        case 0: {
          return 1;
          break;
        }
        default: {
          return 1;
          break;
        }
      }
    }
    default: {
      switch (Q) {
        case 0: {
          return 0;
          break;
        }
        default: {
          return 1;
          break;
        }
      }
    }
  }  
}

int EQUIV(int P, int Q) {
  switch (P) {
    case 0: {
      switch (Q) {
        case 0: {
          return 1;
          break;
        }
        default: {
          return 0;
          break;
        }
      }
    }
    default: {
      switch (Q) {
        case 0: {
          return 0;
          break;
        }
        default: {
          return 1;
          break;
        }
      }
    }
  }  
}

int main(void) {
  int P=0, Q=1;
  
  printf("  P | Q | P XOR Q\n");  
  printf(" ---|---|---------\n");
  printf("  0 | 0 |    %d\n", XOR(0,0));
  printf("  0 | 1 |    %d\n", XOR(0,1));
  printf("  1 | 0 |    %d\n", XOR(1,0));
  printf("  1 | 1 |    %d\n\n", XOR(1,1));
  
  printf("  P | Q | P ==> Q\n");  
  printf(" ---|---|---------\n");
  printf("  0 | 0 |    %d\n", IMPLY(0,0));
  printf("  0 | 1 |    %d\n", IMPLY(0,1));
  printf("  1 | 0 |    %d\n", IMPLY(1,0));
  printf("  1 | 1 |    %d\n\n", IMPLY(1,1));
  
  printf("  P | Q | P <=> Q\n");  
  printf(" ---|---|---------\n");
  printf("  0 | 0 |    %d\n", EQUIV(0,0));
  printf("  0 | 1 |    %d\n", EQUIV(0,1));
  printf("  1 | 0 |    %d\n", EQUIV(1,0));
  printf("  1 | 1 |    %d\n\n", EQUIV(1,1));
  
  system("pause");
  return 0;
}
