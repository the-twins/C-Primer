// Modify Programming Exercise 8 from Chapter 7 so that the menu choices are labeled by
// characters instead of by numbers; use 'q' instead of 5 as the cue to terminate input.
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
    printf("a) $8.75/hr   b) $9.33/hr\n");
    printf("c) $10.00/hr  d) $11.20/hr\n");
    printf("q) quit\n");
    while ((ch = getchar()) != 'q')
    {
        switch (ch)
        {
            case 'a' :
               payment = PAYMENT1;
                break;
            case 'b' :
               payment = PAYMENT2;
                break;
            case 'c' :
               payment = PAYMENT3;
                break;
            case 'd' :
               payment = PAYMENT4;
                break;
            default :
                printf("Enter the number corresponding to the desired pay rate or action:\n");
                printf("a) $8.75/hr   b) $9.33/hr\n");
                printf("c) $10.00/hr  d) $11.20/hr\n");
                printf("q) quit\n");
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
        
