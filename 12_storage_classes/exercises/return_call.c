// Write and test in a loop a function that returns the number of times it has been called.
#include <stdio.h>

int return_call(void);

int main(void)
{
    int i;
    int number;
    printf("How many times do you want to call the function return_call(). Enter a number: ");
    scanf("%d", &number);
    for(i = 0; i < number; i++)
        printf("You called the function %d times.\n", return_call());
    return 0;
}

int return_call(void)
{
    static int call = 0;
    return ++call;
}
