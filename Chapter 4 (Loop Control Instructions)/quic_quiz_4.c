#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,n;
    printf("Enter the value of n: \n");
    scanf("%d", &n);
    for (i=n; i; i--)
    {
        printf("The value of i is: %d\n", i);
    }
    
    return 0;
}