// Find out what your system does with integer overflow, and floating-point
// overflow, and floating-point underflow by using the experimental approach.
// This program having these problems.
#include <stdio.h>

int main(void)
{
    short a = 32767;
    long b = 2147483647;
    long long c = 9223372036854775807;
    unsigned short d = 65535;
    unsigned long long e = 18446744073709551615;
    float g = 999999.88;

    printf("a = %hd, but it is mistake a + 1 = %hd.\n", a, a + 1);
    printf("b = %ld, but it is mistake b + 1 = %ld.\n", b, b + 1);
    printf("c = %lld, but it is mistake c + 1 = %lld.\n", c, c + 1);
    printf("d = %hu, but it is mistake d + 1 = %hu.\n", d, d + 1);
    printf("e = %llu, but it is mistake e + 1 = %llu.\n", e, e + 1);
    printf("g = %.2f, but it is mistake g + 0.1 = %.2f.\n", g, g + 1);

    return 0;
}
