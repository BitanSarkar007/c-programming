#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int size);

int LinearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    // Start searching
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

/*void sort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i + 1; i < size-i-1; i++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}*/

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void sort(int arr[], int size)
{
   int i, j;
   for (i = 0; i < size-1; i++)     
 
       // Last i elements are already in place  
       for (j = 0; j < size-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

int main()
{
    int arr[] = {1, 3, 5, 6, 56, 7, 67, 3467, 264, 82, 24};
    int size = sizeof(arr) / sizeof(int);
    int element = 24;
    int searchIndex = LinearSearch(arr, size, element);
    printf("The elemeny %d was found in index %d \n", element, searchIndex);
    sort(&arr[0], size);
    int bs = binarySearch(arr, size, element);
    printf("The elemeny %d was found in index %d \n", element, bs);
    return 0;
}