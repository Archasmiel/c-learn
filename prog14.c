#include <stdio.h>

#define ALPHABET_SIZE ('z' - 'a' + 1)
#define HIST_CHAR '#'
#define HIST_SIZE 20
#define HIST_C1 '|'
#define BIG_TO_SMALL ('a' - 'A')

int main()
{
    // init
    int c, i;
    int char_count[ALPHABET_SIZE];

    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        char_count[i] = 0;
    }

    // reading to EOF
    while ((c = getchar()) != EOF)
    {
        if (c >= 'A' && c <= 'Z')
        {
            char_count[c - 'A']++;
        }
        else 
        if (c >= 'a' && c <= 'z')
        {
            char_count[c - 'a']++;
        }
    }

    // max search
    int max = 0;
    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        if (max < char_count[i])
        {
            max = char_count[i];
        }
    }

    // horizontal histogram
    int curr_length, l;
    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        printf("%2c%c%3d%c", (char)('a' + i), HIST_C1, char_count[i], HIST_C1);
        curr_length = char_count[i] * HIST_SIZE / max;
        for (l = 0; l < curr_length; l++)
        {
            putchar(HIST_CHAR);
        }
        printf("\n");
    }
}