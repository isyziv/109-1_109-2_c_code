#include <stdio.h>

int main(void) {

  float cDeg, fDeg;
  int cmd; 
  
  while (1) {
    printf("\n���O�G  1. �����ؤ�    2. �ؤ������    3. ����\n" );
    printf("\n��J���O�G ");
    scanf("%d", &cmd);
    
    switch (cmd) {
      case 1: {
        printf("  ��J���ūסG ");
        scanf("%f", &cDeg);
        fDeg = cDeg * 9 / 5 + 32;
        printf("  ��� %4.2f �׬O����ؤ� %4.2f ��.\n", cDeg, fDeg);
        break; 
      } 
      case 2: {
        printf("  ��J�ؤ�ūסG ");
        scanf("%f", &fDeg);
        cDeg = (fDeg - 32) * 5 / 9;
        printf("  �ؤ� %4.2f �׬O������� %4.2f ��.\n", fDeg, cDeg);
        break; 
      } 
      case 3: {
        system("pause");
        return 0; 
      } 
      default: printf("���O���~�I\n");
    } 
  }
}

