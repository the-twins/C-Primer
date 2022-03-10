// Using if else statements, write a program that reads input up to #, replaces 
// each period with an exclamation mark, replaces each exclamation mark 
// initially present with two exclamation marks, and reports at the end the 
// number of substitutions it has made.
#include <stdio.h>

int main(void)
{
    char ch;
    int point_count = 0;
    int excl_mark_count = 0;

    while ((ch = getchar()) != '#')
    {
        if (ch == '.')
        {
            putchar('!');
            point_count++;
        }
        else if (ch == '!')
        {
            putchar('!');
            putchar('!');
            excl_mark_count++;
        }
        else
            putchar(ch);
     }
     printf("\nThe point has been replaced %d times, exclamation mark has been "
            "replaced %d times.\n", point_count, excl_mark_count);

     return 0;
}
