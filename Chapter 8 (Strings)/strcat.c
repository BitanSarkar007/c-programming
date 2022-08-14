#include<stdio.h>
#include<string.h>

int main()
{
    char *st2 = "Bitan";
    char st1[45] = "Hello! ";
    strcat(st1, st2);
    printf("Now the st2 is \n%s\n", st1);
    return 0;
}