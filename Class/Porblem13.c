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

int common(int a[], int size)
{
    int i = 0;
    while (i < size)
    {
        if (a[i] == a[i + 1])
        {
            return a[i];
        }
        else
        {
            i++;
        }
    }

    return 0;
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
    int N, i, val;
    printf("Enter the number of elements you want in the array: ");
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int));
    for (i = 0; i < N; i++)
    {
        printf("Enter your element: \n");
        scanf("%d", &arr[i]);
    }
    printf("\n");
    quickSort(arr, 0, N - 1);
    printArr(arr, N);
    printf("\n");
    int result = common(arr, N);
    if (result == 0)
    {
        printf("No common element found!!\n");
    }
    else
    {
        printf("Equal element found is: %d\n", result);
    }

    return 0;
}