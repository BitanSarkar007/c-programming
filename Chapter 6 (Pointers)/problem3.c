#include <stdio.h>
#include <stdlib.h>
int ten_times(int *a);
int main()
{
    int a;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("The value of a is: %d\n", a);
    ten_times(&a);
    printf("The new value of a is: %d\n", a);
    return 0;
}
int ten_times(int *a)
{
    *a = *a * 10;
    return *a;
}
