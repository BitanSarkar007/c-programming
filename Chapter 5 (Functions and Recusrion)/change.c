#include <stdio.h>
#include <stdlib.h>
void change();

int main()
{
    int b = 344;
    printf("The value of b before change is %d\n", b);
    change();
    printf("The value of b after change is %d\n", b);
    return 0;
}

void change(int a)
{
    a = 77;
}