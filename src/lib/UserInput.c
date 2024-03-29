#include "../include/game.h"

void UserInput(int ply_num, int pos, char symbol)
{
    while (pos <= 0 || pos > 9 || !IsMarkAble[pos - 1]) {
        fprintf(stderr, "Invalid move\n\n");
        printf("Player%d (%c): ", ply_num, symbol);
        scanf("%d", &pos);
    }

    if (symbol == 'X') {
        MarkBoard("player1", pos);
    } else if (symbol == 'O') {
        MarkBoard("player2", pos);
    } else {
        fprintf(stderr, "ERR: SYMBOL DOESN'T EXIST");
        exit(EXIT_FAILURE);
    }

    DrawBoard();
}
