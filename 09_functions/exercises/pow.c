// Chapter 6, "C Control Statements: Looping", (Listing 6.20) shows a power() function that
// returned the result of raising a type double number to positive integer value.
// Improve the function so that it correctly handles negative powers. Also, build into the
// function that 0 to any power other than 0 is 0 and that any number to the 0 power is 1.
// (It should report that 0 to the 0 is undefined, that say it's using a value of 1.) Use a loop.
// Test the function in a program.
#include <stdio.h>

double power(double n, int p);

int main(void)
{
    double x; 
    int exp;

    printf("Enter a number and the integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf("%lf %d", &x, &exp) == 2)
    {
        printf("%.3g to the power %d is %.5g\n", x, exp, power(x, exp));
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");

    return 0;
}

double power(double n, int p)
{
    double pow = 1;
    int i;
    if (p >= 1)
    {
        for (i = 1; i <= p; i++)
	    pow *= n;
    }
    if (p < 0)
    {
        for (i = -1; i >= p; i--)
	    pow /= n;
    }
    return pow;
}
