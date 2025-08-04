#include <stdio.h>

#define MAXLINE 1000

int read_line(char line[], int limit);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = read_line(line, MAXLINE)) > 0) {
        if (len > 80) {
            printf("Bigger than 80 char:%s", line);
            if (line[len - 1] != '\n') putchar('\n');
        }
    }
}

int read_line(char s[], int limit) {
    int c, len, i;

    len = i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (i < limit - 1)
            s[i++] = c;
        len++;
    }

    if (c == '\n') {
        if (i < limit-1)
            s[i++] = c;
        len++;
    }

    s[i] = '\0';
    return len;
}