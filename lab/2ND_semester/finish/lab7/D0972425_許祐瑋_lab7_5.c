#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct customer
{
	int account_number;
	char name[30];
	double balance;
} tmp[10];

int main(void)
{

	FILE *fp;
	fp = fopen("random.bin", "rb");
	if (fp == NULL)
	{
		printf("error");
	}
	else
	{
		printf("Account\tName\tBalance\n");
		for (int i = 0; i < 10; i++)
		{
			fread(&tmp[i], sizeof(struct customer), 1, fp);
			printf("%d\t%s\t%lf\n", tmp[i].account_number, tmp[i].name, tmp[i].balance);
		}
		fclose(fp);
	}

	system("pause");
	return 0;
}