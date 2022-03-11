// Write a program that reads integers until 0 is entered. After input terminates, 
// the program should report the total number of even integers (excluding the 0) 
// entered, the average value of the even integers, the total number of odd integers 
// entered, and the average value of the odd integers.
#include <stdio.h>

int main(void)
{
    int numb;
    int numb_odd = 0;
    int numb_even = 0;
    int even_count = 0;
    int odd_count = 0;

    printf("Enter integers ('0' to quit):\n");
    while (scanf("%d", &numb) == 1 && numb)
    {
        if ((numb % 2) == 0)
        {
            even_count++;
            numb_even += numb;
        }
        else
        {
            numb_odd += numb;
            odd_count++;
        }
    }
    if (even_count > 0)
        printf("The total number of even integers = %d, the average value of the "
               "even integers = %.2f.\n", even_count, (float) numb_even / even_count);
    else
        printf("The total number of even integers = %d.\n", even_count);
    if (odd_count > 0)
        printf("The total number of odd integers = %d, the average value of the "
               "odd integers = %.2f.\n", odd_count, (float) numb_odd / odd_count);
    else
        printf("The total number of odd integers = %d.\n", odd_count); 

    return 0;
}
