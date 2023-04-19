#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "possibilities.h"

bool isInRow (
    grid *board,
    int value,
    int row
) {
    int i;
    bool retVal = false;

    for (i = 0; i < COLMAX; i++) {
        // printf("COLVAL: %d \n", (board->board[row][i]).value);
        retVal = (board->board[row][i]).value == value ? true : false;
        if (retVal) { goto End; }
    }

End:
    // printf("row: %d %d %d %d\n", value, row, i, retVal);
    return retVal;
}

bool isInBox(
    grid* board,
    int value,
    int flatRow
) {
    return isInRow(board, value, flatRow);
}


bool isInCol (
    grid *board,
    int value,
    int col
) {
    int i;
    bool retVal = false;

    for (i = 0; i < ROWMAX; i++) {
        retVal = ((board->board[i][col]).value == value) ? true : false;
        if (retVal) { goto End; }
    }

End:
    // printf("col: %d\n", retVal);
    return retVal;
}


bool isValid (
    grid *board,
    grid* boxBoard,
    int value,
    int row,
    int col,
    int flatRow,
    int flatCol 
) {
    UNUSED(flatCol);
    // printf("value: %d \n", value);
    return (!(isInRow(board, value, row)) & !(isInCol(board, value, col)) & !(isInBox(boxBoard, value, flatRow)));
}

void getPossibilities (
    grid *board,
    grid* boxBoard,
    int row,
    int col
) {
    int flatRow, flatCol, i;
    flatRow = flatCol = -1;
    getFlattenedRowCol(row, col, &flatRow, &flatCol);

    for (i = 0; i < MAXVAL; i++) {
        (board->board[row][col]).possible[i] = isValid(board, boxBoard, i + 1, row, col, flatRow, flatCol);
    }
}

void createPossibilitiesArray (
    grid* board, 
    grid* boxBoard
) {
    int row, col;
    row = col = 0;
    for (row = 0; row < ROWMAX; row++) {
        for (col = 0; col < COLMAX; col++) {
            if (!(board->board[row][col]).isOriginal) {
                // printf("%d %d\n", row, col);
                getPossibilities(board, boxBoard, row, col);
            }
        }
    }    

    return;
}

void dumpPossibilitiesArray (
    grid *board,
    int row,
    int col
) {
    int i;
    for (i = 0; i < MAXVAL; i++) {
        printf("%d ", (board->board[row][col]).possible[i]);
    }
}

int possibilityArraySum (
    cell gridCell
) {
    int retVal, i;
    retVal = i = 0;

    for (i = 0; i < MAXVAL; i++) {
        retVal += gridCell.possible[i];
    }
    return retVal;
}

int getOnlyValue (
    cell gridCell
) {
    int i = 0;

    for (i = 0; i < MAXVAL; i++) {
        if (gridCell.possible[i]) {
            return ++i;
        }
    }
    return 0;
}

bool fillSinglePossibilities (
    grid *board,
    grid *boxBoard
) {
    int row, col, psum, flatRow, flatCol, i;
    bool retVal = true;
    flatRow = flatCol = -1;
    row = col = 0;

    for (row = 0; row < ROWMAX; row++) {
        for (col = 0; col < COLMAX; col++) {
            if (!(board->board[row][col]).isOriginal) {
                psum = possibilityArraySum(board->board[row][col]);
                // printf("psum: %d row: %d col: %d \n", psum, row, col);
                if (psum == 1) {
                    getFlattenedRowCol(row, col, &flatRow, &flatCol);
                    board->board[row][col].value = getOnlyValue(board->board[row][col]);
                    boxBoard->board[flatRow][flatCol].value = board->board[row][col].value;
                    // printf("value: %d\n", board->board[row][col].value);
                    (board->board[row][col]).isOriginal = true;
                    retVal = false;
                }
            }
        }
    }

    return retVal;
}