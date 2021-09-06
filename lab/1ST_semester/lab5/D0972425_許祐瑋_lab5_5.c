#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int range = 201;
    int i, j;
    i = j = 0;
    do
    {
        if ((i % 2) == 0)
        {
            j++;
        }
        if (j != range)
        {
            i++;
        }
    } while (j != range);
    printf("%d\n", i);
    system("pause");
    return 0;
}