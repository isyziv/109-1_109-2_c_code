#include <stdio.h>
#include <windows.h>
int main(void)
	{
		int i = 0;
		while( i <= 2 )
		{
			printf("\a");
			Sleep(1000);
			i=i+1;	
		}
	return 0;
	}

