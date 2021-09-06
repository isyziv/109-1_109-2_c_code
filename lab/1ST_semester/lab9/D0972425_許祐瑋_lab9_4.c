#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int a;
//int b;
int c;
int math(int num)
{
    if (c == 1)
    {
        return num;
    }
    else
    {
        c--;
        return num * math(num);
    }
}
int main(void)
{
    int b;
    printf("base =");
    scanf("%d", &b);
    a = b;
    printf("power =");
    scanf("%d", &c);
    printf("%d", math(b));
    system("pause");
    return 0;
}
