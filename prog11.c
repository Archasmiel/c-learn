#include <stdio.h>

int main()
{
    int c, nl, nw, nc;
    int in_word;

    in_word = 0;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            nl++;

        if (c == ' ' || c == '\n' || c == '\t') {
            if (in_word) {
                putchar('\'');
                putchar('\n');
            }
            in_word = 0;
        } else {
            if (!in_word) {
                nw++;
                putchar('\'');
            }
            putchar(c);
            in_word = 1;
        }
    }

    if (in_word) {
        putchar('\'');
        putchar('\n');
    }

    printf("Chars:%3d\nLines:%3d\nWords:%3d\n", nc, nl, nw);
}