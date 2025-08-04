#include <stdio.h>

#define MAXLINE 1000

int read_line(char s[], int limit);
int trim_line(char s[], int len);
int is_not_whitespace(int c);
void reverse(char s[], int len);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = read_line(line, MAXLINE)) > 0) {
        len = trim_line(line, len);
        if (len > 0 && line[0] != '\n') { 
            reverse(line, len);
            printf("reverse+trim(size=%d):%s", len, line);
            if (len > 0 && line[len - 1] != '\n') putchar('\n');
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

int is_not_whitespace(int c) {
    return !(c == ' ' || c == '\t');
} 

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

void reverse(char s[], int len) {
    int i, c;
    int end = (len > 0 && s[len - 1] == '\n') ? len - 1 : len;

    for (i = 0; i < end / 2; i++) {
        c = s[i];
        s[i] = s[end - 1 - i];
        s[end - 1 - i] = c;
    }
}
