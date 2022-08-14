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
    int a = 34;
    char b = 'g';
    float d  = 432.1341;

    struct employee e1;
    e1.code = 100;
    e1.salary = 6779.68;
    // e1.name = "Bitan"; --> Won't work
    strcpy(e1.name, "Bitan");

    printf("%d\n", e1.code);
    printf("%f\n", e1.salary);
    printf("%s\n", e1.name);

    return 0;
}