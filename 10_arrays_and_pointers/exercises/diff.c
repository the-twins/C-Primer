// Write a function that returns the difference between the largest and smallest elements of
// an array_of_double. Test the function in a simple program.
#include <stdio.h>

double diff(double ar[], int n);

int main(void)
{
    double ar[10] = {1.1, 6.7, 2.7, 5.6, 3.5, 9.9, 4.4, 7.2, 5.6, 0.3};
    printf("The difference between the largest and smallest elements is %.2lf.\n", diff(ar, 10));

    return 0;
}

double diff(double ar[], int n)
{
    int i;
    double max, min;
    for (i = 1, max = ar[0]; i < n; i++)
        max = (max > ar[i] ? max : ar[i]);
    for (i = 1, min = ar[0]; i < n; i++)
        min = (min < ar[i] ? min : ar[i]);

    return max - min;
}
