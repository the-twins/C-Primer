// Write a program that shows you a menu offering you the choice of addition, subtraction,
// multiplication, or division. After getting your choice, the program asks for two numbers,
// then perfoms the requested operation. The program should accept only the offered
// menu choices. It should use type float for the numbers and allow the user to try again
// if he or she fails to enter a number. In the case of division, the program should prompt
// the user to enter a new value if 0 is entered as the value for the second number.
#include <stdio.h>

char get_choice(void);
char get_first(void);

float get_float(void);

void add(void);
void subtract(void);
void multiply(void);
void divide(void);

int main(void)
{
    int choice;
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
	{
	case 'a' : add();
		 break;
        case 's' : subtract();
		 break;
	case 'm' : multiply();
		 break;
        case 'd' : divide();
		 break;
        default : printf("Error!\n");
		break;
	}
    }
    printf("Bye.\n");
    return 0;
}

void add(void)
{
    float first, second;
    printf("Enter first number: \n");
    first = get_float();
    printf("Enter second number: \n");
    second = get_float();
    printf("%.2f + %.2f = %.2f\n", first, second, first + second);
    while (getchar() != '\n')
        continue;
}

void subtract(void)
{
    float first, second;
    printf("Enter first number: \n");
    first = get_float();
    printf("Enter second number: \n");
    second = get_float();
    printf("%.2f - %.2f = %.2f\n", first, second, first - second);
    while (getchar() != '\n')
        continue;
}

void multiply(void)
{
    float first, second;
    printf("Enter first number: \n");
    first = get_float();
    printf("Enter second number: \n");
    second = get_float();
    printf("%.2f * %.2f = %.2f\n", first, second, first * second);
    while (getchar() != '\n')
        continue;
}

void divide(void)
{
    float first, second;
    printf("Enter first number: \n");
    first = get_float();
    printf("Enter second number: \n");
    second = get_float();
    if (second == 0)
    {
        printf("Cannot be divided by 0. Enter another number: \n");
	second = get_float();
    }
    printf("%.2f / %.2f = %.2f\n", first, second, first / second);
    while (getchar() != '\n')
	continue;
}

char get_choice(void)
{
    int ch;
    printf("Enter the operation of your choice:\n");
    printf("a. add        s. subtract\n");
    printf("m. multiply   d. divide\n");
    printf("q. quit\n");
    ch = get_first();
    while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
    {
        printf("Please respond with a,s,m,d or q.\n");
	ch = get_first();
    }
    return ch;
}

char get_first(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;
    return ch;
}

float get_float(void)
{
    float input;
    char ch;
    while (scanf("%f", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
	    putchar(ch);
        printf(" is not correct, please enter a number, such as 2.5, -1.78E8, or 3: ");
    }
    return input;
}
