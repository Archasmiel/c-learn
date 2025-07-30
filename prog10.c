#include <stdio.h>

int main()
{
    int c;

    for (;(c = getchar()) != EOF;)
    {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
            continue;
        }
        if (c == '\b') {
            putchar('\\');
            putchar('b');
            continue;
        }
        if (c == '\\') {
            putchar('\\');
            putchar('\\');
            continue;
        }
        putchar(c);
    }
}