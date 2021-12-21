// Use nested loops to produce the following pattern:
// A
// BC
// DEF
// GHIJ
// KLMNO
// PQRSTU
// Note: If your system doesn’t use ASCII or some other code that encodes letters in numeric order,
// you can use the following to initialize a character array to the letters of the alphabet:
// char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// Then you can use the array index to select individual letters; for example, lets[0] is 'A', and 
// so on.
#include <stdio.h>

#define ROWS 6

int main(void)
{
    int row, col;
    char ch = 'A';

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col <= row; col++, ch++)
            printf("%c", ch);
        printf("\n");
    }
    return 0;
}
