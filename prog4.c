#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    int fahr, cels;

    printf("[%12s|%12s]\n", "Farhernheit", "Celsius");
    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
        printf("[%12d|%12.3f]\n", fahr, (5.0 / 9.0) * (fahr - 32));

    printf("\n\n");
    printf("[%12s|%12s]\n", "Celsius", "Farhernheit");
    for (cels = UPPER; cels >= LOWER; cels = cels - STEP)
        printf("[%12d|%12.3f]\n", cels, (9.0 / 5.0) * cels + 32);
}