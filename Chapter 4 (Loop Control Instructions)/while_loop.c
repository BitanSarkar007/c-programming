#include <stdio.h>
int main()
{
    int a;
    // printf("Enter how many times u want to repeat: ");
    scanf("%d", &a);
    while (a < 10)
    {
        printf("%d\n", a);
        a++;
    }
    return 0;
}