#include <stdio.h>

#define MAX_WORD_LEN 10
#define HIST_LEN 10
#define HIST_CHAR '*'
#define WS_CHAR ' '
#define VERT_CHAR '|'
#define HORIZ_CHAR '-'

int main()
{
    int c, in_word, word_len;
    int word_lens[MAX_WORD_LEN + 1];
    /* word lengths, [1] is 1-char word, [2] is 2...
        [0] is unused*/

    in_word = word_len = 0;
    for (int i = 1; i <= MAX_WORD_LEN; i++)
    {
        word_lens[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (in_word && word_len <= MAX_WORD_LEN)
            {
                word_lens[word_len]++;
            }
            in_word = 0;
            word_len = 0;
        }
        else
        {
            in_word = 1;
            word_len++;
        }
    }

    // Max word occurencies from all in array
    int max, i;

    max = 0;
    for (int i = 1; i <= MAX_WORD_LEN; i++)
        if (word_lens[i] > max)
            max = word_lens[i];

    // Calculating histogram column lengths
    int hist_sizes[MAX_WORD_LEN + 1];
    for (i = 1; i <= MAX_WORD_LEN; i++)
    {
        hist_sizes[i] = word_lens[i] * HIST_LEN / max;
    }

    // Horizontal histogram
    int l, curr_word_len;
    for (i = 1; i <= MAX_WORD_LEN; i++)
    {
        printf("%3d%c", i, VERT_CHAR);
        curr_word_len = word_lens[i] * HIST_LEN / max;
        for (l = 0; l < curr_word_len; l++)
        {
            printf("%c", HIST_CHAR);
        }
        printf("\n");
    }
    printf("\n\n");

    // Vertical histogram
    for (l = HIST_LEN; l >= 1; l--)
    {
        printf("%c", VERT_CHAR);
        for (i = 1; i <= MAX_WORD_LEN; i++)
        {
            printf("%2c%c", hist_sizes[i] >= l ? HIST_CHAR : WS_CHAR, VERT_CHAR);
        }
        printf("\n");
    }

    putchar(HORIZ_CHAR);
    for (l = 0; l < MAX_WORD_LEN; l++)
    {
        printf("%c%c%c", HORIZ_CHAR, HORIZ_CHAR, HORIZ_CHAR);
    }
    printf("\n");

    putchar(VERT_CHAR);
    for (i = 1; i <= MAX_WORD_LEN; i++)
    {
        printf("%2d%c", i, VERT_CHAR);
    }
    printf('\n');
}