#ifndef TIC_BOARD_H
#define TIC_BOARD_H

#include <mach/i386/boolean.h>

#define BOARD_ROWS  3
#define BOARD_COLS  3

typedef struct _board {
    int board[BOARD_ROWS][BOARD_COLS];
    int weight[BOARD_ROWS][BOARD_COLS];
} Board;

Board *MakeBoard(void);
void InitBoard(Board *board);
void PlaceBoard(Board *board, int status, int row, int col);
int BoardWin(Board *board, int status);

#endif //TIC_BOARD_H
