#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

enum State {
    NORMAL,
    IN_SL_COMMENT,
    IN_ML_COMMENT,
    IN_STRING,
    IN_CHAR
};

int c, i, j, symbol;
char buffer[MAXLINE];
enum State state;

FILE* in;
FILE* out;

int read_buffer(void);
void uncomment(void);



int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.c> <output.c>\n", argv[0]);
        return 1;
    }

    in = fopen(argv[1], "r");
    if (!in) {
        perror("Failed to open input file");
        return 1;
    }

    out = fopen(argv[2], "w");
    if (!out) {
        perror("Failed to open output file");
        fclose(in);
        return 1;
    }

    state = NORMAL;
    while (read_buffer()) {
        uncomment();
    }

    if (state == IN_SL_COMMENT) {
        fputc('\n', out);
    }

    fclose(in);
    fclose(out);
    return 0;
}

int read_buffer(void) {
    j = 0;
    while (j < MAXLINE-1 && (c = fgetc(in)) != EOF) {
        buffer[j++] = c;
        if (c == '\n') break;
    }

    buffer[j] = '\0';
    return (c != EOF);
}

void uncomment(void) {
    i = 0;
    while ((c = buffer[i]) != '\0') {
        if (state == NORMAL) {
            if (c == '/') {
                if (i+1 < j && buffer[i+1] == '/') {
                    state = IN_SL_COMMENT;
                    i++;
                } else 
                if (i+1 < j && buffer[i+1] == '*') {
                    state = IN_ML_COMMENT;
                    i++;
                } else {
                    fputc(c, out);
                }
            } else
            if (c == '"') {
                fputc(c, out);
                state = IN_STRING;
            } else
            if (c == '\'') {
                fputc(c, out);
                state = IN_CHAR;
            } else {
                fputc(c, out);
            }
        } 

        else if (state == IN_SL_COMMENT) {
            if (c == '\n') {
                fputc(c, out);
                state = NORMAL;
            }
        } 

        else if (state == IN_ML_COMMENT) {
            if (c == '*' && i+1 < j && buffer[i+1] == '/') {
                state = NORMAL;
                i++;
            }
        } 
        
        else if (state == IN_STRING) {
            fputc(c, out);
            if (c == '\\') {
                i++;
                if (i < j) fputc(buffer[i], out);
            } else if (c == '"') {
                state = NORMAL;
            }
        } 

        else if (state == IN_CHAR) {
            fputc(c, out);
            if (c == '\\') {
                i++;
                if (i < j) fputc(buffer[i], out);
            } else if (c == '\'') {
                state = NORMAL;
            }
        }
        i++;
    }
}