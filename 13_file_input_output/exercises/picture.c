// Create a text file consisting of 20 rows of 30 integers. The integers should be in the range
// 0-9 and be separated by spaces. The file is a digital representation of a picture, with
// the values 0 through 9 representing increasing levels of darkness. Write a program that
// reads the contents of the file into a 20-by-30 array of ints. In a crude approach toward
// converting this digital representation to a picture, have the program use the values
// in this array to initialize a 20-by-31 array chars, with a 0 value corresponding to a
// space character, a 1 value to the period character, and so on, with each larger number
// represented by a character that occupies more space. For example, you might use # to
// represent 9. The last character (the 31st) in each row should be a null character, making
// it an array of 20 strings. Have the program display the resulting picture (that is, print the
// strings) and also store the result in a text file.
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30
#define SIMB " .,:@*=|%#"
#define OUT_F "image.txt"

int main (int argc, char * argv[])
{
    char picture[ROWS][COLS + 1];
    int img[ROWS][COLS];
    FILE *in, *out;
    int c, r;
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
    for(r = 0; r < ROWS; r++)
        for(c = 0; c < COLS; c++)
            fscanf(in, "%d", &img[r][c]);
    for(r = 0; r < ROWS; r++)
    {
        for(c = 0; c < COLS; c++)
            picture[r][c] = SIMB[img[r][c]];
        picture[r][COLS] = '\0';
    }
    for(r = 0; r < ROWS; r++)
    {
        puts(picture[r]);
        fprintf(out, "%s\n", picture[r]);
    }
    fclose(in);
    fclose(out);

    return 0;
}
