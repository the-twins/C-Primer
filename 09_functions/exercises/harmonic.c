// The harmonic mean of two numbers is obtained by taking the inverses of two 
// numbers, averaging them, and taking the inverse of the result. Write a function that
// takes two double arguments and returns the harmonic mean of the two numbers.
#include <stdio.h>

double harmonic(double, double);

int main(void)
{
    double one, two;
    printf("Enter two numbers to get the harmonic mean (q to quit):\n");
    while (scanf("%lf %lf", &one, &two) == 2)
        printf("%.2lf is harmonic mean. Try again (q to quit).\n", harmonic(one, two));
    printf("Bye!\n");

    return 0;
}

double harmonic(double one, double two)
{
    double mean;
    mean = 2 / (1 / one + 1/ two);
    return mean;
}
