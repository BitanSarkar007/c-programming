#include<stdio.h>
#include<stdlib.h>

void bubblesort(int *a, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; i < n-1-i; i++)
        {
            /* code */
        }
        
    }
    
}

void printArray(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    
}

int main()
{
    int A[] = {23,245,2,25,56,32,3245};
    int n = 7;
    printd("Before sort\n");
    printArray(A, n);
    bubblesort(A, n);
    printd("After sort\n");
    printArray(A, n);
    return 0;
}