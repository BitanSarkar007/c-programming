#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *ptr;
    int number = 45;
    ptr = fopen("generated.txt", "w");
    fprintf(ptr, "The number is %d\n", number);
    fprintf(ptr, "Thanks for using fprintf");
    fclose(ptr);
    return 0;
}