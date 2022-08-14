#include<stdio.h>
#include<stdlib.h>

int main()
{
    // Wap to check if a number is divisble by 97 or not
   /* int a;
    printf("Enter the number: ");
    scanf("%d", &a);
    printf("Results: %d\n" , a%97); */

    // Step by step evaluation of 3*x/y-z+k
    int x = 2, y = 3, z=3, k=1;

    int res = 3*x/y-z+k;

    // 6/3 - 3 + 1
    // 2 - 3 + 1
    // 0
    printf("The result is: %d\n", res);

    return 0;
}