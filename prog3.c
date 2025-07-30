#include <stdio.h>

int main()
{
    int fahr, cels;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    /* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

    printf("[%12s|%12s]\n", "Farhernheit", "Celsius");
    fahr = lower;
    while (fahr <= upper)
    {
        cels = 5 * (fahr - 32) / 9;
        printf("[%12d|%12d]\n", fahr, cels);
        fahr = fahr + step;
    }

    /* print Celsius-Fahrenheit table
    for cels = 0, 20, ..., 300 */

    printf("\n\n");
    printf("[%12s|%12s]\n", "Celsius", "Farhernheit");
    cels = lower;
    while (cels <= upper)
    {
        fahr = (9 * cels + 160) / 5;
        printf("[%12d|%12d]\n", cels, fahr);
        cels = cels + step;
    }
}