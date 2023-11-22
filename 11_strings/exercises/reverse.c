// Write a function that replaces the contents of a string with the string reversed. Test the
// function in a complete program that uses a loop to provide input values for feeding to
// the function.
#include <stdio.h>
#include <string.h>

#define SIZE 100

void reverse(char * ar);

int main(void)
{
    char string[SIZE];
    printf("Enter text (EOF to quit):\n");
    while(fgets(string, SIZE, stdin))
    {
        reverse(string);
	printf("%s\n", string);
        printf("Try again (EOF to quit):\n");
    }

    return 0;
}

void reverse(char * ar)
{
    int i, a;
    int n = strlen(ar);
    char temp;
    for(a = n - 1, i = 0; i < a; i++, a--)
    {
	temp = ar[a];
        ar[a] = ar[i];
	ar[i] = temp;
    }
} 
