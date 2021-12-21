// Write a program that creates an array with 26 elements and stores the 26
// lowercase letters in it. Also have it show the array contents.
#include <stdio.h>

#define ALPHABET 26

int main(void)
{
    char letter[ALPHABET];
    int index;

    for (index = 0; index < ALPHABET; index++) 
        letter[index] = 'a' + index;
    for (index = 0; index < ALPHABET; index++)
        printf("%c ", letter[index]);
    printf("\n");

    return 0;
}
        
