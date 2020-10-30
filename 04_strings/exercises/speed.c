// The program requests the download speed in megabits per second (Mbs) and
// the size of a file in megabytes(MB). The program should calculate the
// download time for the file. Note that in context one byte is eight bits.
// Use type float, and use / for division. The program should report all three
// values (download speed, file size, and download time) showing two digits
// to the right of the decimal point, as in the following:
// "At 18.12 megabits per second, a file of 2.20 megabytes
// downloads in 0.97 seconds."
#include <stdio.h>

int main(void)
{
    float mbs;
    float mb;
    float second;

    printf("Enter the download speed in megabits per second and the size ");
    printf("of a file in megabytes.\n");
    scanf("%f %f", &mbs, &mb);
    printf("At %.2f megabits per second, a file of %.2f megabytes\n", mbs, mb);
    printf("downloads in %.2f seconds.\n", mb * 8 / mbs);

    return 0;
}
