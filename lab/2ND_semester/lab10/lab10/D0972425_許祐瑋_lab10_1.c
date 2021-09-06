#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define largest(var1, var2) (var1>var2?var1:var2)

int main(void)
{
	int v1, v2, v3=0;
	printf("input a integer");
	scanf("%d", &v1);
	printf("input another integer");
	scanf("%d", &v2);
	v3=largest(v1, v2);
	printf("The larger integer is %d",v3);

	system("pause");
}
