// Write a program that declares a 3x5 array of int and initializes it to some values of
// your choice. Have the program print the values, double all the values, and then display
// the new values. Write a function to do the displaying and a second function to do the
// doubling. Have the functions take the array name and the number of rows as arguments.
#include <stdio.h>

#define ROWS 3
#define COLS 5
#define NUMB 2

void doub(int arr[][COLS], int n);
void print(int arr[][COLS], int n);

int main(void)
{
    int arr[ROWS][COLS] = {{1,2,3,4,5}, {6,7,8,9,4}, {4,6,7,3,6}};

    printf("The original arr array:\n");
    print(arr, ROWS);
    doub(arr, ROWS);
    printf("The arr array after calling doub():\n");
    print(arr, ROWS);

    return 0;
}

void doub(int arr[][COLS], int n)
{
    int i, j;

    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLS; j++)
            arr[i][j] *= NUMB;
}

void print(int arr[][COLS], int n)
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}
        

