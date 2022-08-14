#include <stdio.h>
#include <stdlib.h>
int sum(int a, int b);
int main()
{
    int a = 4, b = 7;
    printf("The value of a and b is %d and %d\n", a, b);
    printf("The value of 4+7 is %d\n", sum(a, b));
    printf("The value of a and b after function call is %d and %d\n", a, b);
    return 0;
}
int sum(int a, int b)
{
    int c;
    c = a + b;
    // a = 3784;
    // b = 3647;
    return c;
}