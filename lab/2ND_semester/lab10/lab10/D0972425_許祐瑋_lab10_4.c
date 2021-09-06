#include <stdio.h>
#include <stdlib.h>
#define PRINTF(fmt, ...) { \
    printf( fmt"\n"); \
}
int main(void)
{
	PRINTF("hello");
	system("pause");
	return 0;
}
