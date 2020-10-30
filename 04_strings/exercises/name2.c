// The program requests the user's first name and then the user's last name.
// Have it print the entered names on one line and the number of letters in
// each name on the following line. Align each letter count with the end of
// the corresponding name, as in the following:
// "Melissa Honeybee
//        7        8"
// Next, have it print the same information, but with the counts aligned with
// the beginning of each name.
// "Melissa Honeybee
//  7       8"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char namef[40];
    char namel[40];
    int lettersf, lettersl;

    printf("Enter your first and last name.\n");
    scanf("%s %s", namef, namel);
    lettersf = strlen(namef);
    lettersl = strlen(namel);
    printf("%s %s\n", namef, namel);
    printf("%*d %*d\n", lettersf, lettersf, lettersl, lettersl);
    printf("%s %s\n", namef, namel);
    printf("%-*d %-*d\n", lettersf, lettersf, lettersl, lettersl);

    return 0;
}
