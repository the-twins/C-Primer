// Use a copy function from Programming Exercise 2 to copy the third through fifth
// elements of a seven-element array into a three-element array. The function itself need
// not be altered; just choose the right actual arguments. (The arguments need not be
// an array name and array size. They only have to be address of an array element and a
// number of elements to be processed.)
#include <stdio.h>

#define INDEX 7
#define INDEX2 3

void copy_arr(double target1[], double source[], int n);
void print(double target1[], int n);

int main(void)
{
    double source[INDEX] = {1.2, 2.4, 3.4, 4.5, 5.7, 6.5, 7.3};
    double target1[INDEX2];
    printf("The target1 array after calling copy_arr():\n");
    copy_arr(target1, &source[2], INDEX2);
    print(target1, INDEX2);

    return 0;
}

void copy_arr(double target1[], double source[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        target1[i] = source[i];
}

void print(double target1[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%.2lf ", target1[i]);
    printf("\n");
}
