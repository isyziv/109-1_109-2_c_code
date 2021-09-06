#include<stdio.h>
#include<stdlib.h>

int main(void){
	
	char chose,count=1;
	int dollar,dollar2,num=0,chose2;
	do{
		if(num==0){
			printf("This is a vending machine.\n");
			printf("Please put in your coin(1 or 5 or 10 or 50):");
			scanf("%d",&dollar);
			num=1;
		}
		else{
			printf("No this coin.\nPlease Put in the coin again.\nPut in:");
			scanf("%d",&dollar);
		}
	}while(dollar!=1 && dollar!=5 && dollar!=10 && dollar!=50);
	num=0;
	
	do{
	  printf("\n");
	  printf("(A):可樂30元\n");
	  printf("(B):雪碧30元\n");
	  printf("(C):礦泉水20元\n");
	  printf("(D):茶裏王25元\n");
	  printf("(E):科學麵10元\n");
	  printf("(F):卡迪那20元\n");
	  printf("(G):阿Q泡麵50元\n");
	  printf("(H):小熊餅乾35元\n");
	  printf("(除以上以外):離開\n\n");
	  printf("請選擇你要購買的項目:");
	  scanf("%s",&chose);
	  printf("\n");
	  switch(chose){
	  	//switch case  A
	    	case 'A':
	    		if(/*條件式*/){
	    			//印出使用者所買的東西,並印出剩餘硬幣數 
	    		}
	    		else{ 
	    		    //印出使用者硬幣不足,並印出目前硬幣數
	    		    do{
	    		    	//提示使用者是否繼續投幣(1)Yes(2)No,並讓使用者輸入,並將輸入值寫到chose2
	    		        switch(chose2){
	    		        	//分別做出case1為繼續投幣,case2為不繼續投幣且離開
							//case1為繼續投幣,並將第二次投入的硬幣數寫到dollar2,且與一開始輸入的硬幣數相加,再將總硬幣數印出 
							//case2為不繼續投幣,並顯示目前硬幣數,且回到上一層 
							//判斷輸入硬幣數是否為1,5,10,50的條件式,可以參考上面程式8~20行
	    		       }
					}while(chose2!=1 && chose2!=2);
	    		} 
		  		break;
	  	//switch case B	接著繼續寫下去	
		  		
	  		
	  }
    }while(count!=0);  
	
	printf("找零硬幣:%d\n", dollar);
	printf("\n");
	system("PAUSE");
	return 0;
}
