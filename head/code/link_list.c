//#include "link_setup.h"
#include "link_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
//extern void link_setup();
link generate_link()
{
	link new;
	new = (link)malloc(sizeof(LINK_));
	return new;
}
link insert(link top)
{
//add data before node
	link new;
	new = (link)malloc(sizeof(LINK_));
	new->next = top;
	top = new;
	return new;
}
link append(link last)
{
//add new data on the last node
//tip : you shiuld use find_last()
	link new;
	new = (link)malloc(sizeof(LINK_));
	last->data = new;
	new->next = NULL;
	return new;
}
link free_head(link top)
{
	//delete first node memory
	//waring data will be delete
	//you should save data before use this function
	link del;
	del = top;
	top = top->next;
	free(del);
	return top;
}
link find_last(link top)
{
	//find last data , return last data address
	//find the last node
	link last;
	last = (link)malloc(sizeof(LINK_));
	last = top;
	for (; last->next == NULL || last == NULL;last = last->next)
	{	}
	return last;
}
//pr
//find last n
//
