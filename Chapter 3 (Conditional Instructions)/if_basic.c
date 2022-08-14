#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a, b;
    printf("Enter a number: \n");
    scanf("%d", &a);

    if (a%2==0)
    {
        printf("The number is even\n");
    }
    else
    {
        printf("The numebr is odd\n");
    }

    return 0;
}