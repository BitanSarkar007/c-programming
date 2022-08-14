#include<stdio.h>
#include<string.h>
int main()
{
    char s [34];
    printf("Enter you name: ");
    gets(s);
    puts(s);
    printf("Your name is %s\n", s);
    int a = strlen(s);
    printf("The length of the string is: %d\n", a);
    return 0;
}