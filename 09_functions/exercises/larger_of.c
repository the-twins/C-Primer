// Write and test a function called larger_of() that replaces the contents of two double
// variables with the maximum of the two values. For examle, larger_of(x,y) would
// reset both x and y to larger of the two.
#include <stdio.h>

void larger_of(double * u, double * v);

int main(void)
{
    double x, y;
    printf("Enter two numbers (q to quit):\n"); 
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        printf("Originally x = %.2lf and y = %.2lf.\n", x,y);
        larger_of(&x, &y);
        printf("Now x = %.2lf and y = %.2lf.\n", x, y);
        printf("Try again (q to quit).\n");
    }
    printf("Bye!\n");

    return 0;
}

void larger_of(double * u, double * v)
{
    double temp;
    temp = (*u > *v ? *u : *v);
    *u = temp;
    *v = temp;
}
