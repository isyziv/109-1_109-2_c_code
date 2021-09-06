#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
struct employee
{
	int id;
	char lastName[30];
	char firstName[30];
	char gender[30];
	int age;
	float salary;
}tmp;
struct da
{
	int account;
	char name[30];
	double balance;
	struct da* next;
};
typedef struct da dd;
typedef dd* dat;
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
void in(FILE* data, FILE* save)
{
	if (data == NULL) //err check
	{
		puts("error :(");
		system("pause");
	}
	else
	{
		int s1=0, s5=0;
		float s6=0;
		char d1[30], d2[30], d3[30], d4[30], d5[30], d6[30];
		fscanf(data, "%s %s %s", d4, d2, d3);
		printf("%s %s %s", d4, d2, d3);
		fscanf(data, "%s %s %s", d4, d2, d3);
		printf(" %s %s %s\n", d4, d2, d3);
		fscanf(data, "%s %s %s %s %s %s", d1, d2, d3, d4, d5, d6);
		for (int i=0; !feof(data);)
		{
			printf("%s %s %s %s %s %s\n", d1, d2, d3, d4, d5, d6);
			sprintf(d6, "%d", s1);
			sprintf(d6, "%d", s5);
			sprintf(d6, "%f",s6);
			tmp.id=s1;
			strcpy(tmp.lastName, d2);
			strcpy(tmp.firstName, d3);
			strcpy(tmp.gender, d4);
			tmp.salary=s6;			
			fwrite(&tmp, sizeof(struct employee), 1, save);
			fscanf(data, "%s %s %s %s %s %s", d1, d2, d3, d4, d5, d6);

		}
	}
}
int id; char* lastName; char* firstName; char gender; int age; float salary;
void pull()
{
	dat a1, a2;
	a1 = list;
	a2 = list->next;
	list = a2;
	free(a1);
}
void data_storage(int i, FILE* data_s)
{
	fprintf(data_s, "%d\t", list->account);
	fprintf(data_s, "%s%c\t", list->name, 0);
	fprintf(data_s, "%lf", list->balance);
	fprintf(data_s, "\n");
	pull();
}
void out(FILE* data)
{
	fprintf(data, "Account\tName\tBalance\n");
	for (int i = 0; list != NULL; i++)
	{
		data_storage(i, data);
	}
}
int main(void)
{
	FILE* data;
	FILE* save;
	data = fopen("input.txt", "r");
	save = fopen("employee.dat", "wb");
	in(data,save);
	fclose(data);
	fclose(save);
	/*
	data = fopen("bank_today", "r");
	in(data);
	fclose(data);
	data = fopen("bank_update", "w");
	out(data);
	fclose(data);
	*/
	puts("done");
	system("pause");
	return 0;
}