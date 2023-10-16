// Do Programming Exercise 13, but use variable-lenght array function parameters.
#include <stdio.h>

#define ROWS 3
#define COLS 5

void arr(int r, int c, double target[r][c]);
double average(int c, double target[c]);
double average_all(int r, int c, double target[r][c]);
double largest(int r, int c, double target[r][c]);
void print(int r, int c, double target[r][c]);

int main(void)
{
    double target[ROWS][COLS];
    int i;

    printf("Please enter three sets of five double number each:\n");
    arr(ROWS, COLS,target);
    print(ROWS, COLS, target);
    for(i = 0; i < ROWS; i++)
        printf("The average of %d set is %.2lf.\n", i + 1, average(COLS, target[i]));
    printf("The average of all values is %.2lf\n", average_all(ROWS, COLS, target));
    printf("The largest value of the 15 values is %.2lf.\n", largest(ROWS, COLS, target));

    return 0;
}

void arr(int r, int c, double target[r][c])
{
    int i, j;

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%lf", &target[i][j]);
}

double average(int c, double target[c])
{
    int i;
    double total = 0;

    for(i = 0; i < c; i++)
        total += target[i];
    return total / c;
}

double average_all(int r, int c, double target[r][c])
{
    int i, j;
    double total = 0;

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            total += target[i][j];
    return (total / (r * c));
}

double largest(int r, int c, double target[r][c])
{
    int i, j;
    double max = target[0][0];

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            max = (max > target[i][j] ? max : target[i][j]);
    return max;
}

void print(int r, int c, double target[r][c])
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%.2lf ", target[i][j]);
        printf("\n");
    }
    printf("\n");
}
