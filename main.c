#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "main.h"

int main (
    int argc, 
    char *argv[]
)  {
    char *fileName = argv[1];
    grid originalBoard, board, boxBoard;
    readGrid(&originalBoard, fileName);
    board = originalBoard;
    bool noChange = false;
    printf("Original Grid:\n\n");
    printGrid(&board);
    makeBoxGrid(&board, &boxBoard);
    // printGrid(&boxBoard);
    while (!noChange) {
        createPossibilitiesArray(&board, &boxBoard);
        noChange = fillSinglePossibilities(&board, &boxBoard);
    }
    printGrid(&board);
    // printGrid(&boxBoard);

    // dumpPossibilitiesArray(&board, 0, 3);

    return 0;
}