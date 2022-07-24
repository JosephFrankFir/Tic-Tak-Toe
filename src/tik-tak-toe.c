/*
 * Author: Joseph
 * Date: July 2 2022
 * License: MIT
 */

#include "./include/game.h"

char board[5][5] =
{
        {' ', '|', ' ', '|', ' '},
        {'-', '+', '-', '+', '-'},
        {' ', '|', ' ', '|', ' '},
        {'-', '+', '-', '+', '-'},
        {' ', '|', ' ', '|', ' '}
};
bool IsMarkAble[9] = {true, true, true, true, true, true, true, true, true};

int main(int argc, char *argv[])
{
    GetHelp(argc, argv);
    Game();
    if (argc == 2 && strcmp("--save", argv[1]))
    {
        SaveBoard(true ,board);
    }
    return EXIT_SUCCESS;
}