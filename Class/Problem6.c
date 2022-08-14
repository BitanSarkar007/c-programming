#include <stdio.h>
#include <stdlib.h>

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", a[i]);
    }
    printf("\n");
}

int localMin(int a[], int high, int low, int n)
{
    int mid = low + (high - low) / 2;
    if (mid == 0 || a[mid - 1] &&  a[mid + 1] > a[mid] || a[mid] == n - 1)
    {
        return mid;
    }
    else if (mid < 0 || a[mid - 1] > a[mid])
    {
        return localMin(a, low, mid - 1, n);
    }
    else
    {
        return localMin(a, mid + 1, high, n);
    }
}

int main()
{
    int N, i;
    printf("Enter the number of elements you want in array: ");
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int));
    for (i = 0; i < N; i++)
    {
        printf("Enter your element: \n");
        scanf("%d", &arr[i]);
    }
    printf("\n\n");
    printArr(arr, N);
    int x = localMin(arr, 0, N - 1, N);

    printf("Local minimum found at index: %d\n", x);
    return 0;
}