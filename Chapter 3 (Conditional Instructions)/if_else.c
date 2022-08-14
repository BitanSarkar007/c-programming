#include<stdio.h>
#include<stdlib.h>

int main()
{
    int age;
    printf("Enter your age: \n");
    scanf("%d", &age);
    if(age>90){
        printf("You are above 70 and can't drive\n");

    }
    else
    {
        printf("You can drive\n");
    }
    
    return 0;
}