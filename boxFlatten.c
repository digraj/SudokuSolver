#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "boxFlatten.h"

void getFlattenedRowCol (
    int row,
    int col,
    int *flatRow,
    int *flatCol
) {
    if (row >= ROWMAX) {
        return;
    }
    if (row >= COLMAX) {
        return;
    }

    switch (row) {
         case 0:
            switch (col) {
                case 0: *flatRow = 0; *flatCol = 0; return;
                case 1: *flatRow = 0; *flatCol = 1; return;
                case 2: *flatRow = 0; *flatCol = 2; return;
                case 3: *flatRow = 1; *flatCol = 0; return;
                case 4: *flatRow = 1; *flatCol = 1; return;
                case 5: *flatRow = 1; *flatCol = 2; return;
                case 6: *flatRow = 2; *flatCol = 0; return;
                case 7: *flatRow = 2; *flatCol = 1; return;
                case 8: *flatRow = 2; *flatCol = 2; return;
            }
        case 1:
            switch (col) {
                case 0: *flatRow = 0; *flatCol = 3; return;
                case 1: *flatRow = 0; *flatCol = 4; return;
                case 2: *flatRow = 0; *flatCol = 5; return;
                case 3: *flatRow = 1; *flatCol = 3; return;
                case 4: *flatRow = 1; *flatCol = 4; return;
                case 5: *flatRow = 1; *flatCol = 5; return;
                case 6: *flatRow = 2; *flatCol = 3; return;
                case 7: *flatRow = 2; *flatCol = 4; return;
                case 8: *flatRow = 2; *flatCol = 5; return;
            }
        case 2:
            switch (col) {
                case 0: *flatRow = 0; *flatCol = 6; return;
                case 1: *flatRow = 0; *flatCol = 7; return;
                case 2: *flatRow = 0; *flatCol = 8; return;
                case 3: *flatRow = 1; *flatCol = 6; return;
                case 4: *flatRow = 1; *flatCol = 7; return;
                case 5: *flatRow = 1; *flatCol = 8; return;
                case 6: *flatRow = 2; *flatCol = 6; return;
                case 7: *flatRow = 2; *flatCol = 7; return;
                case 8: *flatRow = 2; *flatCol = 8; return;
            }
        case 3: 
            switch (col) {
                case 0: *flatRow = 3; *flatCol = 0; return;
                case 1: *flatRow = 3; *flatCol = 1; return;
                case 2: *flatRow = 3; *flatCol = 2; return;
                case 3: *flatRow = 4; *flatCol = 0; return;
                case 4: *flatRow = 4; *flatCol = 1; return;
                case 5: *flatRow = 4; *flatCol = 2; return;
                case 6: *flatRow = 5; *flatCol = 0; return;
                case 7: *flatRow = 5; *flatCol = 1; return;
                case 8: *flatRow = 5; *flatCol = 2; return;
            }
        case 4: 
            switch (col) {
                case 0: *flatRow = 3; *flatCol = 3; return;
                case 1: *flatRow = 3; *flatCol = 4; return;
                case 2: *flatRow = 3; *flatCol = 5; return;
                case 3: *flatRow = 4; *flatCol = 3; return;
                case 4: *flatRow = 4; *flatCol = 4; return;
                case 5: *flatRow = 4; *flatCol = 5; return;
                case 6: *flatRow = 5; *flatCol = 3; return;
                case 7: *flatRow = 5; *flatCol = 4; return;
                case 8: *flatRow = 5; *flatCol = 5; return;
            }
        case 5:
            switch (col) {
                case 0: *flatRow = 3; *flatCol = 6; return;
                case 1: *flatRow = 3; *flatCol = 7; return;
                case 2: *flatRow = 3; *flatCol = 8; return;
                case 3: *flatRow = 4; *flatCol = 6; return;
                case 4: *flatRow = 4; *flatCol = 7; return;
                case 5: *flatRow = 4; *flatCol = 8; return;
                case 6: *flatRow = 5; *flatCol = 6; return;
                case 7: *flatRow = 5; *flatCol = 7; return;
                case 8: *flatRow = 5; *flatCol = 8; return;
            }
        case 6:
            switch (col) {
                case 0: *flatRow = 6; *flatCol = 0; return;
                case 1: *flatRow = 6; *flatCol = 1; return;
                case 2: *flatRow = 6; *flatCol = 2; return;
                case 3: *flatRow = 7; *flatCol = 0; return;
                case 4: *flatRow = 7; *flatCol = 1; return;
                case 5: *flatRow = 7; *flatCol = 2; return;
                case 6: *flatRow = 8; *flatCol = 0; return;
                case 7: *flatRow = 8; *flatCol = 1; return;
                case 8: *flatRow = 8; *flatCol = 2; return;
            }
        case 7:
            switch (col) {
                case 0: *flatRow = 6; *flatCol = 3; return;
                case 1: *flatRow = 6; *flatCol = 4; return;
                case 2: *flatRow = 6; *flatCol = 5; return;
                case 3: *flatRow = 7; *flatCol = 3; return;
                case 4: *flatRow = 7; *flatCol = 4; return;
                case 5: *flatRow = 7; *flatCol = 5; return;
                case 6: *flatRow = 8; *flatCol = 3; return;
                case 7: *flatRow = 8; *flatCol = 4; return;
                case 8: *flatRow = 8; *flatCol = 5; return;
            }
        case 8:
            switch (col) {
                case 0: *flatRow = 6; *flatCol = 6; return;
                case 1: *flatRow = 6; *flatCol = 7; return;
                case 2: *flatRow = 6; *flatCol = 8; return;
                case 3: *flatRow = 7; *flatCol = 6; return;
                case 4: *flatRow = 7; *flatCol = 7; return;
                case 5: *flatRow = 7; *flatCol = 8; return;
                case 6: *flatRow = 8; *flatCol = 6; return;
                case 7: *flatRow = 8; *flatCol = 7; return;
                case 8: *flatRow = 8; *flatCol = 8; return;
            }
        default: return; //THIS SHOULD NOT HAPPEN
    }
}

void makeBoxGrid (
    grid *board,
    grid *boxBoard
) {
    int row, col;
    int flatRow, flatCol;
    flatRow = flatCol = -1;

    for (row = 0; row < ROWMAX; row++) {
        for (col = 0; col < COLMAX; col++) {
            getFlattenedRowCol(row, col, &flatRow, &flatCol);
            (boxBoard->board[flatRow][flatCol]).value = (board->board[row][col]).value;
        }
    }

    return;
}