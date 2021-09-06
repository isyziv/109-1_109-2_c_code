#include <stdio.h>
#include <stdlib.h>
void swap(int *ptr1, int *ptr2)
{
	int tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

void bubbleSort(int *a, int n)
{
	int i, j, k;
	for (i = n; i > 1; i--)
	{
		for (j = 1; j < i; j++)
		{
			if (a[j - 1] > a[j])
				swap(&a[j - 1], &a[j]);
			printf("a[%d], a[%d]: ", j - 1, j);
			for (k = 0; k < n; k++)
				printf("%4d", a[k]);
			printf("\n");
		}
		printf("****************************************************\n");
	}
}

int main()
{
	int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int i;

	bubbleSort(data, 10);
	printf("\n\nThe sorted sequence: ");
	for (i = 0; i < 10; i++)
	{
		printf("%4d", data[i]);
	}
	printf("\n");

	system("pause");
}
