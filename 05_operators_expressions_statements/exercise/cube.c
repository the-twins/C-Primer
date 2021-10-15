// This program requests a type double number and prints the value of the
// number cubed. (Use a function of your own design to cube the value and print
// it. The 'main()' program should pass the entered value to this function.)
#include <stdio.h>

void cube(double numb);

int main(void)
{
    double numb;
    printf("Enter the number. Enter 0 to stop the program.\n");
    scanf("%lf", &numb);
    while (numb != 0)
    {
        cube(numb);
        printf("Enter next number. Enter 0 to stop the program.\n");
        scanf("%lf", &numb);
    }
    return 0;
}

void cube(double numb)
{
    printf("The cube of %.2lf is %.2lf.\n", numb, numb * numb * numb);
}
