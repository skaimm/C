#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "oyun.h"
int main()
{
    int i;
    createArea();
    listOfHighScore();
    startGame();
    freeMalloc();

    return 0;
}

