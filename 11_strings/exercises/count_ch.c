// Write a program that reads input up to EOF and reports the number of words, the
// number of uppercase letters, the number of lowercase letters, the number of punctuation
// characters, and the number of digits. Use the ctype.h family of functions.
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int word = 0;
    int up_letter = 0;
    int low_letter = 0;
    int punct_ch = 0;
    int digit = 0;
    bool inword = false;
    char ch;
    printf("Enter text (EOF to quit):\n");

    while((ch = getchar()) != EOF)
    {
        if(!isspace(ch) && !inword)
        {
            inword = true;
            word++;
        }
	if(isspace(ch) && inword)
            inword = false;
        if(isupper(ch))
            up_letter++;
        if(islower(ch))
            low_letter++;
        if(ispunct(ch))
            punct_ch++;
        if(isdigit(ch))
            digit++;
    }
    printf("\nWords = %d, uppercase letters = %d, lowercase letters = %d, punctuation characters"
           " = %d, digits = %d.\n", word, up_letter, low_letter, punct_ch, digit);

    return 0;
}

        

