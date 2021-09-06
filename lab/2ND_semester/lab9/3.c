#define _CRT_SECURE_NO_WARNINGS
#include"link_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
tree node;
tree ptr;
link list;
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
	insert_tree(node, var);
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
void del(int judge)
{
	tree tmp_root = NULL;
	int tmp_act = -1;
	tree tmp = NULL;
	tmp = node;
	for (; tmp->var != judge;)
	{
		if (tmp->var > judge)
		{
			tmp_root = tmp;
			tmp = tmp->lptr;
			tmp_act = 0;//targect on the left
		}
		if (tmp->var < judge)
		{
			tmp_root = tmp;
			tmp = tmp->rptr;
			tmp_act = 1;//targect on the  right
		}
	}
	if (tmp_root == NULL)
	{
		if (tmp->lptr == NULL && tmp->rptr == NULL)
		{
			if (tmp_act)
			{
				tmp_root->rptr = NULL;
			}
			else
			{
				tmp_root->lptr = NULL;
			}
		}
		else if (tmp->lptr != NULL && tmp->rptr == NULL)
		{
			if (tmp_act)
			{
				tmp_root->rptr = tmp->lptr;
			}
			else
			{
				tmp_root->lptr = tmp->lptr;
			}
		}
		else if (tmp->lptr == NULL && tmp->rptr != NULL)
		{
			if (tmp_act)
			{
				tmp_root->rptr = tmp->rptr;
			}
			else
			{
				tmp_root->lptr = tmp->rptr;
			}
		}
		else if (tmp->lptr != NULL && tmp->rptr != NULL)
		{
			tree tmp_tmp;
			tmp_tmp = tmp->rptr;
			tmp_root = tmp_tmp;
			for (; tmp_tmp->lptr != NULL;)
			{
				tmp_tmp = tmp_tmp->lptr;
			}
			tmp_tmp->lptr = tmp->lptr;
			node = tmp_root;
		}
	}
	else if (tmp->lptr == NULL && tmp->rptr == NULL)
	{
		if (tmp_act)
		{
			tmp_root->rptr = NULL;
		}
		else
		{
			tmp_root->lptr = NULL;
		}
	}
	else if (tmp->lptr != NULL && tmp->rptr == NULL)
	{
		if (tmp_act)
		{
			tmp_root->rptr = tmp->lptr;
		}
		else
		{
			tmp_root->lptr = tmp->lptr;
		}
	}
	else if (tmp->lptr == NULL && tmp->rptr != NULL)
	{
		if (tmp_act)
		{
			tmp_root->rptr = tmp->rptr;
		}
		else
		{
			tmp_root->lptr = tmp->rptr;
		}
	}
	else if (tmp->lptr != NULL && tmp->rptr != NULL)
	{
		tree tmp_tmp;
		tmp_tmp = tmp->rptr;
		for (; tmp_tmp->lptr != NULL;)
		{
			tmp_tmp = tmp_tmp->lptr;
		}
		tmp_tmp->lptr = tmp->lptr;
		if (tmp_act)
		{
			tmp_root->rptr = tmp->rptr;
		}
		else
		{
			tmp_root->lptr = tmp->rptr;
		}
	}
}
int main()
{
	srand(time(NULL));
	FILE* data;
	data = fopen("binary_tree.txt", "r");
	node = generate_link();
	node->var = -1;
	node->lptr = NULL;
	node->rptr = NULL;
	srand(time(NULL));
	f_r(data);
	puts("\n= = = = = = = = = = = = = = = = = = = = =");
	puts("II");
	puts("\npreorder\n");
	preOrder(node);
	puts("\ninorder\n");
	inOrder(node);
	puts("\npostorder\n");
	postOrder(node);
	puts("\n= = = = = = = = = = = = = = = = = = = = =");
	puts("III");
	int y = rand() % (z - 1);
	int pri = tmp_var[y];
	printf("delete %d\n", pri);
	del(pri);
	puts("\n= = = = = = = = = = = = = = = = = = = = =");
	puts("IV");
	puts("\npreorder\n");
	preOrder(node);
	puts("\ninorder\n");
	inOrder(node);
	puts("\npostorder\n");
	postOrder(node);
	system("pause");
	return 0;
}