// Modify assumption in exercise 7 so that the program presents a menu of pay 
// rates from which to choose. Use a switch to select the pay rate. The 
// beginning of a run should look something like this:
// *****************************************************************
// Enter the number corresponding to the desired pay rate or action:
// 1) $8.75/hr   2) $9.33/hr
// 3) $10.00/hr  4) $11.20/hr 
// 5) quit
// *****************************************************************
// If choices 1 through 4 are selected, the program should request the hours 
// worked. The program should recycle until 5 is entered. If something other 
// than choices 1 through 5 is entered, the program should remind the user what
// the proper choices are and then recycle. Use #defined constants for the 
// various earning rates and tax rates.

#include <stdio.h>

#define PAYMENT1 8.75
#define PAYMENT2 9.33
#define PAYMENT3 10.00
#define PAYMENT4 11.20
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25
#define BREAK1 300
#define BREAK2 450
#define BASE1 (RATE1 * BREAK1)
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1)))
#define OVER 1.5
#define HOURS_PER_WEEK 40

int main(void)
{
    float gross_pay;
    float net_pay;
    float hours;
    float taxes;
    float payment;
    char ch;
    
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr   2) $9.33/hr\n");
    printf("3) $10.00/hr  4) $11.20/hr\n");
    printf("5) quit\n");
    while ((ch = getchar()) != '5')
    {
        switch (ch)
        {
            case '1' : 
               payment = PAYMENT1;
                break;
            case '2' : 
               payment = PAYMENT2; 
                break;
            case '3' : 
               payment = PAYMENT3;
                break;
            case '4' : 
               payment = PAYMENT4;
                break;
            default : 
                printf("Enter the number corresponding to the desired pay rate or action:\n");
                printf("1) $8.75/hr   2) $9.33/hr\n");
                printf("3) $10.00/hr  4) $11.20/hr\n");
                printf("5) quit\n");
                continue;
        }
        printf("Enter the number of hours worked: \n");
        scanf("%f", &hours);
        if (hours <= HOURS_PER_WEEK)
            gross_pay = hours * payment;
        else
            gross_pay = ((hours - HOURS_PER_WEEK) * OVER * payment) + (HOURS_PER_WEEK * payment);
        if (gross_pay <= BREAK1)
            taxes = RATE1 * gross_pay;
        else if (gross_pay <= BREAK2)
            taxes = BASE1 + (RATE2 * (gross_pay - BREAK1));
        else
            taxes = BASE2 + (RATE3 * (gross_pay - BREAK2));
        printf("The gross pay = %.2f, the taxes = %.2f, and the net pay = %.2f"
               ".\n", gross_pay, taxes, net_pay = gross_pay - taxes);
    }

    return 0;
}
