#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define sum(x , y )(((x+y)==13)?1:0);
int main(void)
{
	int x=0, y=0;
	printf("x= ");
	scanf("%d",&x);
	printf("y= ");
	scanf("%d", &y);
	int z = sum(x, y);
	(z==1)?printf("a+b=13\n"): printf("a+b!=13\n");
	system("pause");
	return 0;
}
