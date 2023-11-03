// Write a function called string_in() that takes two string pointers as arguments. If
// the second string is contained in the first string, have the function return the address
// at which the contained string begins. For instance, string_in("hats", "at") would
// return the address of the a in hats. Otherwise, have the function return the null pointer.
// Test the function in a complete program that uses a loop to provide input values for
// feeding to the function.
#include <stdio.h>
#include "../lib.c"
#include <string.h>

#define SIZE 20

char * string_in(char * s1, char * s2);

int main(void)
{
    char string1[SIZE];
    char string2[SIZE];
    char * find;
    printf("Enter the first string to analyze (EOF to quit):\n");
    while(s_gets(string1, SIZE) && string1[0] != EOF)
    {
        printf("Enter the second string to analyze:\n");
        s_gets(string2, SIZE);
	find = string_in(string1, string2);
        if(find == NULL)
            printf("No matches.\n");
	else
	    printf("Address %p in string. Position %ld.\n", find, find - string1);
   	printf("Enter the first string to analyze (EOF to quit):\n");
    }

    return 0;
}

char * string_in(char * s1, char * s2)
{
    int i = 0;
    int j = 0;
    while (s1[i] != '\0')
    {
        while(s2[j] != '\0')
	{
	    if(s2[j] == s1[i + j])
                j++;
	    else
		break;
	}
	if(s2[j] == '\0')
	    return s1 + i;
        i++;
    }
    return NULL;
}
