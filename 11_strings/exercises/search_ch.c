// Design and test a function that searches the string specified by the first function
// parameter for the first occurrence of a character specified by the second function
// parameter. Have the function return a pointer to the character if successful, and a null
// if the character is not found in the string. (This duplicates the way that the library
// strchr() function works.) Test the function in complete progtam that uses a loop to
// provide input values for feeding to the function.
#include <stdio.h>

#define SIZE 100

char * search_char(char * str, char ch);

int main(void)
{
    char string[SIZE];
    char ch;
    char * find;
    printf("Enter text to analyze:\n");
    fgets(string, SIZE, stdin);
    printf("Enter character:\n");
    scanf("%c", &ch);
    find = search_char(string, ch);
    if(find)
        printf("%ld.\n", find - string);
    else
        printf("This text does not contain %c character.\n", ch);

return 0;
}

char * search_char(char * str, char ch)
{
    while(* str != '\0') 
    {
        if(*str == ch)
	    return str;
	str++;
    }
    return NULL;
}
