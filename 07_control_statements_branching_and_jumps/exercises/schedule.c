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

int main(void)
{
    float gross_pay;
    float salary;
    float net_pay;
    float taxes;
    char rate;

    printf("Enter the number of your category:\n");
    printf("1) Single (15%% of first $17,850 plus 28%% of excess)\n");
    printf("2) Head of Household (15%% of first $23,900 plus 28%% of excess)\n");
    printf("3) Married, Joint (15%% of first $29,750 plus 28%% of excess)\n");  
    printf("4) Married, Separate (15%% of first $14,875 plus 28%% of excess)\n");
    printf("5) quit\n");
    while ((rate = getchar()) != '5')
    {
        switch (rate)
        {
            case '1' : gross_pay = 17850;
                     break;
            case '2' : gross_pay = 23900;
                     break;
            case '3' : gross_pay = 29750;
                     break;
            case '4' : gross_pay = 14875 ;
                     break;
            default : 
            printf("Enter the number of your category:\n");
            printf("1) Single (15%% of first $17,850 plus 28%% of excess)\n");
            printf("2) Head of Household (15%% of first $23,900 plus 28%% of excess)\n");
            printf("3) Married, Joint (15%% of first $29,750 plus 28%% of excess)\n");
            printf("4) Married, Separate (15%% of first $14,875 plus 28%% of excess)\n");
            printf("5) quit\n");
            continue;
        }
        printf("Enter your salary: \n");
        scanf("%f", &salary);
        taxes = (RATE1 * gross_pay) + (RATE2 * (salary - gross_pay));
        printf("The gross pay = %.2f, the taxes = %.2f, and the net pay = %.2f"
               ".\n", salary, taxes, net_pay = salary - taxes);
    }
    
    return 0;
}
