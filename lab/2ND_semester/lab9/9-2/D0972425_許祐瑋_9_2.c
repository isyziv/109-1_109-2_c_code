#define _CRT_SECURE_NO_WARNINGS
//#include"link_setup.h"
#include"link_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
static link node;
void a_part(link node, char a[15])//ins data
{
	insert(&node);
	strcpy(node->string, a);
}
void b_part(link ptr)
{
	for (; ptr->next != NULL;)
	{
		puts(ptr->string);
		ptr = ptr->next;
	}
}
void c_part(link ptr,int i)
{
	i++;
	link ptr_1;
	link ptr_2;
	ptr_1 = node;
	ptr_2 = node;
	for (;i!=0;i--)
	{
		ptr_2 = ptr_1;
		ptr_1 = ptr_1->next;
	}
	puts(ptr_1->string);
	ptr_2->next = ptr_1->next;
	free (ptr_1);
}
int f_r(FILE* data, link node_p)//rd
{
	int i = 0;
		for (; 1; i++)
		{
			char tmp[15];
			fgets(tmp, 15, data);
			if (feof(data))
			{
				return i;
			}
			insert(&node);
			strcpy(node->string, tmp);
		}
	return i;
}
int main()
{
	srand(time(NULL));
	FILE* data;
	node = generate_link();
	node->next = NULL;
	data = fopen("linked_list.txt", "r");
	if (data == NULL)
	{
		puts("opps :(");
		return 1;
	}
	int var = f_r(data, node);
	puts("= = = = = = = = = = = = = = = = = = = = =");
	puts("II");
	b_part(node);
	puts("= = = = = = = = = = = = = = = = = = = = =");
	puts("III");
	int ra = (rand() % (var--));
	c_part(node,ra);
	puts("= = = = = = = = = = = = = = = = = = = = =");
	puts("IV");
	b_part(node);
	system("pause");
	return 0;
}