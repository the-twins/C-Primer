// Write a file-copy program that takes the original filename and the copy file from the
// command line. Use standard I/O and the binary mode, if possible.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    FILE *in, *out;
    int ch;
    if(argc != 3)
        exit(EXIT_FAILURE);
    if((in = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr,"Can't open file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if((out = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "Write error.\n");
        exit(EXIT_FAILURE);
    }
    while((ch = getc(in)) != EOF)
        putc(ch, out); 
    printf("DONE!\n");
    fclose(in);
    fclose(out);

    return 0;
}
