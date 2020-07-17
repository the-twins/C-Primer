// have the program use two user-defined function in addition to main(): one named br() that prints "Brazil, Russia" once, and named ic() that prints "India, China" once. Let main() take care of any additional printing tasks.
#include <stdio.h>

void br(void);
void ic(void);

int main(void)
{
    printf("Brazil, Russia, India, China\n");
    ic();
    br();
    
    return 0;
}

void ic(void)
{
    printf("India, China\n");
}

void br(void)
{
    printf("Brazil, Russia\n");
}
