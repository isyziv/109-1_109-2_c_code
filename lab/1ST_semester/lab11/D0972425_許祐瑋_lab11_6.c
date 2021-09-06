#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    srand(time(NULL));
    int size = rand() % 100;
    int sizea = size + 1;
    int a[size];
    int min = 0, number = 0, x = 0;
    for (int i = 0; i != size; i++)
    {
        a[i] = rand();
        printf("%3d. %6d\n", i, a[i]);
    }
    puts("start selection sort");
    for (int j; j != sizea; j++)
    {
        for (int i = number; i != sizea; i++)
        {
            if (a[min] > a[i])
            {
                min = i;
            }
        }
        x = a[number];
        a[number] = a[min];
        a[min] = x;
        number++;
    }

    for (int i = 0; i != size; i++)
    {
        printf("%3d. %6d\n", i, a[i]);
    }
    system("pause");
    return 0;
}