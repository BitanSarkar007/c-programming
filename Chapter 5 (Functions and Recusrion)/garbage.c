#include <stdio.h>

void display();

int main()
{
    for (int i = 0; i < 100; i++)
    {
        display();
    }

    return 0;
}

void display()
{
    printf("My name is Bitan\n");
}