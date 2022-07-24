#include "../include/game.h"

bool CheckWin(char *player)
{
    char symbol = ' ';

    // Checking for the player

    if (strcmp(player, "player1") == 0)
    {
        symbol = 'X';
    }
    else if (strcmp(player, "player2") == 0)
    {
        symbol = 'O';
    }
    // Checking for that possesions

    if (board[0][0] == symbol && board[0][2] == symbol && board[0][4] == symbol)
    {
        return true;
    }
    else if (board[2][0] == symbol && board[2][2] == symbol && board[2][4] == symbol)
    {
        return true;
    }
    else if (board[4][0] == symbol && board[4][2] == symbol && board[4][4] == symbol)
    {
        return true;
    }
    else if (board[0][0] == symbol && board[2][2] == symbol && board[4][4] == symbol)
    {
        return true;
    }
    else if (board[0][4] == symbol && board[2][2] == symbol && board[4][0] == symbol)
    {
        return true;
    }
    else if (board[0][0] == symbol && board[2][0] == symbol && board[4][0] == symbol)
    {
        return true;
    }
    else if (board[0][2] == symbol && board[2][2] == symbol && board[4][2] == symbol)
    {
        return true;
    }
    else if (board[0][4] == symbol && board[2][4] == symbol && board[4][4] == symbol)
    {
        return true;
    }

    return false;
}
