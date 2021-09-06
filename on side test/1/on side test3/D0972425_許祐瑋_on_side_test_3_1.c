#include <stdio.h>
#include <string.h>

int is_palindrome(char *s)
{
    int i, len;

    len = strlen(s);

    for (i = 0; i < (len / 2); i++)
    {
        if (s[i] != s[len - i - 1])
            return 0;
    }

    if (i >= len / 2)
        return 1;
    else
        return 0;
}

int main()
{
    char s[256];

    while (1)
    {
        gets(s);

        if (is_palindrome(s))
            printf("%s is palindrome\n", s);
        else
            printf("%s is not palindrome\n", s);
    }
}