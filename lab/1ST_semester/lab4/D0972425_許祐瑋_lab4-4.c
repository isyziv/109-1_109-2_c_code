#include<stdio.h>
#include <stdlib.h>
int main(void)
{
    float a;
    printf("saleman's sale amount ");
    scanf("%f" , &a);
    if(a >= 15000 )
    {
    printf("*20%%");
    }
    if(a >= 10001) 
    {
        if(a <= 15000 )
        printf("*15%%");
    }
    if(a >= 5001) 
    {
        if(a <= 10000 )
        printf("*10%%");
    }
    if(a >= 0) 
    {
        if(a <= 5000 )
        printf("*0%%");
    }
    
        printf("\n");
        system("pause");
        return 0;
}