#include <stdio.h>
#include <stdlib.h>

void math_a(int n)
{
    int a, b, c, d;
    a = n;
    b = n;
    c = n - 3;
    d = n - 3;
    printf("\t");
    for (int i = 0; i != a; i++)
    {
        printf("*");
    }
    printf("\n\t");
    for (int i = 0; i != c; i++)
    {
        printf("*");
        for (int i = 0; i != d; i++)
        {
            printf("@");
        }
        printf("*");
        d--;
        printf("\n\t");
    }
    printf("**\n\t*\n");
    system("pause");
}
void math_b(int n)
{
    int a, b, c, d;
    a = n;
    b = n;
    c = n - 3;
    d = n - 3;
    int e = 1;
    printf("\t*\n\t**");
    printf("\n\t");
    for (int i = 0; i != c; i++)
    {
        printf("*");
        for (int j = 0; j != e; j++)
        {
            printf("@");
        }
        printf("*");
        e++;
        printf("\n\t");
    }
    for (int i = 0; i != a; i++)
    {
        printf("*");
    }
    printf("\n");

    system("pause");
}
void math_c(int n)
{
    int a, b, c, d, e;
    a = n;
    b = n;
    c = n - 3;
    d = n - 3;
    e = 0;
    printf("\t");
    for (int i = 0; i != a; i++)
    {
        printf("*");
    }
    printf("\n\t");
    e++;
    for (int i = 0; i != c; i++)
    {
        for (int i = 0; i != e; i++)
        {
            printf(" ");
        }
        printf("*");
        for (int i = 0; i != d; i++)
        {
            printf("@");
        }
        printf("*");
        d--;
        printf("\n\t");
        e++;
    }
    for (int i = 0; i != e; i++)
    {
        printf(" ");
    }
    e++;
    printf("**\n\t");
    for (int i = 0; i != e; i++)
    {
        printf(" ");
    }
    printf("*\n");
    system("pause");
}
void math_d(int n)
{
    int a, b, c, d;
    a = n;
    b = n;
    c = n - 3;
    d = n - 3;
    int e = 1;
    int f = n;
    printf("\t");
    for (int i = 0; i != f; i++)
    {
        printf(" ");
    }
    printf("*\n\t");
    f--;
    for (int i = 0; i != f; i++)
    {
        printf(" ");
    }
    f--;
    printf("**\n\t");
    for (int i = 0; i != c; i++)
    {
        for (int i = 0; i != f; i++)
        {
            printf(" ");
        }
        printf("*");
        for (int j = 0; j != e; j++)
        {
            printf("@");
        }
        printf("*");
        e++;
        printf("\n\t");
        f--;
    }
    for (int i = 0; i != f; i++)
    {
        printf(" ");
    }
    f--;
    for (int i = 0; i != a; i++)
    {
        printf("*");
    }
    printf("\n");

    system("pause");
}
int main(void)
{
    int n;
    char input;

    printf("intput 'a' 'b' 'c' or 'd' ");
    scanf("%s", &input);
    printf("please intput size ");
    scanf("%d", &n);
    switch (input)
    {
    case 'a':
        math_a(n);
        break;

    case 'b':

        math_b(n);
        break;
    case 'c':
        math_c(n);
        break;
    case 'd':
        math_d(n);
        break;
    default:
        printf("error\n");
        system("pause");
        return 0;
        break;
        system("pause");
    }
    return 0;
}