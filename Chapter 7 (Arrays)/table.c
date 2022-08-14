#include <stdio.h>
#include <stdlib.h>
void printTable(int *mullTable, int num, int n)
{
    printf("The nultiplication table of %d is: \n", num);
    for (int i = 0; i < 10; i++)
    {
        mullTable[i] = num * (i + 1);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d * %d = %d\n", num, i + 1, mullTable[i]);
    }
    printf("******************************\n\n");
}
int main()
{
    int mullTable[3][10];
    printTable(mullTable[0], 2, 10);
    printTable(mullTable[1], 7, 10);
    printTable(mullTable[2], 9, 10);
    /* for (int i = 0; i < 10; i++)
     {
         mullTable[0][i] = 2 * (i + 1);
     }

     for (int i = 0; i < 10; i++)
     {
         printf("2 * %d = %d\n", i+1, mullTable[0][i]);
     }

      for (int i = 0; i < 10; i++)
     {
         mullTable[0][i] = 7 * (i + 1);
     }

     for (int i = 0; i < 10; i++)
     {
         printf("7 * %d = %d\n", i+1, mullTable[0][i]);
     }

      for (int i = 0; i < 10; i++)
     {
         mullTable[0][i] = 9 * (i + 1);
     }

     for (int i = 0; i < 10; i++)
     {
         printf("9 * %d = %d\n", i+1, mullTable[0][i]);
     }
 */
    return 0;
}