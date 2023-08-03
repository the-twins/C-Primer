// Write a function that returns the index of the largest value strored in an array_of_double.
// Test the function in a simple program.
#include <stdio.h>

int ind(double ar[], int n);

int main(void)
{
    double ar[10] = {1.1, 2.2, 3.3, 4.0, 5.5, 10.0, 6.8, 7.9, 8.8, 9.9};
    printf("The index of the largest value is %d.\n", ind(ar, 10));

    return 0;
}

int ind(double ar[], int n)
{
    int i;
    int imax; 

    for (i = 1, imax = 0; i < n; i++)
        imax = (ar[imax] > ar[i] ? imax : i);

    return imax;
}
