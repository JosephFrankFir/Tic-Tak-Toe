#include "../include/game.h"

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
        #if _WIN32
            system("cls");
        #elif __linux__
            system("clear");
        #endif

        
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
        #if _WIN32
            system("cls");
        #elif __linux__
            system("clear");
        #endif

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
