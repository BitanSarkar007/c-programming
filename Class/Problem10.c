#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int low, int high, int key)
{
    if (arr == NULL || high == 0)
    {
        return -1;
    }
    int left = low;
    int right = high - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] > arr[right])
        {
            left = mid + 1;
        }
        else
        {
            right = mid + 1;
        }
    }
    int start = left;
    left = 0;
    right = high - 1;
    if (key >= arr[start] && key <= arr[right])
    {
        left = start;
    }
    else
    {
        right = start;
    }

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[6] = {61, 85, 2, 8, 21, 32};
    int x = search(arr, 0, 6, 32);
    if (x == -1)
    {
        printf("Element not found in array\n");
    }
    else
    {
        printf("Element found at index: %d\n", x);
    }

    return 0;
}