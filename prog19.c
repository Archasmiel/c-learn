#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int limit);
int trim_line(char s[], int len);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) >= 0) {
        len = trim_line(line, len);
        if (len > 0 && line[0] != '\n') { 
            printf("trim(size=%d):%s", len, line);
            if (len > 0 && line[len - 1] != '\n') putchar('\n');
        } 
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
        i++;
        len++;
    }

    s[i] = '\0';
    printf("%3d\n", len);
    return len;
}

int trim_line(char s[], int len) {
    int i = len-1;
    int had_nl = (s[i] == '\n');    
    
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        len--;
        i--;
    }

    if (len == 0) {
        return 0;
    } 

    if (had_nl) { 
        s[i+1] = '\n';
        i++;
    }
    s[i+1] = '\0';
    return len;
}