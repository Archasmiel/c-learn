#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_length(char *s);
char *merge(char *a, char *b);
int get_line(char **res);
void print_str(char *s);
char *str_dup(char *s);

int main()
{
    int len, maxlen;
    char *line;
    char *maxline;

    line = maxline = NULL;
    maxlen = 0;
    while ((len = get_line(&line)) > 0) {
        if (maxlen < len) {
            free(maxline);
            maxline = str_dup(line);
            maxlen = len;
        }
        free(line);
        line = NULL;
    }

    if (maxlen > 0) {
        printf("\nLength: %d\nLine: ", maxlen);
        print_str(maxline); // escaped output
        printf("\n");
    } else {
        printf("0\n");
    }

    free(maxline);
}

int str_length(char *s)
{
    int len;

    len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    return len;
}

char *merge(char *a, char *b) {
    size_t len_a = a ? strlen(a) : 0;
    size_t len_b = strlen(b);
    char *res = malloc(len_a + len_b + 1);
    if (!res) return NULL;

    if (a) strcpy(res, a);
    else res[0] = '\0';

    strcat(res, b);

    free(a);
    return res;
}

void print_str(char *s)
{
    int c, i = 0;

    while ((c = s[i]) != '\0') {
        if (c == '\n') printf("\\n");
        else if (c == '\t') printf("\\t");
        else if (c == '\\') printf("\\\\");
        else printf("%c", c);
        i++;
    }

    printf("\\0");
}

int get_line(char **s_out) {
    int c, i = 0, len = 0;
    char *res = NULL;
    char buffer[256];

    while ((c = getchar()) != '\n' && c != EOF) {
        if (i == 255) {
            buffer[i] = '\0';
            res = merge(res, buffer);
            i = 0;
        }
        buffer[i++] = c;
        len++;
    }

    buffer[i] = '\0';
    res = merge(res, buffer);

    if (!res) {
        res = malloc(1);
        if (res) res[0] = '\0';
    }

    *s_out = res;
    return len;
}

char *str_dup(char *s) {
    int len = str_length(s);
    char *copy = malloc(len + 1);
    if (copy) strcpy(copy, s);
    return copy;
}