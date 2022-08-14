#include<stdio.h>
void goodMorning();
void goodAfternoon();
void goodNight();

int main()
{
    goodMorning();
    return 0;
}

void goodMorning()
{
    printf("Good morning Bitan\n");
    goodAfternoon();
}
void goodAfternoon()
{
    printf("Good afternoon Bitan\n");
    goodNight();
}
void goodNight()
{
    printf("Good night Bitan\n");
} 