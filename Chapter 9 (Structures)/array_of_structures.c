#include<stdio.h>
#include<string.h>

struct employee
{
    int code;
    float salary;
    char name[10];
};

int main()
{
    struct employee facebook[100];
    facebook[0].code = 100;
    facebook[0].salary = 5136.13;
    strcpy(facebook[0].name , "bitan");  
    return 0;
}