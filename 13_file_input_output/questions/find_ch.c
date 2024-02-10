// Write a program that takes two command-line arguments. The first is a character, and
// the second is a filename. The program should print only those lines in the file containing
// the given character.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main(int argc, char * argv[])
{
    char * ch;
    FILE * fp;
    char str[SIZE];
    if(argc != 3)
        exit(EXIT_FAILURE);
    if((fp = fopen(argv[2], "r")) == NULL)
        exit(EXIT_FAILURE);
    while(fgets(str, SIZE, fp) != NULL)
    {
        ch = strchr(str, argv[1][0]);
	if(ch)
            puts(str);
    }

    return 0;
}
