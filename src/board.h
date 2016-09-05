#ifndef TIC_BOARD_H
#define TIC_BOARD_H

#define BOARD_ROWS  3
#define BOARD_COLS  3

typedef struct _board {
    int board[BOARD_ROWS][BOARD_COLS];
    int weight[BOARD_ROWS][BOARD_COLS];
} Board;

typedef struct _location {
    int row;
    int col;
} Location;

Board *MakeBoard(void);
void InitBoard(Board *board);
void PlaceBoard(Board *board, int status, int row, int col);
int BoardWin(Board *board, int status);
Location *AboutToWin(Board *board, int status);
Location *GetWeight(Board *board);

#endif //TIC_BOARD_H
