/*
 * Author: Joseph
 * Date: July 2 2022
 * License: MIT
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define fucntions

void Game(void);
void DrawBoard(void);
void MarkBoard(char *user, int pos);
bool CheckWin(char *user);
bool CheckTie(void);
void UserInput(int ply_num, int pos, char symbol);

// 3x3 array

char board[5][5] =
    {
        {' ', '|', ' ', '|', ' '},
        {'-', '+', '-', '+', '-'},
        {' ', '|', ' ', '|', ' '},
        {'-', '+', '-', '+', '-'},
        {' ', '|', ' ', '|', ' '}};

bool IsMarkAble[9] = {true, true, true, true, true, true, true, true, true};

// The main function

int main(int argc, char *argv[])
{
    system("clear");
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
    else if (argc == 2 && strcmp("--help", argv[1]))
    {
        fprintf(stderr, "Error: %s doesn't exist\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    Game();

    return EXIT_SUCCESS;
}

// The game function that contains all the other functions

void Game(void)
{
    int pos;
    char term;
    printf("\n     Tik Tak Toe\t\t\n");
    printf("Player1 (X) - Player2 (O)\n");
    DrawBoard();

    while (true)
    {
        printf("Player1 (X): ");
        if (scanf("%d%c", &pos, &term) != 2 || term != '\n')
        {
            fprintf(stderr, "Only degits allowed\n");
            exit(EXIT_FAILURE);
        }

        if (IsMarkAble[0] == false && pos == 1 || IsMarkAble[1] == false && pos == 2 || IsMarkAble[2] == false && pos == 3 || IsMarkAble[3] == false && pos == 4 || IsMarkAble[4] == false && pos == 5 || IsMarkAble[5] == false && pos == 6 || IsMarkAble[6] == false && pos == 7 || IsMarkAble[7] == false && pos == 8 || IsMarkAble[8] == false && pos == 9)
        {
            printf("Invalid move\n\n");
            UserInput(1, pos, 'X');
        }
        else
        {
            MarkBoard("player1", pos);
        }
        system("clear");
        printf("\n     Tik Tak Toe\t\t\n");
        printf("Player1 (X) - Player2 (O)\n");
        DrawBoard();
        if (CheckWin("player1") == true)
        {
            printf("Player 1 won\n");
            break;
        }
        if (CheckTie() == true)
        {
            printf("Tie.\n");
            break;
        }

        printf("Player2 (O): ");
        if (scanf("%d%c", &pos, &term) != 2 || term != '\n')
        {
            fprintf(stderr, "Only degits allowed\n");
            exit(EXIT_FAILURE);
        }

        if (IsMarkAble[0] == false && pos == 1 || IsMarkAble[1] == false && pos == 2 || IsMarkAble[2] == false && pos == 3 || IsMarkAble[3] == false && pos == 4 || IsMarkAble[4] == false && pos == 5 || IsMarkAble[5] == false && pos == 6 || IsMarkAble[6] == false && pos == 7 || IsMarkAble[7] == false && pos == 8 || IsMarkAble[8] == false && pos == 9)
        {
            printf("Invalid move\n\n");
            UserInput(2, pos, 'O');
        }
        else
        {
            MarkBoard("player2", pos);
        }
        system("clear");
        printf("\n     Tik Tak Toe\t\t\n");
        printf("Player1 (X) - Player2 (O)\n");
        DrawBoard();
        if (CheckWin("player2") == true)
        {
            printf("Player 2 won\n");
            break;
        }
        if (CheckTie() == true)
        {
            printf("Tie.\n");
            break;
        }
    }
}

void UserInput(int ply_num, int pos, char symbol)
{
    printf("Player%d (%c): ", ply_num, symbol);
    scanf("%d", &pos);
    if (symbol == 'X')
    {
        MarkBoard("player1", pos);
    }
    else if (symbol == 'O')
    {
        MarkBoard("player2", pos);
    }
    else 
    {
        fprintf(stderr, "ERR: SYMBOL DOESN'T EXIST");
        exit(EXIT_FAILURE);
    }
    DrawBoard();
}

// Prints The 3x3 Tik Tak Toe Board

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

// Marking the board

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

// Checking for the winner

bool CheckTie(void)
{

    if (
        IsMarkAble[0] == false && IsMarkAble[1] == false && IsMarkAble[2] == false && IsMarkAble[3] == false && IsMarkAble[4] == false && IsMarkAble[5] == false && IsMarkAble[6] == false && IsMarkAble[7] == false && IsMarkAble[8] == false)
    {
        return true;
    }

    return false;
}

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
