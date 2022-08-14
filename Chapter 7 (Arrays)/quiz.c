#include <stdio.h>
void display(int arr[3][3]);
int main()
{
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter value for row %d and column %d\n", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
    display(arr);
    /*  for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ",  arr[i][j]);
            }
            printf("\n");
        }
    }
    */
   return 0;
}
    void display(int arr[3][3])
    {

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ",  arr[i][j]);
            }
            printf("\n");
        }
    }
