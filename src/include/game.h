#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

extern char board[][5];
extern bool IsMarkAble[];
extern bool IsPlayer;
extern int DifficultyLevel;

typedef struct {
    int move;
    int score;
} MoveScore;


// Define fucntions
void GetHelp();
void Game();
void DrawBoard(void);
void MarkBoard(char *user, int pos);
bool CheckWin(char *user);
bool CheckTie(void);
void UserInput(int ply_num, int pos, char symbol);
void SaveBoard(bool Save, char board[5][5]);
void ClearBoard(int pos);
int EvaluateBoard(int depth);
MoveScore Minimax(char *player, char mark, int depth);
void Clean(void);
void SetDifficulty(void);

 
#endif