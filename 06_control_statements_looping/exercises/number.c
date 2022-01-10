// Write a program that reads eight integers into an array and then prints 
// them in reverse order
#include <stdio.h>

#define MAX_INTEGERS 8 

int main(void)
{
    int index;
    int numbers[MAX_INTEGERS];

    for (index = 0; index < MAX_INTEGERS; index++)
    {
        printf("Please enter some integer: ");    
        scanf("%d", &numbers[index]);
    }
    for (index = MAX_INTEGERS - 1; index >= 0; index--)
        printf("%d", numbers[index]);
    printf("\n");
    
    return 0;
}
