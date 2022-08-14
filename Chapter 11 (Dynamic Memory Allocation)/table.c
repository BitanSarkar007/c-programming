#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    // printf("The size of int on my pc is: %lu\n", sizeof(int));
    ptr = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        ptr[i] = 7 * (i + 1);
        printf("The value of element 7 * %d is: %d\n", i + 1, ptr[i]);
    }

    // Reallocate ptr using realloc()
    
    ptr = realloc(ptr, 15 * sizeof(int));

    printf("\n\n After reallocating......\n\n\n");

    for (int i = 0; i < 15; i++)
    {
        ptr[i] = 7 * (i + 1);
        printf("The value of element 7 * %d is: %d\n", i + 1, ptr[i]);
    }

    return 0;
}