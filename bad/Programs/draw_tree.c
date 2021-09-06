/* 一棵聖誕樹的畫法可以是一個多層的實心等腰三角形疊在一起，
   最上層的三角形邊長最小，越往下的三角形邊長越大；
   每一個三角形的底部和下一個三角形的頂點重疊在一起。
   最底部的三角形下面畫一個實心長方形作為樹幹。
   寫一個 C 語言的程式畫一棵如下所定義聖誕樹：
     1. 聖誕樹的層數在 2 和 5 之間 (含)，
     2. 頂端的三角形邊長在  3 和 6 之間 (含)，
     3. 每一個下面三角形的邊長比其上端三角形大 1 至 5 點 (含)，
     4. 樹幹的寬是 3 和 9 之間的奇數 (含)，
     5. 樹幹的高在 4 到 10之間 (含)，
     6. 使用 '#' 作為三角形邊的點和 '@'作為三角形內部的點，
     7. 使用 '|' 作為樹幹的點。

*/

#include <stdio.h>
#include <stdlib.h>

void printChar(int n, char c) {
 int i;
 
 for (i = 0; i < n; i++) printf("%c", c);
}

int main(void) {
  const int leading = 10;
  int layer, L, side, growth, theight, twidth, n, i;
  
  // 讀入層數 
  do {
    printf("\n Enter the number of layers (2 to 5): ");
    scanf("%d", &layer);
  } while ((layer < 2) || (layer > 5));
  
  // 讀入頂端三角形的邊長 
  do {
    printf("\n Enter the side of top layer (3 to 6): ");
    scanf("%d", &side);
  } while ((side < 3) || (side > 6));
  
  // 讀入下一個三角形邊長增加的點數 
  do {
    printf("\n Enter the growth of each layer (1 to 5): ");
    scanf("%d", &growth);
  } while ((growth < 1) || (growth > 5));
  
  // 讀入樹幹的寬度 
  do {
    printf("\n Enter the trunk width (odd number, 3 to 9): ");
    scanf("%d", &twidth);
  } while ((twidth < 3) || (twidth > 9) || (twidth % 2 == 0));
  
  // 讀入樹幹的高度 
  do {
    printf("\n Enter the trunk height (4 to 10): ");
    scanf("%d", &theight);
  } while ((theight < 4) || (theight > 10));
  
  printf("\n\n");
  for (L = 0; L < layer; L++) {
    n = side + growth * L;
    if (L==0) {
      printChar(leading + n-1+(layer-L-1)*growth, ' ');
      printChar(1, '#');
      printf("\n");
    }
    
    for (i = 1; i < n-1; i++) {
      printChar(leading + n-i-1+(layer-L-1)*growth, ' ');
      printChar(1, '#');
      printChar(2*i-1, '@');
      printChar(1, '#');
      printf("\n");
    }
    
    printChar(leading + (layer-L-1)*growth, ' ');
    printChar(2*n-1, '#');
    printf("\n");
  }
    
  for (i = 0; i < theight; i++) {
    printChar(leading + (layer-1)*growth+side-1-twidth/2, ' ');
    printChar(twidth, '|');
    printf("\n");
  }
  printf("\n"); 
    
  system("pause");
  return 0;
}
