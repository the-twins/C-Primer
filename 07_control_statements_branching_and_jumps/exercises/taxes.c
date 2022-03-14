// Write a program that requests the hours worked in a week and then prints the 
// gross pay, the taxes, and the net pay. Assume the following:
//    Basic pay rate = $10.00/hr
//    Overtime (in excess of 40 hours) = time and a half
//    Tax rate:  15% of the first $300, 20% of the next $150, 25% of the rest.
// Use #define constants, and don't worry if the example does not conform to current 
// tax law. 
#include <stdio.h>

#define PAYMENT 10
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25
#define BREAK1 300
#define BREAK2 450
#define BASE1 (RATE1 * BREAK1)
#define BASE2 (BASE1 +(RATE2 * (BREAK2 - BREAK1)))
#define OVER 15
#define FOR_40_HOURS 400

int main(void)
{
    double gross_pay;
    double net_pay;
    double hours;
    double taxes;

    printf("Enter the number of hours worked: \n");
    scanf("%lf", &hours);
    if (hours <= 40)
        gross_pay = hours * PAYMENT;
    else
        gross_pay = (hours - 40) * OVER + FOR_40_HOURS;
    if (gross_pay <= BREAK1)
        taxes = RATE1 * gross_pay;
    else if (gross_pay <= BREAK2)
        taxes = BASE1 + (RATE2 * (gross_pay - BREAK1));
    else
        taxes = BASE2 + (RATE3 * (gross_pay - BREAK2));
    printf("The gross pay = %.2lf, the taxes = %.2lf, and the net pay = %.2lf"
           ".\n", gross_pay, taxes, net_pay = gross_pay - taxes);

    return 0;
}
