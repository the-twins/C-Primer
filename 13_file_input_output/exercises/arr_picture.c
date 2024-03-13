// Do Programming Exercise 12, but use variable-length arrays (VLAs) instead of standard
// arrays.
#include <stdio.h>
#include <stdlib.h>

#define SIMB " .,:@*=|%#"
#define OUT_F "image.txt"

int main (int argc, char * argv[])
{
    int rows = 0;
    int cols = 0;
    int ch;
    FILE *in, *out;
    int c = 0;
    int r = 0;
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file\"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if((out = fopen(OUT_F, "w")) == NULL)
    {
        fprintf(stderr,"I couldn't open the file\"%s\"\n", OUT_F);
        exit(EXIT_FAILURE);
    }
    while((ch = getc(in)) != EOF)
    {
        if(ch == '\n')
            rows++;
        if(ch >= '0'&& ch <= '9' && !rows)
	    cols++;
    }
    int img[rows][cols];
    char picture[rows][cols + 1];
    fseek(in, 0L, SEEK_SET);
    for(r = 0; r < rows; r++)
        for(c = 0; c < cols; c++)
	    fscanf(in, "%d", &img[r][c]);
    for(r = 0; r < rows; r++)
    {
        for(c = 0; c < cols; c++)
            picture[r][c] = SIMB[img[r][c]];
        picture[r][cols] = '\0';
    }
    for(r = 0; r < rows; r++)
    {
        puts(picture[r]);
        fprintf(out, "%s\n", picture[r]);
    }
    fclose(in);
    fclose(out);

    return 0;
}
