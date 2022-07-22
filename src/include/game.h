#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

extern char board[][5];
extern bool IsMarkAble[];

// Define fucntions
int GetHelp(int argc, char *argv[]);
void Game(void);
void DrawBoard(void);
void MarkBoard(char *user, int pos);
bool CheckWin(char *user);
bool CheckTie(void);
void UserInput(int ply_num, int pos, char symbol);
 

#endif