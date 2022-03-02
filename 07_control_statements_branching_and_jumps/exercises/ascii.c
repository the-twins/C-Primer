// Write a program that reads input until encountering #. Have the program print each input 
// character and its ASCII decimal code. Print eight character-code pairs per line. 
// Suggestion: Use a character count and the modulus operator (%) to print a newline character 
// for every eight cycles of the loop.
#include <stdio.h>

#define CH_IN_LINE 8

int main(void)
{
    char ch;
    int numb = 0;

    printf("Enter text to be analyzed (# to quit):\n");
    while ((ch = getchar()) != '#')
    {
        numb++;
        if (numb % CH_IN_LINE == 0)
            printf("%c = %d\n", ch, ch);
        else
            printf("%c = %d ", ch, ch);
    }   
    printf ("\n");

    return 0;
}
