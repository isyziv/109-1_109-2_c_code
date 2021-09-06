#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct da
{
	int account;
	char name[30];
	double balance;
	struct da *next;
};
typedef struct da dd;
typedef dd *dat;
dat list = NULL;
void push(int c1, char c2[99], double c3, dat check_point)
{
	dat new;
	new = (dat)malloc(sizeof(dd));
	new->account = c1;
	memmove(new->name, c2, 30);
	new->balance = c3;
	new->next = NULL;
	check_point->next = new;
}
void replace(int c1, char c2[99], double c3, dat check_point)
{
	check_point->balance += c3;
}
void list_start(int c1, char c2[99], double c3)
{
	list = (dat)malloc(sizeof(dd));
	list->account = c1;
	list->account = c1;
	memmove(list->name, c2, 30);
	list->balance = c3;
	list->next = NULL;
}
void check(int c1, char c2[99], double c3)
{
	dat check_point;
	check_point = list;
	if (check_point != NULL)
	{
		for (; (check_point->next) != NULL;)
		{
			if (c1 == check_point->account)
			{
				replace(c1, c2, c3, check_point);
				return 0;
			}
			else
			{
				check_point = check_point->next;
			}
		}
		push(c1, c2, c3, check_point);
	}
	else
	{
		list_start(c1, c2, c3);
	}
}
void in(FILE *data)
{
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
			check(c1, c2, c3);
			fscanf(data, "%d", &c1);
			fscanf(data, "%c", d1);
			fgets(c2, 99, data);
			c222 = strlen(c2);
			c22 = c2 + c222 + 2;
			c3 = strtod(c22, NULL);
		}
	}
}
void pull()
{
	dat a1, a2;
	a1 = list;
	a2 = list->next;
	list = a2;
	free(a1);
}
void data_storage(int i, FILE *data_s)
{
	fprintf(data_s, "%d\t", list->account);
	fprintf(data_s, "%s%c\t", list->name, 0);
	fprintf(data_s, "%lf", list->balance);
	fprintf(data_s, "\n");
	pull();
}
void out(FILE *data)
{
	fprintf(data, "Account\tName\tBalance\n");
	for (int i = 0; list != NULL; i++)
	{
		data_storage(i, data);
	}
}
int main(void)
{
	FILE *data;
	data = fopen("bank", "r");
	in(data);
	fclose(data);
	data = fopen("bank_today", "r");
	in(data);
	fclose(data);
	data = fopen("bank_update", "w");
	out(data);
	fclose(data);
	puts("done");
	system("pause");
	return 0;
}