// Write a program that creates an array with 26 elements and stores the 26
// lowercase letters in it. Also have it show the array contents.
#include <stdio.h>

#define ALPHABET 26

int main(void)
{
    char letter[ALPHABET];
    char ch;
    int index;

    for (index = 0; index < ALPHABET; index++) 
        letter [index] = 'a' + 1;
    for (ch = 'a'; ch < ('a' + ALPHABET); ch++)
        printf("%c ", ch);
        printf("\n");

    return 0;
}
        
