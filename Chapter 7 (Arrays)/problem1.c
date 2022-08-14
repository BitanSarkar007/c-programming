#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arr[10];
    int *ptr = &arr[0];
    ptr = ptr + 2;
    if (ptr == &arr[2])
    {
        printf("These point to the same location in memory\n");
    }
    else
    {
        printf("These point to the different location in memory\n");
    }
    
    
    return 0;
}