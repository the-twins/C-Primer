// Write a function that sets each element in an array to the sum of corresponding
// elements in two other arrays. That is, if array 1 has the value 2,4,5 and 8 and array 2
// has the values 1, 0, 4, and 6, the function assigns array 3 the values 3, 4, 9, and 14. The
// function should take three array names and an array size as arguments. Test the function
// in a simple program.
#include <stdio.h>

void sum(int arr1[], int arr2[], int target[], int n);
void print(int target[], int n);

int main(void)
{
    int arr1[4] = {2, 4, 5, 8};
    int arr2[4] = {1, 0, 4, 6};
    int target[4];

    printf("The target array after calling sum():\n");
    sum(arr1, arr2, target, 4);
    print(target, 4);

    return 0;
}

void sum(int arr1[], int arr2[], int target[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        target[i] = arr1[i] + arr2[i];
}

void print(int target[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", target[i]);
    printf("\n");
}
