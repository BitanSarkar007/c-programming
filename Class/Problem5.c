#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", a[i]);
    }
    printf("\n");
}

void insertionSort(int a[], int n)
{
    printf("Running insertion sort.....\n");
    int key, j;
    for (int i = 1; i < (n - 1); i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int fun(int a[], int n)
{
    int i, k, j, x;
    for (i = 0; i < n - 2; i++)
    {
        j = i+1;
        k = n-1;
        while (j < k)
        {
            x = a[j] + a[k] + a[i];
            if (x == 0)
            {
                return 1;
            }
            
            else if (x < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return -1;
}

int main()
{
    int N, i, k, j, x;
    printf("Enter the number of elements you want in array: ");
    scanf("%d", &N);
    srand(time(0));
    int *arr = (int *)malloc(sizeof(int));
    for (i = 0; i < N; i++)
    {
        printf("Enter your element: \n");
        scanf("%d",&arr[i]);
    }
    // int arr[7] = {-5, -2, 2, 1, 3, 5, 7};
    printArr(arr, N);
    insertionSort(arr, N);
    printArr(arr, N);
    int value = fun(arr, N);
    if (value == 1)
    {
        printf("Sum is zero!!\n");
    }
    else
    {
        printf("Sum is not zero!!\n");
    }

    return 0;
}