#include <stdio.h>
#include <stdlib.h>

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

void find(int a[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (a[i] == i)
        {
            printf("Element found at %d \n", i);
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
    quickSort(arr, 0, N - 1);
    printf("\n");
    printArr(arr, N);
    find(arr, N);
    return 0;
}