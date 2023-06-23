// Write a program that reads characters from the standard input to end-of-file. For each
// character, have the program report whether it is a letter. If it is a letter, also report
// its numerical location in the alphabet. For example, c and C would both be letter 3.
// Incorporate a function that takes a character as an argument and returns the numerical
// location if the character is a letter and returns -1 otherwise.
#include <stdio.h>

int letter(char);

int main(void)
{
    char ch;
    printf("Enter text (EOF to quit).\n");
    while ((ch = getchar()) != EOF)
    {
	if(ch == '\n')
	    continue;
        if(letter(ch) == -1)
	    printf("%c - is not a letter.\n", ch);
	else
            printf("%c - %d\n", ch, letter(ch));
    }
    printf("Bye!\n");

    return 0;
}

int letter(char ch)
{
    if (ch >= 'a' && ch <= 'z') 
        return (ch + 1 - 'a');
    if (ch >= 'A' && ch <= 'Z')
	return (ch + 1 - 'A');
    return -1;
}
