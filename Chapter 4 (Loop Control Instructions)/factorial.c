#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a, fact=1;
    printf("enter your number: \n");
    scanf("%d", &a);
    for (int i = 1; i <= a; i++)
    {
        fact*=i;
    }
    printf("Factorial of you number is: %d\n", fact);
    return 0;
}