#define ROWMAX      9
#define COLMAX      9
#define MAXVAL      9
#define UNUSED(VAL)     (void) VAL

typedef struct _cell {
    int value;
    bool isOriginal;
    int possible[MAXVAL];
} cell;

typedef struct _grid {
    cell board[ROWMAX][COLMAX];
} grid;