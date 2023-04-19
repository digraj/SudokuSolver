#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "readWrite.h"

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