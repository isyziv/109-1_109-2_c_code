#define _CRT_SECURE_NO_WARNINGS
//#include"link_setup.h"
#include"link_list.h"
#include<stdio.h>
#include<stdlib.h>
static link node;
int tmp_var[100];
int z = 0;
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
	node->data = var;
	insert(node, var);

}
void f_r(FILE* data)//rd
{
	for (int i = 0; 1; i++)
	{
		char tmp[2];
		fread(tmp, 2, 1, data);
		if (feof(data))
		{
			return 1;
		}

		record(tmp, i);
		fread(tmp, 1, 1, data);
	}
}
void a_part(link node, char a[15])//ins data
{
	insert(&node);
	strcpy(node->data, a);
}
void b_part(link* node, int a)
{

	node = free_head(node);
}
void c_part(link* node, int a)
{

	node = free_head(node);
}



int main()
{
	FILE* data;
	node = generate_link();
	node->data = 0;
	node->next = NULL;
	data = fopen("stack.txt", "r");
	f_r(data, node);
	int tmp[3];
	for (int i = 0; i != 3; i++)
	{
		tmp[i] = node->data;
		b_part(&node, 0);
	}
	for (int i = 0; i != 3; i++)
	{
		a_part(&node, tmp[i]);
	}
	puts(" ");
	int stack[100];
	int j = 0;
	for (; node->next!=NULL; j++)
	{
		stack[j] = node->data;
		b_part(&node, 0);
	}
	j--;
	for (;j>=0; j--)
	{
		printf("%d\t", stack[j]);
	}
	system("pause");
	return 0;
}
// !feof(data)