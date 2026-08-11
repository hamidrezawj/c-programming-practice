#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int secretNumber;
    int guess;
    int attempts = 0;

    // Initialize random number generator
    srand(time(NULL));

    // Generate a random number between 1 and 100
    secretNumber = rand() % 100 + 1;

    printf("=== Number Guessing Game ===\n");
    printf("I chose a number between 1 and 100.\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess < secretNumber)
        {
            printf("Too low!\n");
        }
        else if (guess > secretNumber)
        {
            printf("Too high!\n");
        }
        else
        {
            printf("Correct!\n");
            printf("You guessed the number in %d attempts.\n", attempts);
        }

    } while (guess != secretNumber);

    return 0;
}
