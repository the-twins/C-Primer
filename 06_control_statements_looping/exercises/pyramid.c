// Have a program request the user to enter an uppercase letter. Use nested
// loops to produce a pyramid pattern like this:
//     A    
//    ABA   
//   ABCBA  
//  ABCDCBA 
// ABCDEDCBA
// The pattern should extend to the character entered. For example, the
// preceding pattern would result from an input value of E. 
// Hint: Use an outer loop to handle the rows. Use three inner loops in a row,
// one to handle the spaces, one for printing letters in ascending order, and 
// one for printing letters in descending order.
// If your system doesn’t use ASCII or some other code that encodes letters in 
// numeric order, you can use the following to initialize a character array to 
// the letters of the alphabet: 
// char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// Then you can use the array index to select individual letters; for example, 
// lets[0] is 'A', and so on.
#include <stdio.h>

int main(void)
{
    char middle_ch, ch, limit;
    
    printf("Enter the limit letter: ");
    scanf("%c", &limit);

    for (middle_ch = 'A'; middle_ch <= limit; middle_ch++)
    {    
        for (ch = 1; ch <= limit - middle_ch; ch++) // draws spaces
            printf(" ");
        for (ch = 'A'; ch < middle_ch; ch++)        // draws the left side of the pyramid
            printf("%c", ch);
        for (ch = middle_ch; ch >= 'A'; ch--)       // draws the right side of the pyramid
            printf("%c", ch);
        printf("\n");
    }
    return 0;
}
