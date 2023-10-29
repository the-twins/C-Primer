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

int main(void)
{
    char string[TARGETSIZE];
    char temp [SIZE];
    puts("Enter the words to copy (EOF to quit):");
    while(s_gets(temp, SIZE) != NULL)
    {
        mystrncpy(string, temp, TARGETSIZE);
	string[TARGETSIZE] = '\0';
        printf("Your word is: %s.\n", string);
	printf("Try again (EOF to quit):\n");
    }

    return 0;
}

char * mystrncpy(char * s1, char * s2, int n)
{
    int i;
    int s;
    for(s = 0, i = 0; s <= n, i <= n; s++, i++)
    {
        s1[i] = s2[s];
	if (s1[i] == '\n')
	    return NULL;
    }
    return s1;

}
