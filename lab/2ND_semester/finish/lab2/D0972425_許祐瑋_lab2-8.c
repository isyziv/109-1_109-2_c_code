#include <stdio.h>
#include <stdlib.h>
void largest(int a[], int n, int *largest, int *smallest)
{
    int tmp = 0;
    for (int i = 0; i != n; i++)
    {
        if (*largest < a[i])
        {
            *largest = a[i];
        }
    }
    for (int i = 0; i != n; i++)
    {
        if (*smallest > a[i])
        {
            *smallest = a[i];
        }
    }
    //printf("%d", *largest);
}
int main(void)
{
    int a[5] = {2, 3, 1, 5, 9};
    int n = 5;
    int *largest_V;
    int *smallest;
    int l = INT_MIN, s = INT_MAX;
    largest_V = &l;
    smallest = &s;
    largest(a, n, largest_V, smallest);
    printf("The largest value is %d\n", l);
    printf("The smallest value is %d \n", s);
    system("pause");
    return 0;
}