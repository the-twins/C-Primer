// The 1988 United States Federal Tax Schedule was the simplest in recent 
// times. It had four categories, and each category had two rates. Here is a 
// summary (dollar amounts are taxable income):
// Single: 15% of first $17,850 plus 28% of excess 
// Head of Household: 15% of first $23,900 plus 28% of excess 
// Married, Joint: 15% of first $29,750 plus 28% of excess
// Married, Separate: 15% of first $14,875 plus 28% of excess
// For example, a single wage earner with a taxable income of $20,000 owes 
// 0.15 × $17,850 + 0.28 × ($20,000-$17,850). Write a program that lets the 
// user specify the tax category and the taxable income and that then calculates
// the tax. Use a loop so that the user can enter several tax cases. 
#include <stdio.h>

#define RATE1 0.15
#define RATE2 0.28
#define TAX_BREAK_1 17850.0
#define TAX_BREAK_2 23900.0
#define TAX_BREAK_3 29750.0
#define TAX_BREAK_4 14875.0

int main(void)
{
    float tax_break;
    float salary;
    float net_pay;
    float taxes;
    char category;

    printf("Enter the number of your category:\n");
    printf("1) Single (15%% of first $17,850 plus 28%% of excess)\n");
    printf("2) Head of Household (15%% of first $23,900 plus 28%% of excess)\n");
    printf("3) Married, Joint (15%% of first $29,750 plus 28%% of excess)\n");  
    printf("4) Married, Separate (15%% of first $14,875 plus 28%% of excess)\n");
    printf("5) quit\n");
    while ((category = getchar()) != '5')
    {
        switch (category)
        {
            case '1' : tax_break = TAX_BREAK_1;
                     break;
            case '2' : tax_break = TAX_BREAK_2;
                     break;
            case '3' : tax_break = TAX_BREAK_3;
                     break;
            case '4' : tax_break = TAX_BREAK_4;
                     break;
            default : 
            printf("Enter the number of your category or quit:\n");
            continue;
        }
        printf("Enter your salary: \n");
        scanf("%f", &salary);
        if (salary > tax_break)
            taxes = (RATE1 * tax_break) + (RATE2 * (salary - tax_break));
        else
            taxes = RATE1 * salary;
        printf("The gross pay = %.2f, the taxes = %.2f, and the net pay = %.2f"
               ".\n", salary, taxes, net_pay = salary - taxes);
    }
    
    return 0;
}
