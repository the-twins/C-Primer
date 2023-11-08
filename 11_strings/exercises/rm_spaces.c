// Write a function that takes a string as an argument and removes the spaces from the
// string. Test it in a program that uses a loop to read lines until you enter an empty line.
// The program should apply the function to each input string and display the result.
#include <stdio.h>

#define SIZE 100

void rm_spaces(char * ar);
void print_arr(char * ar, int n);

int main(void)
{
    char string[SIZE];
    printf("Enter text to remove spaces or empty line to quit:\n");
    while(fgets(string, SIZE, stdin) && string[0] != '\n')
    {
        rm_spaces(string);
	printf("%s\n", string);
        printf("Try again(empty line to quit):\n");
    }

    return 0;
}

void rm_spaces(char * ar)
{
    int i = 0;
    int j = 0;
    while(ar[i] != '\0')
    {
        if(ar[i] != ' ')
        {
            ar[j] = ar[i];
            i++;
	    j++;
	}
        else
            i++;
    }
    ar[j] = '\0';
} 
