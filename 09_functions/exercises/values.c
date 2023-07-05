// Write and test a function that takes the addresses of three double variables as arguments
// and that moves the value of the smallest variable into the first variable, the middle value
// to the second variable, and the largest value into the third variable.
#include <stdio.h>

void values(double * first, double * second, double * third);
void change(double * a, double * b);

int main(void)
{
    double first, second, third;
    printf("Enter three values:\n");
    while (scanf("%lf %lf %lf", &first, &second, &third) == 3)
    {
        values(&first, &second, &third);
        printf("The smallest value is %.2lf, the middle value is %.2lf and the largest is %.2lf.\n",
		first, second, third);
        printf("Try again (q to quit).\n");
    }
    printf("Bye!\n");

    return 0;
}

void values(double * first, double * second, double * third)
{
    if(*first > *second)
        change(first, second);
    if(*second > *third)
	change(second, third);
    if(*first > *second)
	change(first, second);
}

void change(double * a, double * b)
{
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
