// stack.h -- interface for a stack
#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

typedef char Item;

#define MAXSTACK 15 

typedef struct stack
{
    Item item[MAXSTACK];
    int top;
} Stack;

void InitializeStack(Stack * ps);
bool StackIsFull(const Stack * ps);
bool StackIsEmpty(const Stack * ps);
int StackItemCount(const Stack * ps);
bool StackPush(Item item, Stack * ps);
bool StackPop(Item * pitem, Stack * ps);
void EmptyTheStack(Stack * ps);

#endif
