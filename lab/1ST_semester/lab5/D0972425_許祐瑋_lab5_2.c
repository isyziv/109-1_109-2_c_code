#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a, b, c;
    printf("interager N =");
    scanf_s("%d", &a);
    b = c = 1;
    do
    {
        b++;
        c = b * c;
    } while (b != a);
    printf("N!=%d\n", c);
    system("pause");
    return 0;
}