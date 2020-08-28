// This program asks you to enter an ASCII code value, such as 66, and then
// prints the character having that ASCII code.
#include <stdio.h>

int main(void)
{

    int number;

    printf("Please enter some number.\n");
    scanf("%d", &number);
    printf("ASCII symbol for %d is %c.\n", number, number);

    return 0;
} 
