#include <stdio.h>
#include<stdlib.h>

int main()
{
    // Wap to check if a number is prime or not
    int a , prime =1;
    printf("Enter your number to check if it is prime or not: ");
    scanf("%d", &a);
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            prime = 0;
            break;
        }
    }
    if (prime == 0 && a!=2) 
        printf("This is not a prime number\n");
    else
        printf("Number is prime\n");
    return 0;
}