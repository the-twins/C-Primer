// Write a function called transform() that takes four arguments: the name of a source
// array containing type double data, the name of target array of type double, an int
// representing the number of array elements, and the name of a function (or, equivalently,
// a pointer to a function). The transform() function should apply the indicated function
// to each element in the source array, placing the return value in the target array. For
// example, the call
// transform(source, target, 100, sin);
// would set target[0] to sin(source[0]), and so on, for 100 elements. Test the function
// in a program that call transform() four times, using two functions from the math.h
// library ans two suitable functions of your own devising as arguments to successive calls
// of the transform() function.
#include <stdio.h>
#include <math.h>
#include <string.h>

void transform(double source[], double target[], int n, double(*fp)(double i));
double square(double i);
double cube(double i);

int main(void)
{
    int j;
    double source[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                          21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
                          39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56,
                          57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
                          75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,89, 90, 91, 92,
                          93, 94, 95, 96, 97, 98, 99, 100};
    double target[100];
    double(*fp[4])(double) = {sin, cos, square, cube};
    for(j = 0; j < 4; j++)
    {
        transform(source, target, 100, *fp[j]);
        printf("\n");
        printf("______________________________________________________________________________\n");
    }

    return 0;
}

double square(double i)
{
    return i * i;
}

double cube(double i)
{
    return i * i * i;
}

void transform(double source[], double target[], int n, double(*fp)(double i))
{
    int j;
    for(j = 0; j < n; j++)
    {
        target[j] = (*fp)(source[j]);
        printf("%.2lf ", target[j]);
    }
}
