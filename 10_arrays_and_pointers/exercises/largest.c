// Write a function that returns the largest value stored in an array-of-int. Test the function
// in a simple program.
#include <stdio.h>

int largest(int ar[], int n);

int main(void)
{
    int ar[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    printf("The largest value is %d.\n", largest(ar, 15));

    return 0;
}

int largest(int ar[], int n)
{
    int i, max;
    max = ar[0];
    for (i = 1; i < n; i++)
        max = (max > ar[i] ? max : ar[i]);    
    return max;
}
           
