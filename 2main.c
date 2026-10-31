#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int secret, guess, attempts = 0;

    srand((unsigned int)time(NULL));
    secret = rand() % 100 + 1;

    printf("\n=== NUMBER GUESSING GAME ===\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("Try to guess it!\n");

    do {
        printf("Your guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Please enter a whole number.\n");
            return 1;
        }

        attempts++;

        if (guess < 1 || guess > 100) {
            printf("Please choose a number from 1 to 100.\n");
        } else if (guess < secret) {
            printf("Too low. Try a higher number.\n");
        } else if (guess > secret) {
            printf("Too high. Try a lower number.\n");
        } else {
            printf("Correct! You guessed the number in %d attempt(s).\n", attempts);
        }
    } while (guess != secret);

    printf("Thanks for playing!\n");
    return 0;
}
