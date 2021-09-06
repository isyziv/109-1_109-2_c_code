#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int math(int a)
{
    int f;
    f = (6 * pow(a, 4)) + (5 * pow(a, 3)) + (4 * pow(a, 2)) + (3 * a) + 2;
    return f;
}
int main(void)
{
    int a;
    int b;
    printf("x= ");
    scanf("%d", &a);
    printf("%d", math(a));
    system("pause");
    return 0;
}
