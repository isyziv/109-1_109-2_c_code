#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define Max 100
int binarySearch(int [], int, int, int );
int bubble_sort(int *,int);

int main(){
 int a[Max],i,j,key,left,right,result=0; 
 left=0;right=Max;
 
 srand(time(NULL));
 for(i=0;i<Max;i++)
  a[i]=rand() % 500 + 1;
  
 printf("Before sorting array a is: ");
 printf("\n----------------------------------\n"); 
 j=0;
 for(i=0;i<100;i++){
   printf("%4d",a[i]);
   j++;
   if(j==10){
    printf("\n");
    j=0;
   } 
 }    
 printf("\n\n"); 
 
 bubble_sort(a,Max); 
  
 printf("After sorting array a is : ");
 printf("\n-----------------------------------------\n"); 
 j=0;
 for(i=0;i<Max;i++){
   printf("%4d",a[i]);
   j++;
   if(j==10){
    printf("\n");
    j=0;
   } 
 }    
 while(1){
  printf("\n\n"); 
  do{ 
   printf( "Enter a key between 1 and 500: " );
   scanf( "%d", &key );
  }while(key<=0||key>500);
  
  result=binarySearch(a,key,left,right);   
 
  if(result!=-1)
   printf("%d is found ",key);
  else 
   printf("%d is not found \n",key);
 }
 
 system("pause");   
 return 0;   
}

int bubble_sort(int *b,int n)
{
 int i,j,temp;
 for(i=Max;i>1;i--){
  for(j=0;j<i;j++)
  if(b[j]>b[j+1]){
   temp=b[j];
   b[j]=b[j+1];
   b[j+1]=temp;
  }
 }
 return 0;
}

int binarySearch(int b[], int key, int l, int r){
 int meddle;
 meddle=(l+r)/2;
 printf("meddle is at %d=%d \n",meddle,b[meddle]); 
 if(l>r)
  return -1;  
 else if(key==b[meddle])
  return 1; 
 else if(key>b[meddle])
  return binarySearch(b,key,meddle+1,r);
 else 
  return binarySearch(b,key,l,meddle-1);  
  
} 
 
 
   

