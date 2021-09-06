#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Max 2000 
int main(){
 int N,i,j,check,prime[Max],count=0;
 do{
  printf("Enter the number(1~5000) and print prime numbers smaller than it :");
  scanf("%d",&N);
 }while(N<=0||N>5000);
 
 for(i=2;i<=N;i++){
  check=(int)sqrt(i); //fing the check number
  for(j=check;j>1;j--){
   if(i%j==0) 
    break;
  } 
  if(j==1)
   prime[count++]=i;
 }
 
 printf("\nprint all prime numbers:\n");
 int k=0;
 for(i=0;i<count;i++){
  printf("%5d",prime[i]);
  k++;
  if(k==10){
   printf("\n");
   k=0;
  }
 }   
 system("pause");
 return 0;
}
