/* �]�p�� : ���ش�
   �ɶ� : 2005/2/17 
   ���� : �p������׽d�ҵ{�� 
   ���e : �q�@�Ӥ���1~100���Ʀr
   �ɦW : guess_number.c 
*/

#include <stdio.h>
#include <stdlib.h> //rand(),srand() 
#include <time.h>

//�q1~100���H����@�ӼƦr 
int random_number() { 
   int n;
   
   n = rand() % 100 + 1; 
   
   return n; 
} 


void guess() {
  int target_num, guess_num, min, max;  //�ؼмƦr.�q���Ʀr.�Ʀr�d�� 
  int count;  //�q������ 
  int finish; 
  
  srand(time(0));  //�H���ƪ�l�� 
  do {
    target_num = random_number(); 
  } while (target_num == 100); 
  min = 1;
  max = 100;
  count = 0;
  finish = 0;
  
  do { 
    printf("\n#################################"); 
    printf("\n�п�J�n�q�����Ʀr (%d~%d) : ", min, max);  // (%d~%d)�ؼмƦr���d�� 
    scanf("%d", &guess_num);

    // �q���Ʀr > �ؼмƦr 
    if (guess_num > target_num && guess_num < max) {
      count ++;
      printf("��%d���q��\n", count); 
      printf("���׼Ʀr���� %d �M %d ����\n", min, guess_num);
      max = guess_num;  // �ؼмƦr�d�򪺳̤j�� 
    }
    
    // �q���Ʀr < �ؼмƦr
    else if (guess_num < target_num && guess_num > min) {
      count++; 
      printf("��%d���q��\n", count); 
      printf("���׼Ʀr���� %d �M %d ����\n", guess_num, max);
      min = guess_num;  // �ؼмƦr�d�򪺳̤p�� 
    }
    
    else if (guess_num == target_num) {
      printf("�q��F!\n"); 
      printf("�`�@�q�F %d ��\n",++count); 
      finish = 1;  //�j�鵲�� 
    }
    else printf("�q���Ʀr�W�X�d��A�A��J�@�ӼƦr\n"); 
      
  } while (!finish);
}

int main() {
  
  int sel;
  
  while(1) {
    printf("\n*******************\n"); 
    printf("�t�ο��\n"); 
    printf("1.�i�J�C��\n");
    printf("2.����\n"); 
        
    printf("��J���O�G "); 
    scanf("%d",&sel);
  
    switch (sel) {
      case 1: {
        guess();
        break;
      }        
      case 2: {
        return 0;
      }
      default: {
        printf("��ܿ��~.�Э��s���\n");
        break;
      }  
    }
  } 
}
