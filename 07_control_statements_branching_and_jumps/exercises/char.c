// Write a program that reads input until encountering the # character and then
// reports the number of spaces read, the number of newline characters read, and
// the number of all other characters read.
#include <stdio.h>

int main(void)
{
    char ch;
    int n_spaces = 0;
    int n_lines = 0;
    int n_symbols = 0;

    printf("Enter text to be analyzed (# to quit):\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            n_spaces++;
        else if (ch == '\n')
            n_lines++;
        else
            n_symbols++;
    }
    printf("Spaces = %d, newlines = %d, all other characters = %d.\n", n_spaces,
           n_lines, n_symbols);

    return 0;
}
