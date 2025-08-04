#include <stdio.h>

#define TAB_SIZE 4
#define TAB_CHAR '\t'
#define MAXLINE 1000

int read_line(char line[], int limit);
int entab(char line[]);
void print_line(char line[]);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = read_line(line, MAXLINE)) >= 0) {
        print_line(line);
        entab(line);
        print_line(line);
    }
}

// Line reading, returns size with newline symbol
int read_line(char line[], int limit) {
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (i < limit - 1) {
            line[i++] = c;
        }
    }

    if (c == '\n' && i < limit-1) {
        line[i++] = c;
    }

    line[i] = '\0';
    return i;
}

// Compress tabs to least ones
int entab(char line[]) {
    char new_line[MAXLINE];
    int i, j, col, spaces, spaces2tab;

    i = j = col = spaces = 0;
    while (line[i] != '\0') {
        if (line[i] == ' ') {
            spaces++;    
        } else {
            while (spaces > 0) {
                spaces2tab = TAB_SIZE - (col % TAB_SIZE);
                if (spaces >= spaces2tab) {
                    new_line[j++] = '\t';
                    col += spaces2tab;
                    spaces -= spaces2tab;
                } else {
                    new_line[j++] = ' ';
                    col++;
                    spaces--;
                }
            }

            new_line[j++] = line[i];
            if (line[i] == '\n') {
                col = 0;
            } else {
                col++;
            }
        }

        i++;
    }

    while (spaces-- > 0) {
        new_line[j++] = ' ';
    }
    new_line[j] = '\0';

    for (i = 0 ; i <= j ; i++) {
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
