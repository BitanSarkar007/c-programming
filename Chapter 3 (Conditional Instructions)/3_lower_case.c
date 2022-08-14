#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 97-122 = a-z ASCII Values
    char ch;
    printf("Enter your character: ");
    scanf("%c", &ch);
    if (ch <= 122 && ch >= 97)
        printf("It is a lower case\n");
    else
        printf("Not lower case\n");
    return 0;
}