#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SUMMARY(x,y)(x[0]+x[1]);
int tmp_var[100];
int z = 0;
int add = 0;
int add_t;
void record(char tmp[2], int i)
{
	tmp[0] -= 48;
	tmp[1] -= 48;
	int var = 0;
	if (tmp[0] > 0 && tmp[0] <= 9)
	{
		var = tmp[0];
		var *= 10;
	}
	else
	{
		var = 0;
	}
	var += tmp[1];
	tmp_var[z] = var;
	z++;
	printf("%d ", var);
	int x[2];
	x[0]=add;
	x[1]=var;
	add_t = SUMMARY(x,2);
	add = add_t;
}
void f_r(FILE* data)//rd
{
	for (int i = 0; 1; i++)
	{
		char tmp[2];
		fread(tmp, 2, 1, data);
		if (feof(data))
		{
			break;
		}
		record(tmp, i);
		fread(tmp, 1, 1, data);
	}
}
int main(void)
{
	FILE* data;
	data = fopen("array.txt","r");
	f_r(data);
	printf("\n%d", add);

	system("pause");
	return 0;
}
//709
