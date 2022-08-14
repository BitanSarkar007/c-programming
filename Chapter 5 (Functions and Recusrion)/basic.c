#include<stdio.h>
#include<stdlib.h>
void display(); // Function prototype

int main()
{
    int a;
    printf("Intitializing display function\n");
    display(); // Function call
    printf("Display finised it's work\n");
    return 0;
}

// Function definition
void display()
{
    printf("This is display\n");
}