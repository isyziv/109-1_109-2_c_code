#include<stdio.h>
#include <stdlib.h>
int main(void)
{
    int a;
        printf("student score ");
    scanf("%d" ,&a);
    if(a >= 80) 
    {
        if(a <= 100 )
        printf("A");
    }
    if(a >= 70) 
    {
        if(a <= 79 )
        {
        printf("B");
        }
    }
    if(a >= 60) 
    {
        if(a <= 69 )
        {
        printf("C");
        }
    }
    if(a >= 0) 
    {
        if(a <= 50 )
        {
        printf("F");
        }
    }
    system ("pause");
    return 0 ;
}