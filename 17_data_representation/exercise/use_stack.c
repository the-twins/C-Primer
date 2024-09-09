// Write a program that lets you input a string. The program then should push the
// characters of the string onto a stack, one by one (see review question 5), and then pop
// the characters from the stack and display them. This results in displaying the string in
// reverse order.
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "../../11_strings/lib.h"       // for s_gets()
#define MAX_ST 20

int main(void)
{
    Stack text;
    char temp[MAX_ST];
    int i = 0;
    char ch;
    InitializeStack(&text);
    printf("Enter a string:\n");
    s_gets(temp, MAX_ST);
    for(i = 0; temp[i] != '\0' ; i++)
    { 
        if(StackIsFull(&text))
        {
            printf("Stack is full!\n");
            break;
        }
        else
            StackPush(temp[i], &text);
    }
    printf("%d - number of elements in a string.\n", StackItemCount(&text));
    while(!StackIsEmpty(&text))
    {
        StackPop(&ch, &text);
        printf("%c", ch);
    }
    EmptyTheStack(&text);
    printf("\nBye!\n");

    return 0;
}
