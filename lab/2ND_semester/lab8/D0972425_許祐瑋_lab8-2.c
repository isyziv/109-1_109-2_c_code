#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int git(FILE* data, int array[])
{
    int i;
    rewind(data);
    for (i = 0; !feof(data); i++)
    {
        fscanf(data, "%d ", &array[i]);
    }
    return i;
}
int main()
{
    FILE* data;
    srand(time(NULL));
    data = fopen("data.txt", "r");
    int array[99];
    int a = 0, i;
    int re;
    i = git(data, array);
    bubbleSort(array, i, 0);
    show_array(array, i);
    puts(" ");
    puts(" ");
    i = git(data, array);
    a = array[rand() % i];
    printf("find : %d\n", a);
    bubbleSort(array, i, 0);
    re = binarySearch(array, a, 0, i - 1, i);
    re == -1 ? printf(" not found\n") : printf(" found at index %d\n", re + 1);
    puts(" ");
    puts(" ");
    i = git(data, array);
    bubbleSort(array, i, 0);
    show_array(array, i);
    printf("\n?");
    scanf("%d", &a);
    re = binarySearch(array, a, 0, i - 1, i);
    re == -1 ? printf(" not found\n") : printf(" found at index %d\n", re + 1);

    system("pause");
}
