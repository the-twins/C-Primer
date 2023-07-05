// Devise a function called min(x,y) that returns the smaller of two double values Test
// the function with a simple driver.
#include <stdio.h>

double min(double, double);

int main(void)
{
    double evil1, evil2;

    printf("Enter a pair of integers (q to quit):\n");
    while (scanf("%lf %lf", &evil1, &evil2) == 2)
    {
        printf("The smaller of %.2lf and %.2lf is %.2lf.\n",
            evil1, evil2, min(evil1, evil2));
        printf("Enter a pair of integers (q to quit):\n");
    }
    printf("Bye!\n");

    return 0;
}

double min(double x, double y)
{
    return (x < y) ? x : y;
}
 
