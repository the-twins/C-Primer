// Write a program that opens a text file whose name is obtained interactively. Set up a
// loop that asks the user to enter a file position. The program then should print the part of
// the file starting at that position and proceed to the next newline character. Let negative
// or nonnumeric input terminate the user-input loop.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 80

int main(void)
{
    char file[SIZE];
    int numb;
    int ch;
    FILE *fp;
    printf("Enter file name:\n");
    scanf("%80s", file);
    if((fp = fopen(file, "r")) == NULL)
    {
        fprintf(stderr,"Can't open file %s.\n", file);
        exit(EXIT_FAILURE);
    }
    printf("Enter a file position ('#' or negative number to quit):\n");
    while((scanf("%d", &numb) == 1) && (numb >= 0))
    {
        fseek(fp, numb, SEEK_SET);
        while((ch = getc(fp)) != EOF && ch != '\n')
            putchar(ch);
        printf("\nEnter a file position (# to quit):");
    }	
    fclose(fp);

    return 0;
}
