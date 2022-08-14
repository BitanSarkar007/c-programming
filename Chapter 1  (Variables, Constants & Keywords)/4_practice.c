#include<stdio.h>
#include<stdlib.h>

int main()
{
    int principal = 100, rate = 12, years = 20;
    int simpleInterest = (principal * rate * years);
    printf("The value of simple Interest is %d", simpleInterest);
    return 0;
}