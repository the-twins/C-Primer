// The mass of a single molecule of water is about 3.0x10^-23 grams. A quart
// of water is about 950 grams. This program requests an amount of water, in 
// quarts, and displays the number of water molecules in that amount.
#include <stdio.h>

int main(void)
{
    int quart;
    int amount;
    double molecule;

    double mass = 3.0e-23;
    int grams = 950; 

    printf("Enter amount of water in quarts: ");
    scanf("%d", &quart);
   
    amount = quart * grams;
    molecule = amount / mass;

    printf("There are %e molecules in %d quarts of water\n", molecule, quart);
   
    return 0;
}   
