#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "main.h"

void firstPass (
    grid *board,
    grid *boxBoard
) {
    bool isSolved = true;
    bool noChange = false;
    while (!noChange) {
        createPossibilitiesArray(board, boxBoard);
        noChange = fillSinglePossibilities(board, boxBoard, &isSolved);
    }
    board->solved = isSolved;
    return;
}

void setup (
    grid *originalBoard,
    grid *boxBoard,
    char *fileName
) {
    readGrid(originalBoard, fileName);
    makeBoxGrid(originalBoard, boxBoard);
    return;
}

void isComplete (
    grid *board,
    bool *isSolved
) {
    *isSolved = true;
    int row, col;

    for (row = 0; row < ROWMAX; row++) {
        for (col = 0; col < COLMAX; col++) {
            if (!(board->board[row][col]).isOriginal) {
                *isSolved = false;
                return;
            }
        }
    }

    return;
}

void getNextRowCol (
    grid *board,
    int row,
    int col,
    int *nextRow,
    int *nextCol
) {
    int rowi, coli;
    *nextRow = row;
    *nextCol = col;

    if (col < COLMAX - 1) {
        for (coli = col + 1; coli < COLMAX; coli++) {
            if (!board->board[row][coli].isOriginal) {
                *nextCol = coli;
                return;
            }
        }
    }

    for (rowi = row; rowi < ROWMAX; rowi++) {
        for (coli = 0; coli < COLMAX; coli++) {
            if (!board->board[rowi][coli].isOriginal) {
                *nextRow = rowi;
                *nextCol = coli;
                return;
            }
        }
    }
}

void solution (
    grid board,
    grid boxBoard,
    int row,
    int col,
    bool *isSolved,
    grid *finalBoard
) {
    int i;
    int nextRow, nextCol;
    nextRow = nextCol = 0;

    while (!(*isSolved) & (col < COLMAX) & (row < ROWMAX)) {
        for (i = 0; i < MAXVAL; i++) {
            if (board.board[row][col].possible[i]) {
                board.board[row][col].value = i+1;
                board.board[row][col].isOriginal = true;
                createPossibilitiesArray(&board, &boxBoard);
                isComplete(&board, isSolved);
                if (*isSolved) {
                    *finalBoard = board;
                    return;
                }
                getNextRowCol(&board, row, col, &nextRow, &nextCol);
                solution(board, boxBoard, nextRow, nextCol, isSolved, finalBoard);
                if (*isSolved) {
                    return;
                }
            }
        }
        return;
    }

    return;
}

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