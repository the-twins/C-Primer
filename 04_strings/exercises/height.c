// The program requests your height in inches and your name, and then displays
// the information in the following form: "Dabney, you are 6.208 feet tall."
#include <stdio.h>
#define INCH_IN_FEET 12.0

int main(void)
{
    float inch;
    float feet;
    char name[40];

    printf("Enter your height in inches and your name.\n");
    scanf("%f", &inch);
    scanf("%s", name);
    feet = inch / INCH_IN_FEET;
    printf("%s, you are %.2f feet tall.\n", name, feet);

    return 0;
}
