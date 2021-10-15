// This program requests the user to enter a Fahrenheit temperature. The program
// should read the temperature as a type 'double' number and pass it as an argument
// to a user-supplied function called Temperatures(). This function should calculate
// the Celsius equivalent and the Kelvin equivalent and display all three temperatures
// with a precision of two places to the right of the decimal. It should identify each
// value with the temperature scale it represents. The Temperatures() function should
// 'const' to create symbolic representations of the three constants that appear in the
// conversions. The 'main()' function should use a loop to allow the user to enter 
// temperatures repeatedly, stopping when a 'q' or other nonnumeric value is entered.
// Use the fact that 'scanf()' returns the number of items read, so it will return 1
// if it reads a number, but it won't return 1 if the user enters 'q'.
#include <stdio.h>

#define CELS 32.0
#define KELV 273.16

void Temperatures(double fahr);

int main(void)
{
    double fahr;
    char q;
    printf("Enter a Fahrenheit temperature (q to quit): ");
    q = scanf("%lf", &fahr);
    while (q != 0)
    {
        Temperatures(fahr);
        printf("Enter the next Fahrenheit temperature(q to quit): ");
        q = scanf("%lf", &fahr);
    }
    return 0;
}

void Temperatures(double fahr)
{
    printf("%.2lf Fahrenheit is %.2lf Celsius or %.2lf Kelvin.\n",
           fahr,
           5.0 / 9.0 * (fahr - CELS),
           5.0 / 9.0 * (fahr - CELS) + KELV);
}
