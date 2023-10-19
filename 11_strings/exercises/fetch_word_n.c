// Design and test a function like that described in Programming Exercise 3 that it 
// accepts a second parameter specifying the maximum number of characters that can be
// read.
#include <stdio.h>
#include <ctype.h>

#define SIZE 5

char * fetch_word(char * str, int n);

int main(void)
{
    char string[SIZE + 1];
    printf("Enter text(EOF for quit):\n");
    fetch_word(string, SIZE);
    printf("\n");
    puts(string);
    puts("Bye!");

    return 0;
}

char * fetch_word(char * str, int n)
{
    char ch;
    int i = 0;
    while(isspace(ch = getchar()))
        ;
        str[i] = ch;
        i++;
    while((ch = getchar()) != EOF)
    {
        if(!isspace(ch) && i != n)
	{
            str[i] = ch;
            i++;
        }
        else
	{
            str[i] = '\0';
            break;
        }
    }
    str[n] = '\0';
    return str;
}
