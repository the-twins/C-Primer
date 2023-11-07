// The strncpy(s1, s2, n) function copies exactly n characters from s2 to s1, truncating
// s2 or padding it with extra null characters as necessary. The target string may not be
// null-terminated if the length of s2 is n or more. The function returns s1. Write your own
// version of this function; call it mystrncpy(). Test the function in a complete program
// that uses a loop to provide input values for feeding to the function.
#include <stdio.h>
#include <string.h>
#include "../lib.c"

#define SIZE 40
#define TARGETSIZE 5

char * mystrncpy(char * s1, char * s2, int n);
void print_arr(char * ar, int n);

int main(void)
{
    char string[TARGETSIZE];
    char temp [SIZE];
    puts("Enter the words to copy (EOF to quit):");
    while(s_gets(temp, SIZE))
    {
        mystrncpy(string, temp, TARGETSIZE);
        print_arr(string, TARGETSIZE);
	printf("Try again (EOF to quit):\n");
    }

    return 0;
}

char * mystrncpy(char * s1, char * s2, int n)
{
    int i = 0;
    int j = strlen(s2);
    do
    {
        s1[i] = s2[i];
	i++;	    
    }
    while(i < j && i < n);
    do
    {
        s1[i] = '\0';
        i++;
    }
    while(i < n);

    return s1;
}

void print_arr(char * ar, int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (ar[i])
            putchar(ar[i]);
        else
            putchar('0');
    putchar('\n');
}
