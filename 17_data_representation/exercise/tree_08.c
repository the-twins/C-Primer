// tree_08.c -- tree support functions
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree_08.h"

// local data type
typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;

// prototypes for local functions
static Trnode * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode(Trnode * new_node, Trnode * root);
static void InOrder(const Trnode * root, void (*pfun)(Item item));
static Pair SeekItem(const Tree  * ptree, const Item * pi);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode * ptr);
static int DeletePetkind(char arr[MAX_KIND][SLEN], char kind[SLEN], int n);

// function definitions
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
    if(ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree * ptree)
{
    if(ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
    Trnode * new_node;
    Pair look;
    look = SeekItem(ptree, pi);
    if(TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;             // early return
    }
    if(look.child != NULL)
    {
        strcpy(look.child->item.petkind[look.child->item.n], pi->petkind[0]);
        (look.child->item.n)++;
        ptree->size++;
        return true;
    }
    new_node = MakeNode(pi);      // points to new node
    if(new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;             // early return
    }
    // succeeded in creating a new node
    ptree->size++;

    if(ptree->root == NULL)       // case 1: tree is empty
        ptree->root = new_node;   // new node is tree root
    else
        AddNode(new_node, ptree->root); // add node to tree

    return true;                  // successful return
}

void FindWord(const Tree * ptree, const Item * pi)
{
    int i = 0;
    Pair look;
    look = SeekItem(ptree, pi);
    if(look.child != NULL)
    {
        printf("%s : ", look.child->item.petname);
        for(i = 0; i < look.child->item.n; i++)
            printf(" %s", look.child->item.petkind[i]);
        printf("\n");
    }
    else
        printf("Can't find the pet.\n");
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
    Pair look;
    look = SeekItem(ptree, pi);
    int i, j, item_comp;
    char temp[SLEN];
    strcpy(temp, pi->petkind[0]);
    if(look.child == NULL)
        return false;
    if(look.child->item.n == 1)
    {
        DeleteNode(&ptree->root);
        ptree->size--;
        return true;
    }
    item_comp = look.child->item.n;
    look.child->item.n = DeletePetkind(look.child->item.petkind, temp, look.child->item.n);
    if(item_comp != look.child->item.n && look.child->item.n != 0)
        ptree->size--;
    if(look.child->item.n < 1)
    {
        if(look.parent == NULL)
        {
            DeleteNode(&ptree->root);
            ptree->size--;
        }
        else if(look.parent->left == NULL)
        {
            DeleteNode(&look.parent->left);
            ptree->size--;
        }
        else if(look.parent->right == NULL)
        {
            DeleteNode(&look.parent->right);
            ptree->size--;
        }
    }
    return true;
}

void Traverse(const Tree * ptree, void (*pfun)(Item item))
{
    if(ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
    if(ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

// local functions
static void InOrder(const Trnode * root, void(*pfun)(Item item))
{
    if(root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Trnode * root)
{
    Trnode * pright;
    if(root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode(Trnode * new_node, Trnode * root)
{
    if(ToLeft(&new_node->item, &root->item))
    {
        if(root->left == NULL)     // empty subtree
            root->left = new_node; // so add node here
        else
            AddNode(new_node, root->left); // else process subtree
    }
    else if(ToRight(&new_node->item, &root->item))
    {
        if(root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else                          // should be no duplicates
    {
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}

static bool ToLeft(const Item * i1, const Item * i2)
{
    int comp1;
    if((comp1 = strcmp(i1->petname, i2->petname)) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
    int comp1;
    if((comp1 = strcmp(i1->petname, i2->petname)) > 0)
        return true;
    else
        return false;
}

static Trnode * MakeNode(const Item * pi)
{
    Trnode * new_node;
    new_node = (Trnode *) malloc(sizeof(Trnode));
    if(new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

static Pair SeekItem(const Tree * ptree, const Item * pi)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    if(look.child == NULL)
        return look;              // early return
    while(look.child != NULL)
    {
        if(ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if(ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else       // must be same if not to left or right
            break; // look.child is address of node with item
    }

    return look;
}

static void DeleteNode(Trnode **ptr)
// ptr is address of parent member pointing to target node
{
    Trnode * temp;
    if((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else      // delete node has two children
    {
        //find where to reattach right subtree
        for(temp = (*ptr)->left; temp->right != NULL;
            temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

static int DeletePetkind(char arr[MAX_KIND][SLEN], char kind[SLEN], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        if(strcmp(arr[i], kind) == 0)
        {
            for(j = i; j < n; j++)
                strcpy(arr[j], arr[j+1]);
            n--;
        }
    }
    return n;
} 
