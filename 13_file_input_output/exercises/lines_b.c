// Write a program that opens two files. You can obtain the filenames either by using
// command-line arguments or by soliciting the user to enter them.
// a. Have the program print line 1 of the first file, line 1 of the second file, line 2 of the
// first file, line 2 of the second file, and so on, until the last line of the longer file(in
// terms of lines) is printed.
// b. Modify the program so that lines with the same line number are printed on the
// same line.
#include <stdio.h>
#include <stdlib.h>
#include "../../11_strings/lib.h"

#define SIZE 30

int main(int argc, char *argv[])
{
    int ch_fp, ch_fp2;
    char name1[SIZE];
    char name2[SIZE];
    FILE *fp, *fp2;
    if(argc != 1 && argc != 3)
    {
        fprintf(stderr,
                "Error. Enter the names of two files on the command line, or in the program.\n");
        exit(EXIT_FAILURE);
    }
    if(argc == 1)
    {
        printf("Enter the name of the first text file:\n");
        s_gets(name1, SIZE);
        printf("Enter the name of the second text file:\n");
        s_gets(name2, SIZE);
	if((fp = fopen(name1, "r")) == NULL || (fp2 = fopen(name2, "r")) == NULL)
        {
            fprintf(stderr, "I couldn't open files\n");
            exit(EXIT_FAILURE);
        }
    }
    if(argc == 3)
    {
        if((fp = fopen(argv[1], "r")) == NULL || (fp2 = fopen(argv[2], "r")) == NULL)
        {
            fprintf(stderr, "I couldn't open files\n");
            exit(EXIT_FAILURE);
        }
    }
    ch_fp = getc(fp);
    ch_fp2 = getc(fp2);
    while(ch_fp != EOF || ch_fp2 != EOF)
    {
        while(ch_fp != EOF && ch_fp != '\n')
        {
            putchar(ch_fp);
            ch_fp = getc(fp);
	}
        if(ch_fp != EOF)
        {
            if(ch_fp2 == EOF)
                putchar('\n');
            else
                putchar(' ');
            ch_fp = getc(fp);
        }
        while(ch_fp2 != EOF && ch_fp2 != '\n')
        {
            putchar(ch_fp2);
            ch_fp2 = getc(fp2);
        }
        if(ch_fp2 != EOF)
        {
            putchar('\n');
            ch_fp2 = getc(fp2);
        }
    }
    fclose(fp);
    fclose(fp2);

    return 0;
}
