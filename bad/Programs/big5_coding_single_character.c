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
    printf("��J \"1\", �N����r�ର�s�X;��J \"2\", �N�s�X�ର����r�F��J \"3\", �פ�{���G ");
    scanf("%d", &method);
  
    if (method==1) {
      do {
        printf("\n��J�@�Ӥ���r (�Y�n�����{���A�п�J \"��\")�G ");
        scanf("%s", &str);
        printf("\"%s\" ���s�X�O�G %2X%2X\n", str, str[0], str[1]);
      } while (str[0]!=0XB0 || str[1]!=0XB1);
    }
    else if (method==2) {
      do {
        printf("\n��J��դG��ƪ� 16 �i��Ʀr (�Y�n�����{���A�п�J \"00 00\")�G ");
        scanf("%X %X", &str[0], &str[1]);
        str[2] = '\0';
        printf("\"%02X%02X\" ������r�O�G %s\n", str[0], str[1], str);
      } while (str[0]!=0X00 || str[1]!=0X00);
    }
    else printf("\n�Э��s�}�l�A�ýT�{��J \"1\" �� \"2\" \n");  
    printf("\n");
  } while (method != 3);
    
  return 0;
}
