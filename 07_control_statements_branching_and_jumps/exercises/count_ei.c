// Write a program that reads input up to # and reports the number of times 
// that the sequence ei occurs. Note: The program will have to “remember” the 
// preceding character as well as the current character. Test it with input 
// such as "Receive your eieio award".
#include <stdio.h>

int main(void)
{
    char ch;
    int count = 0;

    while ((ch = getchar()) != '#')
    {
        if (ch == 'e')
        {    
            ch = getchar();  
            if (ch == 'i')
                count++;
                continue;
        }          
    }
    printf("The %d times the sequence 'ei' occurs.\n", count);

    return 0;
}
