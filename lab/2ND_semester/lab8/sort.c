#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort_printPass(int array[], int length, int pass, int index)
{
	int i;
	printf("After pass %2d: ", pass);
	for (i = 0; i < index; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("%d* ", array[index]);
	for (i = index + 1; i < length; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("%s", "\n               ");
	for (i = 0; i < pass; i++)
	{
		printf("%s", "--  ");
	}
	puts("\n");
}
void swap(int* ptr1, int* ptr2)
{
	int tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
void swap_pre(int array[], int first, int second)
{
	int temp;
	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}
void selectionSort(int array[], int length, int en)
{
	int smallest;
	int i, j;
	for (i = 0; i < length - 1; i++)
	{
		smallest = i;
		for (j = i + 1; j < length; j++)
		{
			if (array[j] < array[smallest])
			{
				smallest = j;
			}
		}
		swap_pre(array, i, smallest);
		if (en)selectionSort_printPass(array, length, i + 1, smallest);
	}
}
void insertionSort_printPass(int array[], int length, int pass, int index)
{
	int i;
	printf("After pass %2d: ", pass);
	for (i = 0; i < index; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("%d* ", array[index]);
	for (i = index + 1; i < length; i++)
	{
		printf("%d  ", array[i]);
	}
	//puts(" ");
	printf("%s ", "\n              ");
	for (i = 0; i <= pass; i++)
	{
		printf("    ");
	}
	if (length - 1 != pass)
	{
		puts("--");
	}

	else
	{
		puts("#");
	}

}
void insertionSort(int array[], int length, int en)
{
	int insert;
	int i;
	for (i = 1; i < length; i++)
	{
		int moveItem = i;
		insert = array[i];
		while (moveItem > 0 && array[moveItem - 1] > insert)
		{
			array[moveItem] = array[moveItem - 1];
			--moveItem;
		}
		array[moveItem] = insert;
		if (en)insertionSort_printPass(array, length, i, moveItem);
	}
}
void out_store_arry(int SIZE, int array[])
{
	puts("Sorted array:");
	for (int i = 0; i < SIZE; i++) /* print the array */
	{
		printf("%d  ", array[i]);
	}
}
void show_array(int array[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d  ", array[i]);
	}
}
void show_array_4(int array[], int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%4d", array[i]);
	}
}
void printRow(const int b[], int low, int mid, int high, int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		if (i < low || i > high)
		{
			printf("%s", "    ");
		}
		else if (i == mid)
		{
			printf("%3d*", b[i]);
		}
		else
		{
			printf("%3d ", b[i]);
		}
	}
	puts("");
}
int binarySearch(const int b[], int searchKey, int low, int high, int SIZE)
{
	// if return =-1 means not find
	while (low <= high)
	{
		int middle = (low + high) / 2;
		printRow(b, low, middle, high, SIZE);
		if (searchKey == b[middle])
		{
			return middle;
		}
		else if (searchKey < b[middle])
		{
			high = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
	}
	return -1;
}
void bubbleSort(int* a, int n, int en)
{
	int i, j, k;
	for (i = n; i > 1; i--)
	{
		for (j = 1; j < i; j++)
		{
			if (a[j - 1] > a[j])
				swap(&a[j - 1], &a[j]);
			if (en)
			{
				printf("a[%d], a[%d]: \t", j - 1, j);
				for (k = 0; k < n; k++) printf("%4d", a[k]);
				printf("\n");
			}
		}
		//printf("****************************************************\n");
	}
}