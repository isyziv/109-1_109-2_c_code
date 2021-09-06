/* �@�ʸt�Ͼ𪺵e�k�i�H�O�@�Ӧh�h����ߵ��y�T�����|�b�@�_�A
   �̤W�h���T��������̤p�A�V���U���T��������V�j�F
   �C�@�ӤT���Ϊ������M�U�@�ӤT���Ϊ����I���|�b�@�_�C
   �̩������T���ΤU���e�@�ӹ�ߪ���Χ@����F�C
   �g�@�� C �y�����{���e�@�ʦp�U�ҩw�q�t�Ͼ�G
     1. �t�Ͼ𪺼h�Ʀb 2 �M 5 ���� (�t)�A
     2. ���ݪ��T��������b  3 �M 6 ���� (�t)�A
     3. �C�@�ӤU���T���Ϊ�������W�ݤT���Τj 1 �� 5 �I (�t)�A
     4. ��F���e�O 3 �M 9 �������_�� (�t)�A
     5. ��F�����b 4 �� 10���� (�t)�A
     6. �ϥ� '#' �@���T�����䪺�I�M '@'�@���T���Τ������I�A
     7. �ϥ� '|' �@����F���I�C

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
  
  // Ū�J�h�� 
  do {
    printf("\n Enter the number of layers (2 to 5): ");
    scanf("%d", &layer);
  } while ((layer < 2) || (layer > 5));
  
  // Ū�J���ݤT���Ϊ���� 
  do {
    printf("\n Enter the side of top layer (3 to 6): ");
    scanf("%d", &side);
  } while ((side < 3) || (side > 6));
  
  // Ū�J�U�@�ӤT��������W�[���I�� 
  do {
    printf("\n Enter the growth of each layer (1 to 5): ");
    scanf("%d", &growth);
  } while ((growth < 1) || (growth > 5));
  
  // Ū�J��F���e�� 
  do {
    printf("\n Enter the trunk width (odd number, 3 to 9): ");
    scanf("%d", &twidth);
  } while ((twidth < 3) || (twidth > 9) || (twidth % 2 == 0));
  
  // Ū�J��F������ 
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
