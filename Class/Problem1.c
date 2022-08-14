#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", a[i]);
    }
    printf("\n");
}

void bubbleSort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)

        for (int j = i + 1; j < n; j++)
            if (a[j] < a[i])
                swap(&a[i], &a[j]);
}

void insertionSort(int a[], int n)
{
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

void selectionSort(int a[], int n)
{
    int temp, indexOfMin;
    for (int i = 0; i < (n - 1); i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[indexOfMin])
                indexOfMin = j;
        swap(&a[i], &a[indexOfMin]);
    }
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

int lastpartition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    int j = l;
    for (j = l; j < h; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = lastpartition(a, low, high);
        quickSort(a, low, (partitionIndex - 1));  // Sort left subarray
        quickSort(a, (partitionIndex + 1), high); // Sort right subarray
    }
}

int maximum(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

void countSort(int a[], int n)
{
    int i, j;
    int max = maximum(a, n);

    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i < n; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }

    i = 0; // counter for count array
    j = 0; // counter for given array

    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    clock_t start, end;
    int i, ch, n;
    float t;
    for (n = 50000; n <= 150000; n += 10000)
    {
        int *arr = (int *)malloc(n * sizeof(int));
        srand(time(0));
        for (i = 0; i < n; i++)
        {
            arr[i] = rand() % 1000000 + 1;
        }
        start = clock();
        countSort(arr, n-1);
        end = clock();
        t = (float)(end - start) / CLOCKS_PER_SEC;
        printf("%.6f \n", t);
    }
    return 0;
}

