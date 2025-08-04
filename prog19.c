#include <stdio.h>

#define MAXLINE 1000

int read_line(char line[], int limit);
int is_not_whitespace(int c);
int trim_line(char s[], int len);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = read_line(line, MAXLINE)) >= 0) {
        len = trim_line(line, len);
        if (len > 0 && line[0] != '\n') { 
            printf("trim(size=%d):%s", len, line);
            if (len > 0 && line[len - 1] != '\n') putchar('\n');
        } 
    }
}

// reads line of user input
// maximum MAXLINE symbols
// line is saved as "XXXXXX...\n\0..."
// if full symbols "XXXXXXX...\0", what fits
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

int is_not_whitespace(int c) {
    return !(c == ' ' || c == '\t');
} 

// line trimmer
int trim_line(char s[], int len) {
    int i, j, in_word;

    i = j = in_word = 0;
    while (i < len) {
        if (is_not_whitespace(s[i])) {
            s[j] = s[i];
            j++;
            in_word = 1;
        } else {
            if (in_word) {
                s[j] = s[i];
                j++;
                in_word = 0;
            }
        }
        
        i++;
    }

    if (s[j-1] == ' ') j--;

    s[j] = '\0';
    return j;
}