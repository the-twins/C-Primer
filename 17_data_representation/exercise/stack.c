//stack.c -- the Stack implementation
#include <stdio.h>
#include "stack.h"

void InitializeStack(Stack * ps)
{
    ps->top = 0;
}

bool StackIsFull(const Stack * ps)
{
    return ps->top == MAXSTACK;
}

bool StackIsEmpty(const Stack * ps)
{
    return ps->top == 0;
}

int StackItemCount(const Stack * ps)
{
    return ps->top;
}

bool StackPush(Item item, Stack * ps)
{
    if(ps->top == MAXSTACK)
        return false;
    else
    {
        ps->item[ps->top++] = item;
        return true;
    }
}

bool StackPop(Item * pitem, Stack * ps)
{
    if(ps->top == 0)
        return false;
    else
    {
        ps->top--;
        *pitem = ps->item[ps->top];
        return true;
    }
}

void EmptyTheStack(Stack * ps)
{
    ps->top = 0;
}
