#include<stdio.h>
#include<stdlib.h>
void pattern(int n);
int main()
{
    int n = 4;
    pattern(n);
    return 0;
}

void pattern(int n)
{
    if (n==1)
    {
        printf("*");
        return;
    }
    pattern(n-1);
    for (int i = 0; i < n; i++)
    {
        printf("*");
    }
    
    printf("\n");
}