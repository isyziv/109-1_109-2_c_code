#define _CRT_SECURE_NO_WARNINGS
//#include"link_setup.h"
#include"link_list.h"
#include<stdio.h>
#include<stdlib.h>
static link node;
int tmp_var[100];
int z = 0;
int f_r(FILE* data, link node_p)//rd
{
	int i = 0;
	/*
	for (; 1; i++)
	{
		char tmp[15];
		fgets(tmp, 15, data);
		if (feof(data))
		{
			return i;
		}
		insert(&node);
		strcpy(node->data, tmp);
	}
	*/
	return i;
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
int re=f_r(data, node);
	int tmp[3];
	for (int i = 0; i != 3; i++)
	{
		tmp[i] = node->data;
		b_part(&node, 0);
	}
	for (int i = 0; i != 3; i++)
	{
		//a_part(&node, tmp[i]);
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