#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int math(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    return (a + a * (b - 1));
}
int main(void)
{
    int a, b;
    printf("please intput a integer");
    scanf("%d", &a);
    printf("please intput another integer");
    scanf("%d", &b);
    printf("%d", math(a, b));

    system("pause");
    return 0;
}
