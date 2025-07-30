#include <stdio.h>

int main()
{
    int c;
    int nl, bl, tb;

    nl = bl = tb = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ') bl++;
        if (c == '\t') tb++;
        if (c == '\n') nl++;  
    }

    printf("Blanks:%3d\n", bl);
    printf("Tabs:%3d\n", tb);
    printf("NewLines:%3d\n", nl);
}