#include "../include/game.h"

int EvaluateBoard(int depth)
{
    if (CheckWin("player1"))
        return -10 + depth;
    else if (CheckWin("player2"))
        return 10 - depth;
    else if (CheckTie())
        return 0;

    // The game is still ongoing, return a score based on depth
    return depth;
}
