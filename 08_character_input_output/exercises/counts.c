// Devise a program that counts the number of characters in its input
// to the end of file.
#include <stdio.h>

int main(void)
{
    int count = 0;
    int ch;

    while ((ch = getchar()) !=EOF)
        count++;
    printf("\n%d is the number of characters in its input to the end of "
           "file.\n", count);
    return 0;
} 
