// Redo Programming Exercise 8, but this time use recursive function.
#include <stdio.h>

double repower(double n, int p);

int main(void)
{
    double x; 
    int exp;

    printf("Enter a number and the integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf("%lf %d", &x, &exp) == 2)
    {
        printf("%.3g to the power %d is %.5g\n", x, exp, repower(x, exp));
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");

    return 0;
}

double repower(double n, int p)
{
    double pow = 1;
    if (p >= 1)
	pow = n * repower(n, p - 1);
    if (p < 0)
	pow = 1 / n * repower(n, p + 1);
    return pow;
}
