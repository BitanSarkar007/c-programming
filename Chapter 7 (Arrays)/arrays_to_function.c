#include <stdio.h>
#include <stdlib.h>
/* void printArray(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("The value of element %d is %d\n", i+1, *(ptr+i));
    }
 */
void printArray(int ptr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("The value of element %d is %d\n", i + 1, ptr[i]);
    }
    // ptr[2] = 5555; // this value will be changed in arr array of main as well
}
int main()
{
    int arr[] = {1, 65, 351, 562, 462, 653, 3};
    printArray(arr, 7);
    printf("%d\n", arr[2]);
    return 0;
}