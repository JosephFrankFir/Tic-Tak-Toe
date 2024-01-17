// MiniMax.c
#include "../include/game.h"

MoveScore Minimax(char *player, char mark, int depth) {
    MoveScore bestMove;
    bestMove.score = (strcmp(player, "player2") == 0) ? INT_MIN : INT_MAX;
    bestMove.move = -1;

    // Check if the game is over or depth limit reached
    if (CheckWin("player1") || CheckWin("player2") || CheckTie() || depth == 0) {
        bestMove.score = EvaluateBoard(depth);
        return bestMove;
    }

    // Iterate through available moves
    for (int i = 0; i < 9; ++i) {
        if (IsMarkAble[i]) {
            // Make the move
            MarkBoard(player, i + 1);

            // Recur with the other player
            MoveScore result = Minimax((strcmp(player, "player1") == 0) ? "player2" : "player1", (mark == 'X') ? 'O' : 'X', depth - 1);

            // Undo the move
            ClearBoard(i + 1);

            // Update the best move
            if ((strcmp(player, "player2") == 0 && result.score > bestMove.score) ||
                (strcmp(player, "player1") == 0 && result.score < bestMove.score)) {
                bestMove.score = result.score;
                bestMove.move = i + 1;
            }
        }
    }

    return bestMove;
}
