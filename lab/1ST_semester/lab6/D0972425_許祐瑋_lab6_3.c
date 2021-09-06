#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, j, k;
    char a;
    scanf("%s", &a);
    switch (a)
    {
    case 'a':

        for (i = 0; i != 10; i++)
        {
            for (j = 0; i != j; j++)
            {
                printf_s("*");
            }
            puts("*");
        }
        puts("");
        break;

    case 'b':

        for (i = 0; i != 10; i++)
        {
            for (j = (10 - i - 1); j != 0; j--)
            {
                printf_s("*");
            }
            puts("*");
        }
        puts("");
        break;
    case 'c':

        for (i = 0; i != 10; i++)
        {
            for (k = 0; k != i; k++)
            {
                printf_s(" ");
            }
            
            for (j = (10 - i - 1); j != 0; j--)
            {
                printf_s("*");
            }
            puts("*");
        }
        puts("");
        break;
    case 'd':

        for (i = 0; i != 10; i++)
        {
            for (k = 10 - i - 1; k != 0; k--)
            {
                printf_s(" ");
            }
            for (j = 0; j != i; j++)
            {
                printf_s("*");
            }
            puts("*");
        }
        break;
    }
    system("pause");
    return 0;
}
