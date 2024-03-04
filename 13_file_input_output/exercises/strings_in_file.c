// Write a program that takes two command-line arguments. The first is a string; the
// second is the name of file. The programs should then search the file, printing all lines
// containing the string. Because this task is line oriented rather then character oriented,
// use fgets() insted of getc(). Use the standard C library function strstr() (briefly
// described in exercise 7 of Chapter 11) to search each line for the string. Assume no lines
// are longer than 255 characters.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

int main(int argc, char * argv[])
{
    char buf[MAX];
    FILE *fp;
    if(argc < 2)
    {
        fprintf(stderr, "Enter a string and the name of file.\n");
        exit(EXIT_FAILURE);
    }
    if((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "I culdn't open files.\n");
        exit(EXIT_FAILURE);
    }
    while(fgets(buf, MAX, fp) != NULL)
    {
        if(strstr(buf, argv[1])!= NULL)
            printf("%s", buf);
    }

    return 0;
}
