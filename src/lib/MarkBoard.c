#include "../include/game.h"



void MarkBoard(char *user, int pos)
{
    char symbol = ' ';

    // Checking the player

    if (strcmp(user, "player1") == 0)
    {
        symbol = 'X';
    }
    else if (strcmp(user, "player2") == 0)
    {
        symbol = 'O';
    }
    // Switch Case for marking the board
    switch (pos)
    {
    case 1:
        board[0][0] = symbol;
        IsMarkAble[0] = false;
        break;
    case 2:
        board[0][2] = symbol;
        IsMarkAble[1] = false;
        break;
    case 3:
        board[0][4] = symbol;
        IsMarkAble[2] = false;
        break;
    case 4:
        board[2][0] = symbol;
        IsMarkAble[3] = false;
        break;
    case 5:
        board[2][2] = symbol;
        IsMarkAble[4] = false;
        break;
    case 6:
        board[2][4] = symbol;
        IsMarkAble[5] = false;
        break;
    case 7:
        board[4][0] = symbol;
        IsMarkAble[6] = false;
        break;
    case 8:
        board[4][2] = symbol;
        IsMarkAble[7] = false;
        break;
    case 9:
        board[4][4] = symbol;
        IsMarkAble[8] = false;
        break;
    default:
        printf("Invalid move\n\n");
        break;
    }
}
