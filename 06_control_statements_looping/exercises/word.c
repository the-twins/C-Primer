// Write a program that reads a single word into a character array and then
// prints the word backward. 
// Hint: Use strlen() (Chapter 4) to compute the index of the last character 
// in the array.
#include <stdio.h>
#include <string.h>

#define MAX_LETTERS 30 

int main(void)
{
    int index;
    char word[MAX_LETTERS];
    
    printf("Please enter some word (no more than %d letters): ", MAX_LETTERS);
    scanf("%s", word);
    
    for (index = strlen(word) - 1; index >= 0 ; index--)
        printf("%c", word[index]);
    printf("\n");
    return 0;
}
