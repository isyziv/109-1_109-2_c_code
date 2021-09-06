#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
void act(FILE* data, int j)
{
    int array[99];
    int i = 0;
    if (j == 1)puts("(a)");
    rewind(data);
    for (i = 0; !feof(data); i++)
    {
        fscanf(data, "%d ", &array[i]);
    }
    bubbleSort(array, i,1);
    if (j == 1)puts("(b)");
    rewind(data);
    for (i = 0; !feof(data); i++)
    {
        fscanf(data, "%d ", &array[i]);
    }
    insertionSort(array, i,1);
    if (j == 1)puts("\n(c)");
    rewind(data);
    for (i = 0; !feof(data); i++)
    {
        fscanf(data, "%d ", &array[i]);
    }
    selectionSort(array, i,1);
}
int main()
{
    FILE* data;
    data = fopen("data.txt", "r");
    act(data, 1);
    puts("(d)");
    act(data, 0);
    system("pause");
}