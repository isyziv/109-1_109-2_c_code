#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char a, b;
    unsigned short ab, c;
    scanf("%s", &a);
    ab = a;
    ab <<= 8;
    scanf("%s", &b);
    ab |= b;
    printf("%d", ab);
    system("pause");
    return 0;
}