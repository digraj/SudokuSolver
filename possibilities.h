#pragma once

#include "main.h"
#include "readWrite.h"
#include "boxFlatten.h"
#include "solution.h"

bool isInRow (
    grid *board,
    int value,
    int row
);

bool isInBox(
    grid* board,
    int value,
    int flatRow
);

bool isInCol (
    grid *board,
    int value,
    int col
);

bool isValid (
    grid *board,
    grid* boxBoard,
    int value,
    int row,
    int col,
    int flatRow,
    int flatCol 
);

void getPossibilities (
    grid *board,
    grid* boxBoard,
    int row,
    int col
);

void createPossibilitiesArray (
    grid* board, 
    grid* boxBoard
);

void dumpPossibilitiesArray (
    grid *board,
    int row,
    int col
);

int possibilityArraySum (
    cell gridCell
);

int getOnlyValue (
    cell gridCell
);

bool fillSinglePossibilities (
    grid *board,
    grid *boxBoard,
    bool *isSolved
);