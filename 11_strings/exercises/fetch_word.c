// Design and test a function that reads the first word from a line of input an array and
// discards the rest of the line. it should skip over leading whitespace. Define a word as a
// sequence of characters with no blanks, tabs, or newlines in it. Use getchar(), not scanf().)
#include <stdio.h>
#include <ctype.h>

#define SIZE 100

char * fetch_word(char * str);

int main(void)
{
    char string[SIZE];
    printf("Enter text(EOF for quit):\n");
    fetch_word(string);
    printf("\n");
    puts(string);
    puts("Bye!");

    return 0;
}

char * fetch_word(char * str)
{
    char ch;
    int i = 0;
    while(isspace(ch = getchar()))
        ;
	str[i]= ch;
	i++;
    while((ch = getchar()) != EOF)
    {
        if(!isspace(ch))
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
    return str;
}
