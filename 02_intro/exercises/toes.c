// The program creates an integer variable toes. Have the program set toes to 10. Also have the program calculate what twice toes is and what toes squared is. The program should print all three values, identifying them.  
#include <stdio.h>
int main(void)
{
    int toes, twice, square;

    toes = 10;
    twice = toes * 2;
    square = toes * toes;
    printf("It is an integer toes %d, twice toes %d, square of toes %d\n", toes, twice, square);
    
    return 0;
}
