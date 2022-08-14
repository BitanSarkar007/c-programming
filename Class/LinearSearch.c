#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LinearSearch(int A[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == k)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    clock_t start = clock();

    int key, x;
    printf("Enter value for k\n");
    scanf("%d", &key);
    int *A = (int *)malloc(x * sizeof(int));
    int out = LinearSearch(A, x, key);
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime Taken : %.20f\n", elapsed);
    return 0;
}