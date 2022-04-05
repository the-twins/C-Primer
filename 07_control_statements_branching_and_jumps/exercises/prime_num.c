// Write a program that accepts a positive integer as input and then displays 
// all the prime numbers smaller than or equal to that number.
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    unsigned long num;
    unsigned long check_num;
    unsigned long prime_num;
    bool is_prime;

    printf("Enter a positive integer: \n");
    scanf("%lu", &num);
    for (prime_num = 2; prime_num < num; prime_num++)
    {
        is_prime = true;
        for (check_num = 2; check_num < prime_num; check_num++)
            if (prime_num % check_num == 0)
            {
                is_prime = false;
                break;
            }
        if (is_prime)
            printf("%lu is a prime number\n", prime_num);
    }
    
    return 0;
}
