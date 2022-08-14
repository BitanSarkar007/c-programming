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
    struct employee bitan = {100,32.23,"bitan"};

    printf("Code is: %d\n", bitan.code);
    printf("Salary is: %.3f\n", bitan.salary);
    printf("Name is: %s\n", bitan.name);

    return 0;
}