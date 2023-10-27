// Design and test a function that fetches the next n characters from input (including
// blanks, tabs, and newlines), storing the results in an array whose address is passed as an
// argument.
#include <stdio.h>

#define SIZE 10

char * fetch_n(char * str, int n);

int main(void)
{
    char string[SIZE + 1];
    printf("Enter text(EOF for quit):\n");
    fetch_n(string, SIZE);
    printf("\n");
    puts(string);
    puts ("Bye!");

    return 0;
}

char * fetch_n(char * str, int n)
{
    char ch;
    int i;
    for (i = 0; i < n; i++)
    {
        ch = getchar();
        if (ch != EOF)
            str[i] = ch;
        else
        {
	    str[i] = '\0';
            break;
	}
    }
    str[n] = '\0';
    return str;
}
