// Suppose list.h (Listing 17.3) uses the following definition of a list:
//     #define MAXSIZE 100
//     typedef struct list
//     {
//         Item entries[MAXSIZE];  // array of item
//         int item;               // number of items in list
//     } List;
// Rewrite the list.c (Listing 17.5) functions to fit this definition an d test the resulting
// code with the film3.c (Listing 17.4) program.
#include <stdio.h>
#include <stdlib.h>
#include "list_3.h"

// interface functions
// set the list to empty
void InitializeList(List * plist)
{
    plist->item = 0;
}

// returns true if list is empty
bool ListIsEmpty(const List * plist)
{
    if(plist->item == 0)
        return true;
    else
        return false;
}

// returns true if list is full
bool ListIsFull(const List * plist)
{
    if (plist->item == MAXSIZE)
        return true;
    else
        return false;
}

// returns number of nodes
unsigned int ListItemCount(const List * plist)
{
    return plist->item;
}

// creates node to hold item and adds it to the end of
// the list pointed to by plist (slow implementation)
bool AddItem(Item item, List * plist)
{

    if(plist->item == MAXSIZE)
        return false;             // quit function on failure
  
    plist->entries[plist->item] = item;
    plist->item++;

    return true;
}

// visit each node and execute function pointed to by pfun
void Traverse (const List * plist, void (*pfun)(Item item))
{
    int i;

    for(i = 0; i < plist->item; i++)
        (*pfun)(plist->entries[i]);     // apply function to item
}

void EmptyTheList(List * plist)
{
    plist->item = 0;
}
