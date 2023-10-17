// Modify and test the function in exercise 1 so that it stops after n characters or after the
// first blank, tab, or newline, whichever comes first. (Don't just use scanf().)
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
    puts("Bye!");

    return 0;
}

char * fetch_n(char * str, int n)
{
    char ch;
    int i;
    for(i = 0; i < n; i++)
    {
        ch = getchar();
        if(ch != EOF && ch != ' ' && ch != '\n' && ch != '\t')
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
