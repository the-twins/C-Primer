// Write a program that reads in a line of input and then prints the line in reverse order.
// You can store the input in an array of char; assume that the line is no longer than 255 
// characters. Recall that you can use scanf() with the %c specifier to read a character at
// a time from input and that the newline character (\n) is generated when you press the
// Enter key
#include <stdio.h>

#define MAX_CHARACTERS 255 

int main(void)
{
    int count = 0;
    char ch = 0;
    char line[MAX_CHARACTERS];
    int index;
    printf("Please enter some line (no more than %d characters): ", MAX_CHARACTERS);

    while (ch != '\n' && count < MAX_CHARACTERS)
    {
        scanf("%c", &ch);
        line[count] = ch;
        count++;    
    }

    for (index = count - 1; index >= 0 ; index--)
        printf("%c", line[index]);
    printf("\n");
    return 0;
}
