#include <stdio.h>
#include <stdlib.h>

void bubbleSort(float a[], int *n)
{
    int temp;
    for (int i = 0; i < *(n); i++)
    {
        for (int j = i + 1; j < *(n); j++)
        {
            if (a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int binarySearch(float arr[], int size, float val)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    float k;
    // Keep searching until low <= high
    while (low <= high)
    {
        mid = (low + high) / 2;
        k = arr[mid] - val;

        if (k < 0)
        {
            k = -k;
        }
        
        if (k<= 0.00001)
            return mid;

        if (arr[mid] < val)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n, i;
    float p;
    int result;
    printf("Enter the number of values you want in an array: \n");
    scanf("%d", &n);
    float arr[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter your value: \n");
        scanf("%f", &arr[i]);
    }
    bubbleSort(arr, &n);
    for (i = 0; i < n; i++)
    {
        printf("value is: %f \n", arr[i]);
    }
    printf("Enter the value you wish to search: \n");
    scanf("%f", &p);
    result = binarySearch(arr, n, p);
    if (result == -1)
    {
        printf("Value is not present in array\n");
    }
    else
    {
        printf("Value is present in array at index %d \n", result);
    }

    return 0;
}