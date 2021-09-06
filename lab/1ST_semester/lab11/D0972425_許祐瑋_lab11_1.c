#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a[10], b[10];
    int x, out;
    for (int i = 0; i != 10; i++)
    {
        x = rand();
        a[i] = x;
        x = rand();
        b[i] = x;
    }
    for (int j = 0; j != 2; j++)
    {
        if (j == 0)
        {
            puts("matrix a =");
        }
        if (j == 1)
        {
            puts("matrix b =");
        }
        printf("[");
        for (int i = 0; i != 10; i++)
        {
            if (j == 0)
            {
                out = a[i];
            }
            if (j == 1)
            {
                out = b[i];
            }
            printf("%10d", out);
        }
        printf("]");
        puts(" ");
    }
    out = 0;
    for (int i = 0; i != 10; i++)
    {
        out += a[i] * b[i];
    }
    printf("the inner product a b =%15d\n", out);
    system("pause");
    return 0;
}