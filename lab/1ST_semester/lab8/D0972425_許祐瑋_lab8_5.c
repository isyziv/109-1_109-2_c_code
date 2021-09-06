#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    char b;
    int a;
    int c, d, e;
    printf("hight=");
    scanf("%d", &a);
    printf("symbol used to print the triangle: ");
    scanf("%s", &b);
    c = a - 1;
    d = 1;
    e = 1;
    c++;
    for (; c > 0; c--)
    {
        for (int i = 0; i != c; i++)
        {
            printf(" ");
        }
        for (int j = 0; j != e; j++)
        {
            printf("%c", b);
        }
        printf("\n");
        e += 2;
    }
    system("pause");
    return 0;
}
