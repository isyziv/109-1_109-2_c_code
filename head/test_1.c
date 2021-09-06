#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
struct LINK
{
	int data;
	struct LINK* next;
}LINK_;
typedef struct Link* link;
int sub(link top, int a, int b, int c)
{
	a = top->data;
	top = top->next;
	b = top->data;
	c = a + b;
	return c;
};
int main()
{

	int a = 0, b = 0, c = 0;
	link ll;
	int sub(ll,a,b,c);
}