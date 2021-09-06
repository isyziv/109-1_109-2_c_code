#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n = 0;
    printf("please input N = ");
    scanf("%d", &n);
    int i, j;
    i = j = 0;
    while (n != i)
    {
        if (j % 2 == 0)
        {
            i++;
        }
        j++;
    }
    j--;
    printf("%d", j);
    system("pause");
    return 0;
}