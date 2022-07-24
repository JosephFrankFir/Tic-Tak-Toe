#include "../include/game.h"

void DrawBoard(void)
{
    // Looping through board array
    for (int i = 0; i < 5; i++)
    {
        printf("\t");
        for (int k = 0; k < 5; k++)
        {
            printf("%c", board[i][k]);
        }
        printf("\n");
    }
}

