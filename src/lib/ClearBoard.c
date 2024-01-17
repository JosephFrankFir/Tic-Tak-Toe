#include "../include/game.h"


void ClearBoard(int pos)
{
    switch (pos)
    {
    case 1:
        board[0][0] = ' ';
        IsMarkAble[0] = true;
        break;
    case 2:
        board[0][2] = ' ';
        IsMarkAble[1] = true;
        break;
    case 3:
        board[0][4] = ' ';
        IsMarkAble[2] = true;
        break;
    case 4:
        board[2][0] = ' ';
        IsMarkAble[3] = true;
        break;
    case 5:
        board[2][2] = ' ';
        IsMarkAble[4] = true;
        break;
    case 6:
        board[2][4] = ' ';
        IsMarkAble[5] = true;
        break;
    case 7:
        board[4][0] = ' ';
        IsMarkAble[6] = true;
        break;
    case 8:
        board[4][2] = ' ';
        IsMarkAble[7] = true;
        break;
    case 9:
        board[4][4] = ' ';
        IsMarkAble[8] = true;
        break;
    default:
        printf("Invalid move\n\n");
        break;
    }
}
