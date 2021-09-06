#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include"link_list.h"
#define sum(x , y )(x+y);
int tmp_var[100];
int z = 0;
link node;
int all = 0;
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
	all++;
	node->data = var;
	node = insert(node);
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
int main(void)
{
	node = generate_link();
	FILE* data;
	data = fopen("stack.txt", "r");
	f_r(data);
	puts(" ");
	puts("= = =");
	link ptb = node;
	for (int i = 0; i != all; i++)
	{
		ptb = ptb->next;

		printf("%d ", ptb->data);
	}
	puts(" ");
	puts("= = =");
	for (int i = 0; i != 2; i++)
	{
		node=free_head(node);
		printf("%d ", node->data);
		all -- ;
	}


	puts(" ");
	puts("= = =");
	ptb = node;
	for (int i = 0; i != all; i++)
	{
		ptb = ptb->next;

		printf("%d ", ptb->data);
	}
	system("pause");
	return 0;
}

