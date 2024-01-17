#include "../include/game.h"


void Game() {
    int pos;
    char term;
    if(!IsPlayer){
        SetDifficulty();
    }
    Clean();
    printf("\n     Tic Tac Toe\t\t\n");
    printf("Player1 (X) - Player2 (O)\n");
    DrawBoard();
    

    while (true) {
        printf("Player1 (X): ");
        if (scanf("%d%c", &pos, &term) != 2 || term != '\n') {
            fprintf(stderr, "Only digits allowed\n");
            exit(EXIT_FAILURE);
        } else if ((pos > 9) || (pos <= 0) || !IsMarkAble[pos - 1]) {
            fprintf(stderr, "Invalid move\n\n");
            UserInput(1, pos, 'X');
        } else {
            MarkBoard("player1", pos);
        }

        Clean();

        printf("\n     Tic Tac Toe\t\t\n");
        printf("Player1 (X) - Player2 (O)\n");
        DrawBoard();

        if (CheckWin("player1") == true) {
            printf("Player 1 won the game\n");
            break;
        }
        if (CheckTie() == true) {
            printf("Tie.\n");
            break;
        }

        // Player 2's turn
        if (IsPlayer) {
            printf("Player2 (O): ");
            if (scanf("%d%c", &pos, &term) != 2 || term != '\n') {
                fprintf(stderr, "Only digits allowed\n");
                exit(EXIT_FAILURE);
            } else if ((pos > 9) || (pos <= 0) || !IsMarkAble[pos - 1]) {
                fprintf(stderr, "Invalid move\n\n");
                UserInput(1, pos, 'O');
            } else {
                MarkBoard("player2", pos);
            }
        } else {
            // AI's turn using Minimax with the chosen difficulty level
            MoveScore aiMove;
            if (DifficultyLevel == 1) {
                aiMove = Minimax("player2", 'O', 3);  // Easy
            } else if (DifficultyLevel == 2) {
                aiMove = Minimax("player2", 'O', 6);  // Medium
            } else if (DifficultyLevel == 3){
                aiMove = Minimax("player2", 'O', 10); // Hard
            }
            else if (DifficultyLevel == 4){
                aiMove = Minimax("player2", 'O', 13); // Very hard
            }
            pos = aiMove.move;
            MarkBoard("player2", pos);
        }

        Clean();

        printf("\n     Tic Tac Toe\t\t\n");
        printf("Player1 (X) - Player2 (O)\n");
        DrawBoard();

        if (CheckWin("player2") == true) {
            printf("Player 2 won the game\n");
            break;
        }
        if (CheckTie() == true) {
            printf("Tie.\n");
            break;
        }
    }
}
