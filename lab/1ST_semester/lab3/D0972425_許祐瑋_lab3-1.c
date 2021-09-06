#include<stdio.h>
#include <stdlib.h>
int main(void)
{
    int x, y, z;
    scanf("%d" ,&x );
    scanf("%d" ,&y );
    z = (x % y);
    printf("%d" , z);
    system("pause");
    return 0;
}

