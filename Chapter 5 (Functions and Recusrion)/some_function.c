#include <stdio.h>
#include <stdlib.h>
int sum(int a, int b); // function prototype declaration

int main()
{
    int c = sum(2, 15);
    printf("The value of c is %d\n", c);
    return 0;
}

int sum(int a, int b)
{
    int result;
    result = a + b;
    return result;
}