// Guess the random number between 1 and 100
// gcc -o guess_number guess_number.c

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    int guess = -1;
    int guess_count = 0;

    // Generate random number
    srand(time(NULL));
    int rand_num = rand() % 100;

    while (guess != rand_num) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guess_count++;

        if (guess < rand_num) {
            printf("Higher\n");
        } else if (guess > rand_num) {
            printf("Lower\n");
        }
    }

    // Game over
    printf("You took %d guesses!\n", guess_count);
}
