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
  // �������{�����q�C 
  
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
  // �������{�����q�C 
  
  printf("\n�j�g�r�����r��G %s\n\n", source);
  printf("�s�X�᪺�r��G %s\n\n", target);
  
  // �N�K�X�٭즨��Ӫ���r
  // �������{�����q�C 
  
  printf("�٭�᪺�r��G %s\n\n", recover);
  
  system("pause");
  return 0;
}
