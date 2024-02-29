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
    long last, count;
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
        fseek(fp, 0L, SEEK_END);
        last = ftell(fp);
	if (numb > last)
        {
            printf("This text contains only %ld characters. Bye.\n", last);
            break;
        }
        for(count = numb; count < last; count++)
        {
	    fseek(fp, count, SEEK_SET);
	    ch = getc(fp);
            putchar(ch);
	    if(ch == '\n')
                break;
        }
        printf("Enter a file position (# to quit):\n");
    }	
    putchar('\n');
    fclose(fp);

    return 0;
}
