// Write a program that prompts the user to enter three sets of five double numbers each.
// (You may assume the user responds correctly and doesn't enter non-numeric data.) The
// program should accomplish all of the following:
// a. Store the information in a 3x5 array.
// b. Compute the average of each set of five values.
// c. Compute the average of all the values.
// d. Determine the largest value of the 15 values.
// e. Report the results.
// Each major task should be handled by a separate function using the traditional C
// approach to handling attays. Accomplish task 'b' by using a function that computes
// and returns the average of a one-dimensional array; use a loop to call this function three
// times. The other tasks should take the entire array as an argument, and the functions
// performing tasks 'c' and 'd' should return the answert to the calling program.
#include <stdio.h>

#define ROWS 3
#define COLS 5

void arr(double target[][COLS], int n);
void average(double target[], int n);
double average_all(double target[][COLS], int n);
double largest(double target[][COLS], int n);
void print(double target[][COLS], int n);

int main(void)
{
    double target[ROWS][COLS];

    printf("Please enter three sets of five double number each:\n");
    arr(target, ROWS);

    return 0;
}

void arr(double target[][COLS], int n)
{
    int i, j;

    for(i = 0; i < n; i++)
        for(j = 0; j < COLS; j++)
            scanf("%lf", &target[i][j]);

    print(target, ROWS);
    
    for(i = 0; i < ROWS; i++)
        average(target[i], COLS);
    printf("The average of all values is %.2lf\n", average_all(target, ROWS));
    printf("The largest value of the 15 values is %.2lf\n", largest(target, ROWS));
}

void average(double target[], int n)
{
    int i;
    double total = 0;

    for(i = 0; i < n; i++)
        total += target[i];
    printf("The average of each set of five values is %.2lf.\n", total / n);
}

double average_all(double target[][COLS], int n)
{
    int i, j;
    double total = 0;

    for(i = 0; i < n; i++)
        for(j = 0; j < COLS; j++)
            total += target[i][j];
    return (total / (n * COLS));
}

double largest(double target[][COLS], int n)
{
    int i, j;
    double max = target[0][0];

    for(i = 0; i < n; i++)
        for(j = 0; j < COLS; j++)
            max = (max > target[i][j] ? max : target[i][j]);
    return max;
}

void print(double target[][COLS], int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < COLS; j++)
            printf("%.2lf ", target[i][j]);
        printf("\n");
    }
    printf("\n");
}
