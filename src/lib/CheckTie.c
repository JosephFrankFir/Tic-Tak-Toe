#include "../include/game.h"



bool CheckTie(void)
{

    if (
        IsMarkAble[0] == false && IsMarkAble[1] == false && IsMarkAble[2] == false && IsMarkAble[3] == false && IsMarkAble[4] == false && IsMarkAble[5] == false && IsMarkAble[6] == false && IsMarkAble[7] == false && IsMarkAble[8] == false)
    {
        return true;
    }

    return false;
}
