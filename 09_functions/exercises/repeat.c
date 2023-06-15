// Write a function that takes three arguments: a character and two integers. The character
// is to be printed. The first integer specifies the number of times that the character is to
// be printed on a line, and the second integer specifies the number of lines that are to be
// printed. Write a program that makes use of this function.
#include <stdio.h>

void repeat(char, int, int);

int main(void)
{
    char ch;
    int numb_of_time;
    int numb_of_line;
    printf("Enter one character and two integers:\n");
    while (scanf("%c %d %d", &ch, &numb_of_time, &numb_of_line) == 3)
    {
        repeat(ch, numb_of_time, numb_of_line);
        printf("Try again. Enter one character and two intefers:\n");
        getchar();
    }
    printf("Bye!\n");

    return 0;
}

void repeat(char ch, int numb_of_time, int numb_of_line)
{
    int row, n;

    for (row = 0; row < numb_of_line; row++)
    {
        for(n = 1; n <= numb_of_time; n++)
            printf("%c", ch);
        printf("\n");
    }
} 
