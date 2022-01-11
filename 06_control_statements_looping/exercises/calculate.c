// Modify exercise 8 so that it uses a function to return the value of the 
// calculation.
#include <stdio.h>

float calculate(float first_num, float next_num); 

int main(void)
{
    float first_num, next_num;
    int status;

    printf("Please enter two floats ");
    printf("(q to quit): ");
    status = scanf("%f %f", &first_num, &next_num);
    while (status == 2)
    {
        printf("The value of their difference divided by their product = %.2f\n", calculate(first_num, next_num));
        printf("Please enter two floats (q to quit): ");
        status = scanf("%f %f", &first_num, &next_num);
    }
    return 0;
}

float calculate(float first_num, float next_num)
{
    return (first_num - next_num) / (first_num * next_num);
}
