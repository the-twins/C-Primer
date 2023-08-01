// Write a program that initializes an array-of-double and then contents of the
// array into three other arrays. (All four arrays should be declared in the main program). To
// make the first copy, use a function with array notation. To make the second copy, use a
// function with pointer notation and pointer incrementing. Have the first two functions
// take as arguments the name of the target array, the name of the source array, and the
// number of elements to be copied. have the third function take as arguments the name
// of the target, the name of the source, and pointer to the element following the last
// element of the source. That is, the function calls would look like this, given the following
// declarations:
// double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
// double target1[5];
// double target2[5];
// double target3[5];
// copy_arr(target1, source, 5);
// copy_ptr(target2, source, 5);
//
// copy_ptrs(target3, source, source + 5);
#include <stdio.h>

void copy_arr(double target1[], double source[], int n);
void copy_ptr(double *target2, double *source, int n);
void copy_ptrs(double target3[], double source[], double * end);

int main (void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    printf("The target1 array after calling copy_arr():\n");
    copy_arr(target1, source, 5);
    printf("The target2 array after calling copy_ptr():\n");
    copy_ptr(target2, source, 5);
    printf("The target3 array after calling copy_ptrs():\n");
    copy_ptrs(target3, source, source + 5);

    return 0;
}

void copy_arr(double target1[], double source[], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
    {
	target1[i] = source[i];
        printf("%.2lf ", target1[i]);
    }
    printf("\n");
}

void copy_ptr(double *target2, double *source, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
	*(target2 + i) = *(source + i);
        printf("%.2lf ", target2[i]);
    }
    printf("\n");
}  

void copy_ptrs(double target3[], double source[], double *end)
{
    for (; source < end; target3++, source++)
    {
        *target3 = *source;
        printf("%.2lf ", *target3);
    }
    printf("\n");
}

