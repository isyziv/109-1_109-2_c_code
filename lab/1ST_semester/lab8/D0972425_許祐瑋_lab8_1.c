#include <stdio.h>
#include <stdlib.h>
void local(void);
void statics(void);
void global(void);
int x = 10;
int main(void)
{
    int x = 15;
    printf("% d\n", x); //15
    {
        int x = 27;
        printf("% d\n", x); //27
    }
    statics();
    local();
    global();
    statics();
    system("pause");
    return 0;
}
void local()
{
    int x = 125;
    printf("% d\n", x); //125
    x--;
    printf("% d\n", x); //124
}
void statics()
{
    static int x = 5;
    printf("% d\n", x); //1st:5     2nd: 6
    x++;
    printf("% d\n", x); //1st:6     2nd: 7
}
void global()
{
    printf("% d\n", x); //10
    x *= 8;
    printf("% d\n", x); //80
}