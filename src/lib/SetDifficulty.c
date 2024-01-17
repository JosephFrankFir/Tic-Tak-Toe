#include "../include/game.h"

int DifficultyLevel;


void SetDifficulty(void) {
    printf("Choose difficulty level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("4. Very hard\n");
    
    do {
        printf("Enter the number corresponding to your choice: ");
        scanf("%d", &DifficultyLevel);

        if (DifficultyLevel < 1 || DifficultyLevel > 4) {
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (DifficultyLevel < 1 || DifficultyLevel > 4);
}