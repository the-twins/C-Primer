// Write a program that requests two floating-point numbers and prints the 
// value of their difference divided by their product. Have the program loop 
// through pairs of input values until the user enters nonnumeric input. 
#include <stdio.h>

int main(void)
{
    float first_num, next_num;
    int status;

    printf("Please enter two floats ");
    printf("(q to quit): ");
    status = scanf("%f %f", &first_num, &next_num);
    while (status == 2)
    {
        printf("The value of their difference divided by their product = %.2f\n",
               (first_num - next_num) / (first_num * next_num));
        printf("Please enter two floats (q to quit): ");
        status = scanf("%f %f", &first_num, &next_num);
    }

    return 0;
}
