#include <stdio.h>
#include <stdlib.h>
void math(range)
{
    int i, j;
    i = j = 0;
    do
    {
        if ((i % 2) == 0)
        {
            j++;
            printf("%d\t", i);
            if (j % 10 == 0)
            {
                printf("\n");
            }
        }
        if (j != range)
        {
            i++;
        }
    } while (j != range);
}
int main(void)
{
    int range;
    printf("input range");
    scanf("%d", &range);
    math(range);
    system("pause");
    return 0;
}
