#include<stdio.h>
#include <stdlib.h>
int main(void)
{
    int a ,b ,c ;
    printf("integers a is ");
    scanf("%d" , &a);
    printf("integers b is ");
    scanf("%d" , &b);
    c = a % b;
    if (c == 0)
    {
        printf("integers %d is a multiple of the %d\n" ,a ,b);
    }
    system ("pause");
    return 0 ;
}
