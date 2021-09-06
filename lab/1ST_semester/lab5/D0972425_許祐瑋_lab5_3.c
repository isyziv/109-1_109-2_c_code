#include<stdio.h>
#include<stdlib.h>
#define range 10
int main(void)
{
    int a[range];
    int i ,j ;
    i = j = 0;
    int k;
    for (k = 1; j != range; k++)//find even number
    {
        if((i%2)==0 && i!=0 )//if even
        {
            a[j] = i;
            j++;
        }
        i++;//else(odd)
    }
    j = 0;
    for (k = 1; j != range;k++) //layout
    {
        if (j!=range)//printf loop
       {
            printf("%d\n" ,a[j]);
            j++;
       }
    }
    system("pause");
    return 0;
}