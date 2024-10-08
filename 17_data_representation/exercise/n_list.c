// Suppose list.h (Listing 17.3) uses the following definition of a list:
//     typedef struct list
//     {
//         Node * head;    // points to head of list
//         Node * end;     // points to end of list
//     } List;
// Rewrite the list.c (Listing 17.5) functions to fit this definition and test the resulting
// code with the film3.c (Listing 17.4) program.
#include <stdio.h>
#include <stdlib.h>
#include "n_list.h"

// local function prototype
static void CopyToNode(Item item, Node * pnode);

// interface functions
// set the list to empty
void InitializeList(List * plist)
{
    plist->head = plist->end = NULL;
}

// returns true if list is empty
bool ListIsEmpty(const List * plist)
{
    if(plist->head == NULL)
        return true;
    else
        return false;
}

// returns true if list is full
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;

    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}

// returns number of nodes
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = plist->head;        // set to start of list

    while(pnode != NULL)
    {
        ++count;
        pnode = pnode->next;      // set to next node
    }

    return count;
}

// creates node to hold item and adds it to the end of
// the list pointed to by plist
bool AddItem(Item item, List * plist)
{
    Node * pnew;

    pnew = (Node *) malloc(sizeof(Node));
    if(pnew == NULL)
        return false;             // quit function on failure

    CopyToNode(item, pnew);
    pnew->next = NULL;
    if(plist->head)
    {
        plist->end->next = pnew;
        plist->end = pnew;
    }
    else
    {
        plist->head = pnew;
        plist->end = pnew;
    }

    return true;
}

// visit each node and execute function pointed to by pfun
void Traverse (const List * plist, void (*pfun)(Item item))
{
    Node * pnode = plist->head;   // set to start of list

    while(pnode != NULL)
    {
        (*pfun)(pnode->item);     // apply function to item
        pnode = pnode->next;      // advance to next item
    }
}

// free memory allocated by malloc()
// set list pointer to NULL
void EmptyTheList(List * plist)
{
    Node * psave;

    while(plist->head != NULL)
    {
        psave = plist->head->next;     // save address of next node
        free(plist->head);             // free current node
        plist->head = psave;           // advance to next node
    }
}

// local function definition
// copies an item into a node
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;           // structure copy
}
