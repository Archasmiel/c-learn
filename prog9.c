#include <stdio.h>
#define BLANK ' '

int main()
{
    int c, prev;

    for (; (c = getchar()) != EOF; prev = c)
    {
        if (prev == BLANK && c == BLANK) continue;
        putchar(c);
    }
}