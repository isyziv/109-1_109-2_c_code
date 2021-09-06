#include <stdio.h>

int main(void)
{
    int x = 10;
    int y = 20;

    fprintf(stderr, "FILE :%s\nLINE : %d\nDate :%s \nTime:%s\n", __FILE__, __LINE__, __DATE__, __TIME__);
    return 0;
}