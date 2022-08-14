#include <stdio.h>
#include <string.h>

struct employee
{
    int code;
    float salary;
    char name[10];
};

int main()
{
    struct employee e1, e2, e3;
    printf("Enter code for e1\n");
    scanf("%d", &e1.code);
    printf("Enter salary for e1\n");
    scanf("%f", &e1.salary);
    printf("Enter name for e1\n");
    scanf("%s", e1.name);

    printf("Enter code for e2\n");
    scanf("%d", &e2.code);
    printf("Enter salary for e2\n");
    scanf("%f", &e2.salary);
    printf("Enter name for e2\n");
    scanf("%s", e2.name);

    printf("Enter code for e3\n");
    scanf("%d", &e3.code);
    printf("Enter salary for e3\n");
    scanf("%f", &e3.salary);
    printf("Enter name for e3\n");
    scanf("%s", e3.name);

    return 0;
}