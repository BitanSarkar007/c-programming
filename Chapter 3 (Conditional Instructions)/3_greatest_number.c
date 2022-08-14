#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Wap to print greatest of 4 numbers
    printf("Enter 4 numbers :\n");
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    if (a > b && b > c && c > d)
        printf("Greatest number is: %d\n", a);
    if (b > a && b > c && b > d)
        printf("Greatest number is: %d\n", b);
    if (c > a && c > b && c > d)
        printf("Greatest number is: %d\n", c);
    if (d > a && d > b && d > c)
        printf("Greatest number is: %d\n", d);
        
    return 0;
}