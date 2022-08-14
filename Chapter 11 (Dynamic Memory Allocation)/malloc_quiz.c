#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    int n;
    printf("How many integers do you want to enter: \n");
    scanf("%d", &n);
    // printf("The size of int on my pc is: %lu\n", sizeof(int));
    ptr =(int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of element %d: \n", i+1);
        scanf("%d", &ptr[i]);
    }
    free(ptr);
    for (int i = 0; i < n; i++)
    {
        printf("The value of element %d is: %d\n", i+1, ptr[i]);
        
    }
    
    return 0;
}