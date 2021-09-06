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
  for (i=0; i<26; i++) decode_book[code_book[i] - 65] = i+65;
  
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
  i = 0; 
  while (source[i] != '\0') {
    if (islower(source[i])) source[i]=toupper(source[i]);
    if (isalpha(source[i])) target[i] = code_book[source[i] - 65];
    else target[i] = source[i]; 
    i++; 
  }
  target[i] = '\0'; 
  
  printf("\n大寫字母的字串： %s\n\n", source);
  printf("編碼後的字串： %s\n\n", target);
  
  // 將密碼還原成原來的文字
  i = 0; 
  while (target[i] != '\0') {
    if (isalpha(target[i])) recover[i] = decode_book[target[i] - 65];
    else recover[i] = target[i];
    i++; 
  }
  recover[i] = '\0';
  
  printf("還原後的字串： %s\n\n", recover);
  
  system("pause");
  return 0;
}
