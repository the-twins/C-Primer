// Write a function that takes a string as an argument and removes the spaces from the
// string. Test it in a program that uses a loop to read lines until you enter an empty line.
// The program should apply the function to each input string and display the result.
#include <stdio.h>
#include <ctype.h>
#include "../lib.c"

#define SIZE 100

void rm_spaces(char * ar);

int main(void)
{
    char string[SIZE];
    printf("Enter text to remove spaces or empty line to quit:\n");
    while(s_gets(string, SIZE) && string[0] != '\0')
    {
        rm_spaces(string);
	printf("%s\n", string);
        printf("Try again(empty line to quit):\n");
    }

    return 0;
}

void rm_spaces(char * ar)
{
    int i = 0;
    int j = 0;
    while(ar[i] != '\0')
    {
        if(!isspace(ar[i]))
        {
            ar[j] = ar[i];
	    j++;
	}
        i++;
    }
    ar[j] = '\0';
} 
