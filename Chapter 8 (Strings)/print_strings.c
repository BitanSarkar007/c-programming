#include<stdio.h>
int main()
{
    char str[]= "Bitan";
    char *ptr = str;
    /*while (*ptr!='\0')
    {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");*/
    printf("%s\n", ptr);
    char s [34];
    printf("Enter you name: ");
    scanf("%s", s);
    printf("Your name is %s\n", s);    
    return 0;
}