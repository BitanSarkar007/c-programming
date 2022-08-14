#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(&a[i], &a[j]);
        }

    } while (i < j);

    swap(&a[low], &a[j]);
    return j;
}

void quickSort(int a[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        quickSort(a, low, (partitionIndex - 1));  // Sort left subarray
        quickSort(a, (partitionIndex + 1), high); // Sort right subarray
    }
}

void pair(int arr[], int arr2[], int n)
{
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] == arr2[j])
        {
            printf("Common data found: %d\n", arr[i]);
            i++;
            j++;
        }
        else if (arr[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", a[i]);
    }
    printf("\n");
}

int main()
{
    int N, i;
    printf("Enter the number of elements you want in both arrays: ");
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int));
    for (i = 0; i < N; i++)
    {
        printf("Enter your element: \n");
        scanf("%d", &arr[i]);
    }
    int *arr2 = (int *)malloc(sizeof(int));
    printf("Enter element for next array \n");
    for (i = 0; i < N; i++)
    {
        printf("Enter your element: \n");
        scanf("%d", &arr2[i]);
    }
    quickSort(arr, 0, N - 1);
    printf("\n");
    printArr(arr, N);
    printf("\n");
    quickSort(arr2, 0, N - 1);
    printArr(arr2, N);
    printf("\n");

    printf("**************\n\n\n");

    pair(arr, arr2, N);

    return 0;
}