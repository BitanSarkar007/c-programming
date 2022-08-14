#include<stdio.h>
#include<stdlib.h>

int sum(int a[], int size, int val)
{
    int l = 0;
    int h = size - 1;
    while (l<h)
    {
        if (a[l] + a[h] == val)
        {
            return 1;
        }
        else if (a[l] + a[h] < val)
        {
            l++;
        }
        else
        {
            h--;
        }
        
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
    printf("Enter the sum to be searched in the array: \n");
    scanf("%d",&val);
    int result = sum(arr, N, val);
    if (result == 1)
    {
        printf("Pair found!! \n");
    }
    else
    {
        printf("Pair not found!! \n");
    }
    
    return 0;
}