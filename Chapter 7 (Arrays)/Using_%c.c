#include<stdio.h>
#include<stdlib.h>

int main()
{
    char st1[34];
    char st2[34];
    int i = 0;
    printf("Enter the value of the first string\n");
    scanf("%s", st1);
    printf("Enter the value of the second string\n");
    char c;
    while (c!='\n')
    {
        fflush(stdin);
        scanf("%c", &c);
        st2[i]=c;
        i++;

    }
    st2[i-1] = '\0';

    printf("The value of st1 is %s\n", st1);
    printf("The value of st2 is %s\n", st2);
    
    return 0;
}