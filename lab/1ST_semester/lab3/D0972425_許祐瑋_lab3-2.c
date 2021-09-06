#include<stdio.h>
#include <stdlib.h>
int main(void)
{
    int a, b, c, d ,e;
    float f,g ;
    printf("integers 1 is");
    scanf("%d",&a);
    printf("integers 2 is");
    scanf("%d",&b);
    printf("integers 3 is");
    scanf("%d",&c);
    printf("integers 4 is");
    scanf("%d",&d);
    printf("integers 5 is");
    scanf("%d",&e);
    f = a + b + c + d + e;
    g = f / 5;
    printf("%f",g);
    system("pause");
    return 0;
}
