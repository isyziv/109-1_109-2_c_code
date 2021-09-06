#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void out(FILE *data)
{
	int c1;
	char c2[100], t1[30], t2[30], t3[30];
	double c3;
	if (data == NULL) //err check
	{
		puts("error :(");
		system("pause");
	}
	else
	{
		int c1, c222;
		char c2[99], *c22;
		double c3 = 0;
		char d1[30], d2[30], d3[30];
		fscanf(data, "%s %s %s", d1, d2, d3);
		fscanf(data, "%d", &c1);
		fscanf(data, "%c", d1);
		fgets(c2, 99, data);
		c222 = strlen(c2);
		c22 = c2 + c222 + 2;
		c3 = strtod(c22, NULL);
		for (; !feof(data);)
		{
			printf("%d\t%s\t%lf\n", c1, c2, c3);
			fscanf(data, "%d", &c1);
			fscanf(data, "%c", d1);
			fgets(c2, 99, data);
			c222 = strlen(c2);
			c22 = c2 + c222 + 2;
			c3 = strtod(c22, NULL);
		}
	}
}
int main(void)
{
	FILE *data;
	data = fopen("bank", "r");
	out(data);
	fclose(data);
	system("pause");
	return 0;
}