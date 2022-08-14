#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a=6;
    int *ptr;
    ptr = &a;
    printf("The address of variable a is %u\n", ptr);
    printf("The value of variable a is %u\n", *ptr);
    return 0;
}