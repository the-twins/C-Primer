// Generalize the to_binary() function of Listing 9.8 to a to_base_n()function that
// takes a second argument in the range 2-10. It then should print the number that is its
// first argument to the number base given by the second argument. For example, to_
// base_n(129, 8) would display 201, the base-8 equivalent of 129. Test the function in a
// complete program.
#include <stdio.h>

void to_base_n(unsigned long n, int range);

int main(void)
{
    unsigned long number;
    int range;
    printf("Enter an integer and second integer in the range 2-10 (q to quit):\n");
    while (scanf("%lu %d", &number, &range) == 2)
    {
        printf("Equivalent: ");
        to_base_n(number, range);
        putchar('\n');
        printf("Enter an integer and second integer in the range 2-10 (q to quit):\n");
    }
    printf("Done.\n");

    return 0;
}

void to_base_n(unsigned long n, int range)
{
    int r;
    r = n % range;
    if (n >= range)
        to_base_n(n / range, range);
    printf("%d", r);

    return;
}
