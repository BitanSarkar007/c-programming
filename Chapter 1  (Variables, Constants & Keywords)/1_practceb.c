#include<stdio.h>
#include<stdlib.h>

int main()
{
    int length, breadth;
    printf("Enter the length of the rectangle: \n");
    scanf("%d", &length);
    printf("Enter the breadth of the rectangle: \n");
    scanf("%d", &breadth);

    printf("The area of the rectangle is: %d\n", length*breadth);
    return 0;
}