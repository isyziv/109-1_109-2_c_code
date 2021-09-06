/* 
    This is an enachaned version of the solution to the practice problem.
    An outer loop is added to repeat the entrie process, until "3" is entered
    at the first enquiry. 
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  unsigned char str[3];
  int method;
  
  do {
    printf("輸入 \"1\", 將中文字轉為編碼;輸入 \"2\", 將編碼轉為中文字；輸入 \"3\", 終止程式： ");
    scanf("%d", &method);
  
    if (method==1) {
      do {
        printf("\n輸入一個中文字 (若要結束程式，請輸入 \"停\")： ");
        scanf("%s", &str);
        printf("\"%s\" 的編碼是： %2X%2X\n", str, str[0], str[1]);
      } while (str[0]!=0XB0 || str[1]!=0XB1);
    }
    else if (method==2) {
      do {
        printf("\n輸入兩組二位數的 16 進位數字 (若要結束程式，請輸入 \"00 00\")： ");
        scanf("%X %X", &str[0], &str[1]);
        str[2] = '\0';
        printf("\"%02X%02X\" 的中文字是： %s\n", str[0], str[1], str);
      } while (str[0]!=0X00 || str[1]!=0X00);
    }
    else printf("\n請重新開始，並確認輸入 \"1\" 或 \"2\" \n");  
    printf("\n");
  } while (method != 3);
    
  return 0;
}
