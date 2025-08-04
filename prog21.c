#include <stdio.h>
#define MAXLINE 1000
#define TAB_SIZE 4
#define TAB_CHAR ' '

int read_line(char line[], int limit);
int detab(char line[]);
void print_line(char line[]);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = read_line(line, MAXLINE)) >= 0) {
        print_line(line);
        detab(line);
        print_line(line);
    }
}

// Line reading, returns size with newline symbol
int read_line(char line[], int limit) {
    int c, i = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (i < limit - 1) {
            line[i++] = c;
        }
    }

    if (c == '\n' && i < limit - 1) {
        line[i++] = c;
    }

    line[i] = '\0';
    return i;
}


// Tab replacing, returns new size
int detab(char line[]) {
    char new_line[MAXLINE];
    int i, j, spaces;

    i = j = 0;
    while (line[i] != '\0' && j < MAXLINE-1) {
        if (line[i] == '\t') {
            spaces = TAB_SIZE - (j % TAB_SIZE);
            while (spaces-- > 0 && j < MAXLINE) {
                new_line[j++] = TAB_CHAR;
            }
            i++;
        } else {
            new_line[j++] = line[i++];
        }
    }

    new_line[j] = '\0';
    for (i = 0; i <= j ; i++) {
        line[i] = new_line[i];
    }

    return j;
}

// Printing line with invisible symbols
void print_line(char line[]) {
    int c, i = 0;

    while ((c = line[i]) != '\0') {
        if (c == '\t') {          
            printf("\\t");
        } else if (c == '\n') {
            printf("\\n");
        } else {
            putchar(c);
        }
        i++;
    }

    printf("\\0\n");
}

