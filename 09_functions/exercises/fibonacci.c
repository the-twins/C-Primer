// Write and test a Fibonacci() function that uses a loop instead of recursion to calculate
// Fibonacci numbers.
#include <stdio.h>

int Fibonacci(int n);

int main(void)
{
    int numb;
    printf("Enter an integer:\n");
    while (scanf("%d", &numb) == 1)
    {
        printf("%d\n", Fibonacci(numb));
        printf("Try again (q to quit).\n");
    }
    printf("Bye!");

    return 0;
}

int Fibonacci(int n)
{
    int ans = 0;
    int current = 1; 
    int prev, i;
    if (n < 3)
        return 1;
    for (prev = 1, i = 3; i <= n; i++)
    {
	ans = current + prev;
	prev = current;
	current = ans;
    }
    return ans;
}
