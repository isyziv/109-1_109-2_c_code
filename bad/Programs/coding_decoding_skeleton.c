#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
  char source[40], target[40]; // 原輸入之字串和編碼後的字串
  char recover[40]; // 還原後的字串 
  int i, leng;
    
  //編碼簿 
  char code_book[26] = {'H', 'Z', 'J', 'L', 'K', 'A', 'M', 'X', 'D', 'R', 'V', 'W', 'Y',
                        'O', 'C', 'G', 'N', 'T', 'B', 'Q', 'S', 'I', 'U', 'E', 'P', 'F'};
  char decode_book[26];
  
  // 產生對應的解碼簿 
  // 完成此程式片段。 
  
  // 列印編碼簿
  printf("編碼簿：\n    ");
  for (i=0; i<26; i++) printf("%c ", i+65);
  printf("\n    ");
  for (i=0; i<26; i++) printf("%c ", code_book[i]);
  
  // 列印解碼簿
  printf("\n\n解碼簿：\n    ");
  for (i=0; i<26; i++) printf("%c ", i+65);
  printf("\n    ");
  for (i=0; i<26; i++) printf("%c ", decode_book[i]);
  printf("\n\n*******************************************************************\n\n");
     
  // 輸入英文字串 
  printf("請輸入英文字母的字串： ");
  i = 0;
  do {
    source[i] = getchar();
  } while (source[i++] != '\n');
  source[i] = '\0';
  
  // 將原字串編碼
  // 完成此程式片段。 
  
  printf("\n大寫字母的字串： %s\n\n", source);
  printf("編碼後的字串： %s\n\n", target);
  
  // 將密碼還原成原來的文字
  // 完成此程式片段。 
  
  printf("還原後的字串： %s\n\n", recover);
  
  system("pause");
  return 0;
}
