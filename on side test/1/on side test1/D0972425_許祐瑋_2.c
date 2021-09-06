#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float a, b, c;
    printf("salesmans sale ");
    scanf("%f", &a);
    b = 0;
    c = 0;

    if (a <= 0)
    {
        printf("error");
    }
    if (0 < a && a <= 1000)
    {
        b = 0;
    }
    if (a > 1000 && a <= 2000)
    {
        b = 0.2;
    }
    if (a > 2000 && a <= 5000)
    {
        b = 0.5;
    }
    if (a > 5000 && a <= 10000)
    {
        b = 0.8;
    }
    if (a > 10000)
    {
        b = 0.12;
    }
    c = a * b;
    if (a > 0)
    {
        printf("bones=%1.3f\n", c);
    }
    system("pause");
    return 0;
}
