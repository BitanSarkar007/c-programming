#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number, guess, nguess = 1;
    srand(time(0));
    number = rand() % 100 + 1;
    printf("Guess the number between 1 and 100: \n");
    // printf("The number is: %d\n", number);
    // Keep runnign the program till the number is guessed
    do
    {
        printf("Guess the number between 1 to 10\n");
        scanf("%d", &guess);
        if (guess > number)
        {
            printf("Try something lower\n");
        }

        else if (guess < number)
        {
            printf("Try something higher\n");
        }
        else
        {
            printf("You guessed in %d times!!\n", nguess);
        }
        nguess++;
    } while (guess != number);

    return 0;
}