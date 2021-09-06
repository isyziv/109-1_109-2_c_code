#include <stdio.h>
#include <stdlib.h>
void mys1(char *s1, const char *s2)
{
    while (*s1 != '\0')
    {
        s1++;
    }
    for (; *s1 == *s2; s1++, s2++)
    {
    }
    puts(" ");
}
int mys2(const char *s)
{
    int x;
    for (x = 0; *s != '\0'; s++)
    {
        x++;
    }
    return x;
}
int main(void)
{
    char s1 = 'a', s2 = 'b';
    mys1(&s1, &s2);
    int i = mys2(&s1);
    puts(" ");
    system("pause");
    return 0;
}
//nmys1:將傳入的兩段字串合併並存在第一段字串
//mys2:算出並傳回傳入的字串長度