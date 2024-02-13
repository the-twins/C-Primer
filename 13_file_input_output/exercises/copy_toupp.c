// Write a file copy program that prompts the user to enter the name of a text file to act as
// the source file and the name of output file. The program should use the toupper()
// function from ctype.c to convert all text to uppercase as it's written to the output file.
// Use standard I/O and the text mode.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 41

int main(void)
{
    int ch;
    char in[MAX];
    char out[MAX];
    FILE *fp, *fp2;
    printf("Enter the name of a text file:\n");
    scanf("%s", in);
    printf("Enter the name of output file:\n");
    scanf("%s", out);
    if((fp = fopen(in, "r")) == NULL)
    {
        printf("Can't open %s\n", in);
        exit(EXIT_FAILURE);
    }
    if((fp2 = fopen(out, "w")) == NULL)
    {
        printf("Wrire error.\n");
        exit(EXIT_FAILURE);
    }
    while((ch = getc(fp)) != EOF)
    {
        ch = toupper(ch);
        putc(ch, fp2);
    }
    printf("Done!\n");
    fclose(fp);
    fclose(fp2);

    return 0;
}
