// The program requests a volume in cups and that displays the equivalent
// volumes in pints, ounces, tablespoons, and teaspoons. A pint is 2 cups, a
// cup is 8 ounces, an ounce is 2 tablespoons, and a tablespoon is 3 teaspoons
#include <stdio.h>

int main (void)
{
    float cup;

    printf("Enter volume in cups: ");
    scanf("%f", &cup);
    printf("%.2f cups is equal to %.2f pints, ",cup, cup / 2);
    printf("%.2f ounces, %.2f tablespoons, ", cup * 8, cup * 16);
    printf("%.2f teaspoons.\n", cup * 48);

    return 0;
}   
