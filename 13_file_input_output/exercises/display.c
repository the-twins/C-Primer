// Write a program that sequentially display onscreen all the files listed in the command
// line. Use argc to control a loop.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int ch;
    int i;
    FILE *fp;

    if(argc < 2)
        exit(EXIT_FAILURE);
    for(i = 1; i < argc; i++)
    {
        if((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Can't open file \"%s\"\n", argv[i]);
            continue;
        }
        while((ch = getc(fp)) != EOF)
            putchar(ch);
        fclose(fp);
    }

    return 0;
}
