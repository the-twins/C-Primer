// Write a function called is_within() that takes a character and a string pointer as its two
// function parameters. Have the function return a nonzero value (true) if the character is
// in the string and zero (false) otherwise. Test the function in a complete program that usws
// a loop to provide input values for feeding to the function.
#include <stdio.h>

#define SIZE 100

int is_within(char * str, char ch);

int main(void)
{
    char string[SIZE];
    char ch;
    int find;
    printf("Enter text to analyze(EOF to quit):\n");
    while (fgets(string, SIZE, stdin) && string[0] != EOF)
    {
        printf("Enter character:\n");
        scanf("%c", &ch);
        find = is_within(string, ch);
        if(find == 1)
            printf("This text contains %c character.\n", ch);
        else
            printf("This text does not contain %c character.\n", ch);
	printf("Enter text to analyze(EOF to quit):\n");
	fgets(string, SIZE, stdin);
    }

    return 0;
}

int is_within(char * str, char ch)
{
    while(* str != '\0')
    {
        if(* str == ch)
            return 1;
        str++;
    }
    return 0;
}
