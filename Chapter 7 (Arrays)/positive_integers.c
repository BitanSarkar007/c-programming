#include<stdio.h>
#include<stdlib.h>

int main()
{
    int count = 0;
    int arr[10] = {2,4,-7,1,-8,13,-13,-14, 8, -10};
    for (int i = 0; i < 10; i++)
    {
        if (arr[i]<0)
        {
             count ++;
        }
        
    }
    printf("The number of positive integers in array is %d\n", count);
    
    return 0;
}