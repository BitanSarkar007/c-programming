#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a = 4;
    int b = 8;
    printf("The value of a+b is: %d\n", a+b);
    printf("The value of a-b is: %d\n", a-b);
    printf("The value of a*b is: %d\n", a*b);
    printf("The value of a/b is: %d\n", a/b);

    int z = a*b; //legal
    // b * a = z //Illegal
    printf("The value of z is :%d\n", z);

    printf("5 when devided by 2 leaves a remainder: %d\n", 5%2);
    printf("-5 when devided by 2 leaves a remainder: %d\n", -5%2);
    printf("5 when devided by -2 leaves a remainder: %d\n", 5%-2);
    printf("The value of 4 to the power 5 is: %f\n", pow(4,5));

    printf("The value of 6 + 5 is %d\n", 6 + 5);
    printf("The value of 6 + 5.6 is %f\n", 6 + 5.6);
    printf("The value of 6.1 + 5.6 is %f\n", 6.1 + 5.6);
    printf("The value of 2 / 5 is %f\n", 2.0 / 5);

    return 0;
}