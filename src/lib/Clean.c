#include "../include/game.h"
void Clean(void)
{
    #if _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #elif __APPLE__
        #include <TargetConditionals.h>
        #if TARGET_OS_MAC
            system("clear");
        #endif
    #endif
}
