// The program converts your age in years to days and displays both values. At this point, don't worry about fractional years and leap years.
#include <stdio.h>
int main(void)
{
    int age, days;

    age = 31;
    days = 365 * age;
    printf("I am %d years old or %d days\n", age, days);

    return 0;
}
