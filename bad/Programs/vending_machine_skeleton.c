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
	  printf("(A):�i��30��\n");
	  printf("(B):����30��\n");
	  printf("(C):�q�u��20��\n");
	  printf("(D):���ؤ�25��\n");
	  printf("(E):�����10��\n");
	  printf("(F):�d�}��20��\n");
	  printf("(G):��Q�w��50��\n");
	  printf("(H):�p���氮35��\n");
	  printf("(���H�W�H�~):���}\n\n");
	  printf("�п�ܧA�n�ʶR������:");
	  scanf("%s",&chose);
	  printf("\n");
	  switch(chose){
	  	//switch case  A
	    	case 'A':
	    		if(/*����*/){
	    			//�L�X�ϥΪ̩ҶR���F��,�æL�X�Ѿl�w���� 
	    		}
	    		else{ 
	    		    //�L�X�ϥΪ̵w������,�æL�X�ثe�w����
	    		    do{
	    		    	//���ܨϥΪ̬O�_�~����(1)Yes(2)No,�����ϥΪ̿�J,�ñN��J�ȼg��chose2
	    		        switch(chose2){
	    		        	//���O���Xcase1���~����,case2�����~�����B���}
							//case1���~����,�ñN�ĤG����J���w���Ƽg��dollar2,�B�P�@�}�l��J���w���Ƭۥ[,�A�N�`�w���ƦL�X 
							//case2�����~����,����ܥثe�w����,�B�^��W�@�h 
							//�P�_��J�w���ƬO�_��1,5,10,50������,�i�H�ѦҤW���{��8~20��
	    		       }
					}while(chose2!=1 && chose2!=2);
	    		} 
		  		break;
	  	//switch case B	�����~��g�U�h	
		  		
	  		
	  }
    }while(count!=0);  
	
	printf("��s�w��:%d\n", dollar);
	printf("\n");
	system("PAUSE");
	return 0;
}
