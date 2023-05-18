// Modify the get_first() function of Listing 8.8 so that it returns the first non-
// whitespace character encountered. Test it in a simple program.
#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void)
{
    char ch;
    printf("Enter text to be analyzed:\n");
    ch = get_first();
    if (!ch)
        printf("Text must contain letters.\n");
    else 	
        printf("The first character is %c.\n", ch);
    printf("Bye!\n");

    return 0;
}

char get_first(void)
{
    int ch;
    while ((ch = getchar()) != EOF)
    {
        if (!isspace(ch))
	    return ch;
    }

    return 0;
}
