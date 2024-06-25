// Write a program that implements a menu by using an array of pointers to function. For
// instance, choosing a from the menu would activate the function pointed to by the first
// element of the array.
#include <stdio.h>
#include <string.h>

int showmenu(void);
void show(double (*fp)(double i, double j));
double Addition(double i, double j);
double Subtraction (double i, double j);
double Multiply(double i, double j);
double Division(double i, double j);

int main(void)
{
    int index;
    double(*fp[4])(double, double) = {Addition, Subtraction, Multiply, Division};
    index = showmenu();
    while(index >= 0 && index <= 3)
    {
        show(*fp[index]);
        index = showmenu();
    }

    return 0;
}

int showmenu(void)
{
    int ans;
    printf("Enter menu choice:\n");
    printf("0)Addition       1)Subtraction\n");
    printf("2)Multiplication  3)Division\n");
    printf("If you want to exit, enter any other number or letter.\n");
    if(scanf("%d", &ans) && ans >= 0 && ans <= 3)
        return ans;
    else
        printf("Bye.\n");
}

double Addition(double i, double j)
{
    return i + j;
}

double Subtraction(double i, double j)
{
    return i - j;
}

double Multiply(double i, double j)
{
    return i * j;
}

double Division(double i, double j)
{
    return i / j;
}

void show(double (*fp) (double i, double j))
{
    double i, j;
    printf("Enter two numbers:");
    if(scanf("%lf %lf", &i, &j) == 2)
        printf("%.2lf\n", (*fp)(i, j));
}
