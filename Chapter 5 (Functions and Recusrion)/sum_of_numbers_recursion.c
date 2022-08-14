#include<stdio.h>

int sum(int n);
int main()
{
    int n;
    printf("Enter the value of n: \n");
    scanf("%d", &n);
    printf("Sum of first %d natural numbers is: %d\n",n, sum(n));
    return 0;
}
int sum(int n)
{
    int x = n; 
    if (x!= 0)
    {
       return n + sum(n-1);
    }
    else
    {
        return 0;
    }
    
}