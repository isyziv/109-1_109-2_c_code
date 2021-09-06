#include<stdio.h>
#include <stdlib.h>
int main(void)
{
    int a, i;
    i = 1;
    a = 0;
    while (i<101)
    {
        a = a + i;
        i++;
    }
    printf("%d\n" ,a);
    system ("pause");
    return 0 ;
}