#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "main.h"

int main (
    int argc, 
    char *argv[]
)  {
    char *fileName = argv[1];
    grid originalBoard, board, boxBoard, finalBoard;
    setup(&originalBoard, &boxBoard, fileName);
    board = originalBoard;
    printf("Original Grid:\n\n");
    printGrid(&board);
    firstPass(&board, &boxBoard);
    finalBoard = board;
    bool isSolved = false;
    if (!board.solved) {
        solution(board, boxBoard, 0, 0, &isSolved, &finalBoard);
    }
    printf("Solved Grid:\n\n");
    printGrid(&finalBoard);
    return 0;
}