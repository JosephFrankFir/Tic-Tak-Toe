#include "../include/game.h"

int GetHelp(int argc, char *argv[])
{
        #ifdef _WIN32
            system("cls")
        #elif __LINUX__
            system("clear");
        #endif


    if (argc == 2 && strcmp("--help", argv[1]) == 0)
    {
        board[0][0] = '1';
        board[0][2] = '2';
        board[0][4] = '3';
        board[2][0] = '4';
        board[2][2] = '5';
        board[2][4] = '6';
        board[4][0] = '7';
        board[4][2] = '8';
        board[4][4] = '9';
        printf("\n   Tik Tak Toe Guide\t\t\n");
        DrawBoard();
        printf("\nType the the right number to mark the board.\n");
        printf("\nRULES FOR TIC-TAC-TOE\n1. The game is played on a grid that's 3 squares by 3 squares.\n2. You are X, your friend is O. Players take turns putting their marks in empty squares.\n3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\nTop-Left 	Top-Center 	Top-Right\nMiddle-Left 	Middle-Center 	Middle-Right\nBottom-Left 	Bottom-Center 	Bottom-Right\n\nHOW CAN I WIN AT TIC-TAC-TOE?\nTo beat the player (or at least tie), you need to make use of a little bit of strategy. Strategy means figuring out what you need to do to win.\nPart of your strategy is trying to figure out how to get three Xs in a row. The other part is trying to figure out how to stop the other player from getting three Os in a row.\nAfter you put an X in a square, you start looking ahead. Where's the best place for your next X? You look at the empty squares and decide which ones are good choices-which ones might let you make three Xs in a row.\nYou also have to watch where the other player puts its O. That could change what you do next. If the the other gets two Os in a row, you have to put your next X in the last empty square in that row, or the computer will win.You are forced to play in a particular square or lose the game.\nIf you always pay attention and look ahead, you'll never lose a game of Tic-Tac-Toe. You may not win, but at least you'll tie.\n");
        exit(0);
    }
    
    else if(argc == 2 && strcmp("--help", argv[1]))
    {
        fprintf(stderr, "Error: %s doesn't exist\n", argv[1]);
        exit(EXIT_FAILURE);
    }
}