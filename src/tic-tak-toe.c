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
bool IsPlayer = false;
int main(int argc, char *argv[]) {
    Clean();
    if (argc > 1) {
        if (argc == 2 && strcmp("--player", argv[1]) == 0) {
        IsPlayer = true;
        }

        else if (argc == 2 && strcmp("--help", argv[1]) == 0){
            GetHelp();
        }
    } 
    else if (argc == 0) {
        fprintf(stderr, "Error: %s doesn't exist\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    Game();
    return EXIT_SUCCESS;
}

