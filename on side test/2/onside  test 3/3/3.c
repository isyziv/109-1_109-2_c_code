#include <stdio.h>

int main(void)
{
    int x = 10;
    int y = 20;
    fprintf(stderr, "Date :%s \nTime:%s\n", __DATE__, __TIME__);
    return 0;
}