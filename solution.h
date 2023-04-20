#pragma once

#include "main.h"
#include "possibilities.h"
#include "boxFlatten.h"
#include "readWrite.h"

void firstPass (
    grid *board,
    grid *boxBoard
);

void setup (
    grid *originalBoard,
    grid *boxBoard,
    char *fileName
);

void isComplete (
    grid *board,
    bool *isSolved
);

void getNextRowCol (
    grid *board,
    int row,
    int col,
    int *nextRow,
    int *nextCol
);

void solution (
    grid board,
    grid boxBoard,
    int row,
    int col,
    bool *isSolved,
    grid *finalBoard
);