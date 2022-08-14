#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Wap to pront n natural numbers using do-while loop
    int n, i;
    printf("Enter the value of a: \n");
    scanf("%d", &n);
    do
    {
        printf("%d\n", i);
        i++;
    } while (i <= n);

    return 0;
}