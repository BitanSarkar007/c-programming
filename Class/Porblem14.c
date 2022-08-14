#include <stdio.h>
#include <stdlib.h>

int first_occurence(int arr[], int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first_occurence(arr, (mid + 1), high, x, n);
        else
            return first_occurence(arr, low, (mid - 1), x, n);
    }
    return -1;
}

int last_occurence(int arr[], int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last_occurence(arr, low, (mid - 1), x, n);
        else
            return last_occurence(arr, (mid + 1), high, x, n);
    }
    return -1;
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
    printf("Enter the value you wish to seach: ");
    scanf("%d", &val);
    int x1 = first_occurence(arr, 0, N - 1, val, N);
    int x2 = last_occurence(arr, 0, N - 1, val, N);
    printf("First occurence: %d\n", x1);
    printf("Last occurence: %d\n", x2);
    return 0;
}