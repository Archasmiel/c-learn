#include <stdio.h>

int main() 
{
    int c;
    printf("%d %c", EOF, EOF);

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}