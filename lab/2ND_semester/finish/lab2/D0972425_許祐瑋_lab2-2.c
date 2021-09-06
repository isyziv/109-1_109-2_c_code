#include <stdio.h>
#include <stdlib.h>
void largest(int a[], int n, int *largest)
{
    int tmp = 0;
    for (int i = 0; i != n; i++)
    {
        if (*largest < a[i])
        {
            largest = &a[i];
        }
    }
    printf("%d", *largest);
}
int main(void)
{
    int a[5] = {2, 3, 1, 5, 4};
    int n = 5;
    int *largest_V;

    largest_V = &a[0];
    largest(a, n, largest_V);

    system("pause");
    return 0;
}
