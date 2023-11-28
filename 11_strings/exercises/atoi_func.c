// Use the character classification functions to prepare an implementation of atoi(); have
// this version return the value of 0 if the input string is not a pure number.
#include <stdio.h>
#include "../lib.c"

#define SIZE 30

int numb(char * st);

int main(void)
{
    char st[SIZE];
    int result;
    printf("Enter string:\n");
    while(s_gets(st, SIZE) != NULL)
    {
        result = numb(st);
        if(result == 0)
            printf("The input string is not a pure number.\n");
        else
            printf("%d\n", result);
         printf("Try again.\n");
    }

    return 0;
}

int numb(char * st)
{
    int n = 0;
    while(*st != '\0')
    {
        if(*st >= '0' && *st <= '9')
            n = n * 10 + (*st - '0');
        else
            return 0;
	st++;
    }
    return n;
}
