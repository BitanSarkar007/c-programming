#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *ptr;
    ptr = fopen("sample.txt", "r"); //--> For reading the file
    //ptr = fopen("sample.txt", "w"); //--> For writing to a file
    return 0;
}