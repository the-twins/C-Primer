// Write a program that initializes a two-dimensional array_of_double and uses one of the
// copy functions from exercise 2 to copy it to a second two-dimensional array. (Because a
// two-dimensional array is an array of arrays, a one-dimensional copy function can be used
// with each subarray.)
#include <stdio.h>

#define ROWS 2
#define COLS 3

void copy_arr(double target1[], double source[], int n);
void print(int r, int c, double target1[r][c]);

int main(void)
{
    double source[ROWS][COLS] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}};
    double target1[ROWS][COLS];
    int i;

    printf("The target1 array after calling copy_arr():\n");
    for (i = 0; i < ROWS; i++)
        copy_arr(target1[i], source[i], COLS);
    print(ROWS, COLS, target1);

    return 0;
}

void copy_arr(double target1[], double source[], int n)
{
    int i;

    for(i = 0; i < n; i++)
            target1[i] = source[i];
}

void print(int r, int c, double target1[r][c])
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
	    printf("%.2lf ", target1[i][j]);
	printf("\n");
    }
    printf("\n");
}
