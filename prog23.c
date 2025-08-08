#include <stdio.h>
#include <string.h>

#define MAXLINE 20

int read_buffer(int start);
int fold(void);

char line[MAXLINE];
int c, i, j;

int main() {
    j = 0;
    while (read_buffer(j)) {
        j = fold();
    }

    if (j > 0) {
        fwrite(line, 1, j, stdout);
    }
}

int read_buffer(int start) {
    i = start;
    while (i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }

    line[i] = '\0';

    return (c != EOF);
}

int fold(void) {
    for (i = MAXLINE-2; i >= 0; i--) {
        if (line[i] == ' ' || line[i] == '\t') {
            break;
        }
    }

    if (i == -1 || i == MAXLINE-2) {
        fwrite(line, 1, MAXLINE-1, stdout);
        i = MAXLINE-1;
    } else {
        i++;
        fwrite(line, 1, i, stdout);
    }
    putchar('\n');

    memmove(line, line+i, MAXLINE-i);

    return MAXLINE-i;
}