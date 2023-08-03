// Write a function that reverses the contents of an array of double and test it in a simple
// program.
#include <stdio.h>

void rev(double ar[], int n);
void print(double ar[], int n);

int main(void)
{
    double ar[5] = {1.3, 2.4, 3.5, 4.6, 5.8};
    rev(ar, 5);
    print(ar, 5);

    return 0;
}

void rev(double ar[], int n)
{
    int i, a;
    double intermed;
    for (i = 0, a = n-1; i < a; i++, a--)
    {
	intermed = ar[a];
	ar[a] = ar[i];
	ar[i] = intermed;
    }
}

void print(double ar[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%.2lf ", ar[i]);
    printf("\n");
}
