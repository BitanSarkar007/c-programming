#include <stdio.h>
#include <stdlib.h>

int fibbonacci(int n);
int main()
{
    int n;
    printf("Enter the term excluding 0: ");
    scanf("%d", &n);
    printf("Fibonacci series for n terms is: %d\n", fibbonacci(n));

    return 0;
}
int fibbonacci(int n)
{
    // printf("calling factorial(%d)\n", n);
    
    if (n == 0 || n == 1)
    {
        return -(n - 1);
    }

    else
    {
        return fibbonacci(n - 1) + fibbonacci(n - 2);
    }
}