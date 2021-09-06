#include<stdio.h>
#include <stdlib.h>
int main(void)
{
    int a, b, c;
    int x, y, z;
    scanf("%d%d%d" , &a,&b,&c);
    x = a;
    y = b;
    z = c;
    int i,w;
    i = 0;
    do
    {
        if(x > y)
        {
            w = x;
            x = y;
            y = w;
        }
        if(y>z)
        {
            w = y;
            y = z;
            z = w;
        }
        i++;
    } while (i != 3);
    printf("\n%d\n%d\n%d\n" , x ,y, z);
    system ("pause");
    return 0 ;
}