// This program asks for an integer and then print all the integers from (and
// including) that value up to (and including) a value larger by 10.
#include <stdio.h>

int main(void)
{
    int n, current;
    printf("Please enter an integer.\n");
    scanf("%d", &n);
    printf("%d\n", current = n);
    while( current++ < n + 10 )
    {
         printf("%d\n", current);
    }
    return 0;
}
