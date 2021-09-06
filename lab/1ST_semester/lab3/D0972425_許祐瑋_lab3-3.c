#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a, b;
    float c;
    printf("integer is");
    scanf("%d", &a);
    c = sqrt(a);
    b = a * a * a;
    printf("x^2= %f\n", c);
    printf("X^3= %d", b);
    system("pause");
    return 0;
}