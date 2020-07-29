// Have the program define a function that displays the string "Smile!" once,
// and have the program use the function as often as needed.
#include <stdio.h>

void sm(void);

int main(void)
{
    sm();
    sm();
    sm();
    printf("\n");
    sm();
    sm();
    printf("\n");
    sm();
    printf("\n");

    return 0;
}

void sm(void)
{
    printf("Smile!");
}
