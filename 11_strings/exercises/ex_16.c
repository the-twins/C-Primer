// Write a program that reads input until EOF and echoes it to the display. Have the
// program recognize and implement the following command-line arguments:
// -p Print input as is
// -u Map input to all uppercase
// -l Map input to all lowercase
// Also, if there are no command-line arguments, let the program behave as if the -p
// argument had been used.
#include <stdio.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    char ch;
    if(argc > 2)
    {
        printf("Usage: %s -p|-u|-l\n", argv[0]);
        return 1;
    }
    if(argc < 2)
    {
        printf("Enter text with EOF at the end:\n");
        while((ch = getchar()) != EOF)
	    putchar(ch);
    }
    else
    {
        printf("Enter text with EOF at the end:\n");
        while((ch = getchar()) != EOF)
        {
            if(argv[1][1] == 'p')
                putchar(ch);
            if(argv[1][1] == 'u')
                putchar(toupper(ch));
            if(argv[1][1] == 'l')
                putchar(tolower(ch));
        }
    }

    return 0;
}
