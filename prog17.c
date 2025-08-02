#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("Longest line (size=%d):\n%s", max, longest);
    } else {
        printf("No lines detected.");
    }
}

int get_line(char s[], int limit) {
    int c, i, len;

    i = len = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (i < limit-1) {
            s[i] = c;
            i++;
        }
        len++;
    }

    if (i < limit-1 && c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return len;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}