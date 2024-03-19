// Digital images, paticularly those radioed back from spacecraft, may have glitches. Add
// a de-glitching function to programming exercise 12. It should compare each value to its
// immediate neighbors to the left and right, above and below. If the value differs by more
// than 1 from each of its neighbors, replace the value with the average of the neighboring
// values. You should round the average to the nearest integer value. Note that the points
// along the boundaries have fewer than four neighbors, so they require special handling.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void glitch(int rows, int cols, int img[rows][cols]);
int abs_diff(int a, int b);

#define SIMB " .,:@*=|%#"
#define OUT_F "image.txt"

int main (int argc, char * argv[])
{
    int rows = 0;
    int cols = 0;
    FILE *in, *out;
    int c = 0;
    int r = 0;
    int ch;
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
        if(ch >= '0' && ch <= '9' && !rows)
            cols++;
    }
    int img[rows][cols];
    char picture[rows][cols + 1];
    fseek(in, 0L, SEEK_SET);
    for(r = 0; r < rows; r++)
        for(c = 0; c < cols; c++)
            fscanf(in, "%d", &img[r][c]);
    glitch(rows, cols, img);
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

void glitch(int rows, int cols, int img[rows][cols])
{
    int r, c;
    int neig_count; 
    int neig_sum;
    bool glit;
    for(r = 0; r < rows; r++)
    {
        for (c = 0; c < cols; c++)
        {
            neig_count = 0;
            neig_sum = 0;
	    glit = false;
            if(r)
            {
                neig_count++;
                neig_sum += img[r - 1][c];
                if(abs_diff(img[r][c], img[r - 1][c]) > 1)
                    glit = true;
	    }
            if(r < (rows - 1))
            {
                neig_count++;
                neig_sum += img[r + 1][c];
                if(abs_diff(img[r][c], img[r + 1][c]) > 1)
                    glit = true;
            }
            if(c)
            {
                neig_count++;
                neig_sum += img[r][c-1];
                if(abs_diff(img[r][c], img[r][c - 1]) > 1)
                    glit = true;
            }
            if(c < (cols - 1))
            {
                neig_count++;
                neig_sum += img[r][c + 1];
                if(abs_diff(img[r][c], img[r][c + 1]) > 1)
                    glit = true;
            }
            if(glit)
                img[r][c] = neig_sum / neig_count;
	}
    }
}

int abs_diff(int a, int b)
{
    int diff;
    diff = a - b;
    if(diff < 0)
        diff = diff * (-1);
    return diff;
}
