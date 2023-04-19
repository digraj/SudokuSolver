#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

void printNewLine () {
    printf(" --- --- --- --- --- --- --- --- --- ");
    return;
}

void printGrid (
    grid *board
) {
    int row, col, rowName, num;
    num = rowName = 65;
    
    printf("    1   2   3   4   5   6   7   8   9\n");
    for (row = 0; row < ROWMAX; row++) {
        printf("  ");
        printNewLine();
        printf("\n%c |", rowName++);
        for (col = 0; col < ROWMAX; col++) {
            num = (board->board[row][col]).value;
            if (num != 0) {
                printf(" %d |", num);
            } else {
                printf ("   |");
            }
        }
        printf("\n");
    }
    printf("  ");
    printNewLine();
    printf("\n\n");
    return;
}

void readGrid (
    grid* board,
    char *fileName
) {
    char num;
    int row,col;
    num = row = col = 0;
    printf("SOLVING: %s\n\n", fileName);
    FILE *openedFile = fopen(fileName, "r");
    fseek(openedFile, 0, SEEK_SET);

    while ((num = fgetc(openedFile)) != EOF) {
        switch (num) {
            case '\r': continue;
            case '\n': row++; col = 0; continue;
            case '.': num = 0; (board->board[row][col]).isOriginal = false; break;
            default: num -= 48; (board->board[row][col]).isOriginal = true;
        }
        (board->board[row][col++]).value = num;
    }

    fclose(openedFile);
    return;
}

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
    grid* boxBoard)
{
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