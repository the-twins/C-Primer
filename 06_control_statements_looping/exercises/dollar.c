// Use nested loops to produce the following pattern:
// $
// $$
// $$$
// $$$$
// $$$$$
#include <stdio.h>

#define ROWS 5

int main(void)
{
    int row;
    int col;

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col <= row; col++)   
            printf("$");
    printf("\n");
    }

    return 0;
}
