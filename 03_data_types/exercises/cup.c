// The program requests a volume in cups and that displays the equivalent
// volumes in pints, ounces, tablespoons, and teaspoons. A pint is 2 cups, a
// cup is 8 ounces, an ounce is 2 tablespoons, and a tablespoon is 3 teaspoons
#include <stdio.h>

int main (void)
{
    float pint;
    float cup;
    float ounce;
    float tspoon;
    float teaspoon;

    printf("Enter volume in cups: ");
    scanf("%f", &cup);
    pint = cup / 2;
    ounce = cup * 8;
    tspoon = cup * 16;
    teaspoon = cup * 48;
    printf("There are volumes %.2f in pints, %.2f in ounces, ", pint, ounce);
    printf("%.2f in tablespoons, %.2f in teaspoons.\n", tspoon, teaspoon);

    return 0;
}   
