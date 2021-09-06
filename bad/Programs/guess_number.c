/* 設計者 : 王建智
   時間 : 2005/2/17 
   說明 : 計算機概論範例程式 
   內容 : 猜一個介於1~100的數字
   檔名 : guess_number.c 
*/

#include <stdio.h>
#include <stdlib.h> //rand(),srand() 
#include <time.h>

//從1~100當中隨機選一個數字 
int random_number() { 
   int n;
   
   n = rand() % 100 + 1; 
   
   return n; 
} 


void guess() {
  int target_num, guess_num, min, max;  //目標數字.猜測數字.數字範圍 
  int count;  //猜測次數 
  int finish; 
  
  srand(time(0));  //隨機數初始化 
  do {
    target_num = random_number(); 
  } while (target_num == 100); 
  min = 1;
  max = 100;
  count = 0;
  finish = 0;
  
  do { 
    printf("\n#################################"); 
    printf("\n請輸入要猜測的數字 (%d~%d) : ", min, max);  // (%d~%d)目標數字的範圍 
    scanf("%d", &guess_num);

    // 猜測數字 > 目標數字 
    if (guess_num > target_num && guess_num < max) {
      count ++;
      printf("第%d次猜測\n", count); 
      printf("答案數字介於 %d 和 %d 之間\n", min, guess_num);
      max = guess_num;  // 目標數字範圍的最大值 
    }
    
    // 猜測數字 < 目標數字
    else if (guess_num < target_num && guess_num > min) {
      count++; 
      printf("第%d次猜測\n", count); 
      printf("答案數字介於 %d 和 %d 之間\n", guess_num, max);
      min = guess_num;  // 目標數字範圍的最小值 
    }
    
    else if (guess_num == target_num) {
      printf("猜對了!\n"); 
      printf("總共猜了 %d 次\n",++count); 
      finish = 1;  //迴圈結束 
    }
    else printf("猜測數字超出範圍，再輸入一個數字\n"); 
      
  } while (!finish);
}

int main() {
  
  int sel;
  
  while(1) {
    printf("\n*******************\n"); 
    printf("系統選單\n"); 
    printf("1.進入遊戲\n");
    printf("2.結束\n"); 
        
    printf("輸入指令： "); 
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
        printf("選擇錯誤.請重新選擇\n");
        break;
      }  
    }
  } 
}
