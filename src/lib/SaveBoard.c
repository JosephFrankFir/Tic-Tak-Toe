#include <stdio.h>
#include <stdlib.h>
#include "../include/game.h"

void SaveBoard(bool Save, char board[5][5])
{
   if (Save == true)
   {
      FILE *f = fopen("Board.txt", "a+"); // open the file for writing
      if (f != NULL)                     // check for success
      {
         for (int i = 0; i < 5; ++i)
         {
            fprintf(f,"\n");
            fprintf(f,"\t");
            for (int k = 0; k < 5; k++)
            {
               fprintf(f, "%c", board[i][k]);
            }
            fprintf(f,"\n\n");
         }
         
         fclose(f); // close the file
         f = NULL;  // set file handle to null since f is no longer valid
      }
      }
}