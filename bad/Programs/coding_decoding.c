#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
  char source[40], target[40]; // ���J���r��M�s�X�᪺�r��
  char recover[40]; // �٭�᪺�r�� 
  int i, leng;
    
  //�s�Xï 
  char code_book[26] = {'H', 'Z', 'J', 'L', 'K', 'A', 'M', 'X', 'D', 'R', 'V', 'W', 'Y',
                        'O', 'C', 'G', 'N', 'T', 'B', 'Q', 'S', 'I', 'U', 'E', 'P', 'F'};
  char decode_book[26];
  
  // ���͹������ѽXï 
  for (i=0; i<26; i++) decode_book[code_book[i] - 65] = i+65;
  
  // �C�L�s�Xï
  printf("�s�Xï�G\n    ");
  for (i=0; i<26; i++) printf("%c ", i+65);
  printf("\n    ");
  for (i=0; i<26; i++) printf("%c ", code_book[i]);
  
  // �C�L�ѽXï
  printf("\n\n�ѽXï�G\n    ");
  for (i=0; i<26; i++) printf("%c ", i+65);
  printf("\n    ");
  for (i=0; i<26; i++) printf("%c ", decode_book[i]);
  printf("\n\n*******************************************************************\n\n");

  // ��J�^��r��
  printf("�п�J�^��r�����r��G ");
  i = 0;
  do {
    source[i] = getchar();
  } while (source[i++] != '\n');
  source[i] = '\0';
  
  // �N��r��s�X
  i = 0; 
  while (source[i] != '\0') {
    if (islower(source[i])) source[i]=toupper(source[i]);
    if (isalpha(source[i])) target[i] = code_book[source[i] - 65];
    else target[i] = source[i]; 
    i++; 
  }
  target[i] = '\0'; 
  
  printf("\n�j�g�r�����r��G %s\n\n", source);
  printf("�s�X�᪺�r��G %s\n\n", target);
  
  // �N�K�X�٭즨��Ӫ���r
  i = 0; 
  while (target[i] != '\0') {
    if (isalpha(target[i])) recover[i] = decode_book[target[i] - 65];
    else recover[i] = target[i];
    i++; 
  }
  recover[i] = '\0';
  
  printf("�٭�᪺�r��G %s\n\n", recover);
  
  system("pause");
  return 0;
}
