#include <stdio.h>

int main(void) {

  float cDeg, fDeg;
  int cmd; 
  
  while (1) {
    printf("\n指令：  1. 攝氏轉華氏    2. 華氏轉攝氏    3. 結束\n" );
    printf("\n輸入指令： ");
    scanf("%d", &cmd);
    
    switch (cmd) {
      case 1: {
        printf("  輸入攝氏溫度： ");
        scanf("%f", &cDeg);
        fDeg = cDeg * 9 / 5 + 32;
        printf("  攝氏 %4.2f 度是等於華氏 %4.2f 度.\n", cDeg, fDeg);
        break; 
      } 
      case 2: {
        printf("  輸入華氏溫度： ");
        scanf("%f", &fDeg);
        cDeg = (fDeg - 32) * 5 / 9;
        printf("  華氏 %4.2f 度是等於攝氏 %4.2f 度.\n", fDeg, cDeg);
        break; 
      } 
      case 3: {
        system("pause");
        return 0; 
      } 
      default: printf("指令錯誤！\n");
    } 
  }
}

