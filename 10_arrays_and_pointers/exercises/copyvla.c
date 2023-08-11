// Write a program that initializes a two-dimensional 3x5 array-of-double and uses a VLA-
// based function to copy it to a second two-dimensional array. Also provide a VLA-based
// function to display the contents of the two arrays. The two functions should be capable,
// in general, of processing arbitrary NxM arrays. (If you don't have access to a VLA-capable
// compiler, use the traditional C approach of functions that can process an Nx5 array).
#include <stdio.h>

#define ROWS 3
#define COLS 5

void copy_arr(int r, int c, double target[r][c], double arr[r][c]);
void print(int r, int c, double array[r][c]);

int main(void)
{
    double arr[ROWS][COLS] = {{1.1, 2.2, 3.3, 4.4, 5.5},
	                     {4.4, 5.5, 6.6, 7.7, 8.8},
			     {7.7, 8.8, 9.9, 1.3, 4.5}};
    double target[ROWS][COLS];

    printf("The arr array contains values:\n");
    print(ROWS, COLS, arr);
    printf("The target array after calling copy_arr():\n");
    copy_arr(ROWS, COLS, target, arr);
    print(ROWS, COLS, target);

    return 0;
}

void copy_arr(int r, int c, double target[r][c], double arr[r][c])
{
    int i, j;

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            target[i][j] = arr[i][j];
}

void print(int r, int c, double array[r][c])
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%.2lf ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}
