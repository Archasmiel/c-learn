#include <stdio.h>

#define MAXLINE 1000

int read_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    // reading non-zero lines and copying only longest
    max = 0;
    while ((len = read_line(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
    {
        printf("Longest line:\n%s", longest);
    }
    else
    {
        printf("No lines detected.");
    }
}

// Reads line from console, with max limit
// Returns real length of line
int read_line(char s[], int limit)
{
    int c, i;

    for (i = 0; i < limit - 1 && ((c = getchar()) != EOF && c != '\n'); i++)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

// Copying one array to other
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}