// This program displays the results of applying the modulus operation. The 
// user should first enter an integer to be used as second operand, which will
// then remain unchanged. Then the user enters the numbers for which the modulus
// will be computed, terminating the process by entering 0 or less.
#include <stdio.h>

int main(void)
{
    int first, next;
    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand: ");
    scanf("%d", &next);
    printf("Now enter the first operand: ");
    scanf("%d", &first);
    while (first > 0)
    {
        printf("%d %% %d is %d.\n", first, next, first % next);
        printf("Enter next number for first operand (<=0 to quit): ");
        scanf("%d", &first);
    }
    printf("Done.\n");

    return 0;
}
