#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ptr;
    char c;
    ptr = fopen("getcdemo.txt", "r");
    c = fgetc(ptr);
    while (c!= EOF)
    {
       printf("%c", c);
       c = fgetc(ptr);
    }
    printf("\n");
    return 0;
}