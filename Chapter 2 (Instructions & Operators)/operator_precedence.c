#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 4;
    int y = 9;

    printf("The value of 3*x - 8*y is: %d\n", 3 * x - 8 * y);
    printf("The value of 8*y / 3*x is: %d\n", 8 * y / 3 * x);
    // 8*y / 3*x = 72/12 will give wrong answer
    // 72 / 3 * 4
    // 24 * 4 
    // 96 
    // Associativity or left to right is followed
    return 0;
}