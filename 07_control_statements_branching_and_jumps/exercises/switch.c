// Redo exercise 4 using a switch.
#include <stdio.h>

int main(void)
{
    char ch;
    int point_count = 0;
    int excl_mark_count = 0;

    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
            case '.' :
                putchar('!');
                point_count++;
                break;       
            case '!' :
                putchar('!');
                putchar('!');
                excl_mark_count++;
                break;
            default :
                putchar(ch);
        }
    }
    printf("\nThe point has been replaced %d times, exclamation mark has been "
            "replaced %d times.\n", point_count, excl_mark_count);

    return 0;
}
