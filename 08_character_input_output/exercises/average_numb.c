// Write a program that reads input as a stream of characters until encountering EOF. Have
// it report the average number of letters per word. Don't count whitespace as being letters
// in a word. Actually, punctuation shouldn't be counted either, but dont't worry about that
// now. (If you do worry about it, consider using the 'ispunct()' function from the 'ctype.h'
// family.)
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    char ch;
    int n_chars = 0;
    int n_words = 0;
    bool inword = false;
 
    printf("Enter text to be analyzed:\n");
    while ((ch = getchar()) != EOF)
    {
        if (isalnum(ch))
            n_chars++;
        if (!isspace(ch) && !inword)
        {
            inword = true;
            n_words++;
        }
        if (isspace(ch) && inword)
            inword = false;
    }
    if (n_words == 0)
        printf("The program is stopped.\n");
    else
        printf("\nThis text contains %d words of %d letters. Averege number of letters "
	       "= %d.\n", n_words, n_chars, n_chars / n_words);

    return 0;
}
