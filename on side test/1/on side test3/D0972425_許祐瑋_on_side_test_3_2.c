#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char a;
    int b;
    printf("INPUT your icon");
    scanf("%s", &a);
    printf("input hight");
    scanf("%d", &b);
    int k = 1;
    int l = b - 1;
    for (int i = 0; i != b; i++)
    {
        for (int j = 0; j != l; j++)
        {
            printf(" ");
        }
        for (int j = 0; j != k;j++ )
        {
            printf("%c", a);
        }
        l--;
        k += 2;
        puts(" ");
    }
    system("pause");
    return 0;
}