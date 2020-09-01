// There are approximately 3.156x10^7 seconds in a year. This program requests
// your age in years and then displays the equivalent number of seconds.
#include <stdio.h>

int main(void)
{
    int age;
    double seconds = 3.156e+07;
    
    printf("Enter your age in years: ");
    scanf("%d", &age);
    printf("You are %.0f seconds old.\n", age * seconds);

    return 0;
}
