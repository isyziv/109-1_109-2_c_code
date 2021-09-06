#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define sum(x , y )(x+y);
int main(void)
{
	int x = 0, y = 0;
	printf("x= ");
	scanf("%d", &x);
	printf("y= ");
	scanf("%d", &y);
	int z = sum(x, y);
	printf("a+b=%d\n",z);
	system("pause");
	return 0;
}
