#pragma once

#include "main.h"
#include "possibilities.h"
#include "readWrite.h"
#include "solution.h"

void getFlattenedRowCol (
    int row,
    int col,
    int *flatRow,
    int *flatCol
);

void makeBoxGrid (
    grid *board,
    grid *boxBoard
);