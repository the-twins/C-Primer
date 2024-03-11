// Write a program that takes as command-line arguments a character and zero or more
// filename. If no arguments follow the character, have the program read the standard
// input. Otherwise, have it open each file in turn and report how many times the character
// appears in each file. The filename and the character itself should be reported along with
// the count. Include error-checking to see whether the number of arguments is correct and
// whether the files can be opend. If a file can't be opened, have the program report that
// fact and go on to the next file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../11_strings/lib.h"

#define SIZE 500

int main(int argc, char * argv[])
{
    int i, ch;
    int count = 0;
    FILE * fp;
    char str[SIZE];
    if(argc > 2)
    {
        for(i = 2; i < argc; i++)
        {
            if((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Can't open file \"%s\"\n", argv[i]);
                continue;
            }
            while((ch = getc(fp)) != EOF)
            {
                if(ch == argv[1][0])
                    count++;
            }
            printf("File %s contains %d characters \"%c\"\n", argv[i], count, argv[1][0]);
            fclose(fp);
	    count = 0;
        }
    }
    if(argc == 2)
    {
        printf("Enter the text to analyze (EOF to quit):\n");
	s_gets(str, SIZE);
        for(i= 0; i < strlen(str); i++)
        {
            if(str[i] == argv[1][0])
                count++;
	}
        printf("%d characters found in your text.\n", count);
    }

    return 0;
} 
