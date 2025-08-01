#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

float fahr2cels_f(float fahr);
int fahr2cels_i(int fahr);

float cels2fahr_f(float cels);
int cels2fahr_i(int cels);

int main()
{
    int fahr, cels;

    printf("[%12s|%12s]\n", "Farhernheit", "Celsius");
    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
        printf("[%12d|%12.3f]\n", fahr, fahr2cels_f(fahr));

    printf("\n\n");
    printf("[%12s|%12s]\n", "Celsius", "Farhernheit");
    for (cels = UPPER; cels >= LOWER; cels = cels - STEP)
        printf("[%12d|%12.3f]\n", cels, cels2fahr_f(cels));
}

float fahr2cels_f(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32);
}
int fahr2cels_i(int fahr)
{
    return 5 * (fahr - 32) / 9;
}

float cels2fahr_f(float cels)
{
    return (9.0 / 5.0) * cels + 32.f;
}
int cels2fahr_i(int cels)
{
    return 9 * cels / 5 + 32;
}