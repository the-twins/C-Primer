// Write a program that reads input as a stream of characters until encountering EOF.
// Have it report the number of uppercase letters, the number of lowercase letters, and the
// number of other characters in the input. You may assume that the numeric values for the
// lowercase letters are sequential and assume the same for uppercase. Or, more portably,
// you can use appropriate classification functions from the 'ctype.h' library.
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int up_letter = 0;
    int low_letter = 0;
    int character = 0;

    printf("Enter text to be analyzed:\n");
    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            up_letter++;
        else if (islower(ch))
            low_letter++;
        else
            character++;
    }
    printf("\nThe number of uppercase letters = %d, the number of lowercase letters = %d, and "
           "the number of other characters = %d.\n", up_letter, low_letter, character);

    return 0;
}
