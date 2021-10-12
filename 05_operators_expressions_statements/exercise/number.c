// This program asks for an integer and then print all the integers from (and
// including) that value up to (and including) a value larger by 10.

#include <stdio.h>

int main(void)
{
    int n, n_max;
    printf("Please enter an integer.\n");
    scanf("%d", &n);
    printf("%d\n",n);
    printf("%d\n", n_max = n + 1);
    while( n_max++ < n + 10 )
    {
         printf("%d\n",n_max);
    }

    return 0;
}
