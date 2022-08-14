#include<stdio.h>

int strlen(char * st)
{
    char *ptr = st;
    int len = 0;
    while (*ptr!='\0')
    {
        len++;
        ptr++;
    }
    return len;
}


int main()
{
    char st[] = "Bitan";
    int l = strlen(st);
    printf("The length of this string is %d\n", l);
    return 0;
}