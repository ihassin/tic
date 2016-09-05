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
int BoardFull(Board *board);
int PlaceBoard(Board *board, int player, int row, int col);
int BoardWin(Board *board, int player);
Location *Move(Board *board, int player);
Location *AboutToWin(Board *board, int player);
Location *GetWeight(Board *board);
int PlayProgrammatic(int player);

#endif //TIC_BOARD_H
