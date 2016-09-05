#include <stdlib.h>
#include <assert.h>

#ifndef TIC_BOARD_H
#include "board.h"
#endif

Board *MakeBoard(void)
{
    Board *board = malloc(sizeof(Board));
    return(board);
}

void InitBoard(Board *board)
{
    assert(board);
    for(int rows = 0; rows < BOARD_ROWS; rows++)
    {
        for(int cols = 0; cols < BOARD_COLS; cols++)
        {
            board->board[rows][cols] = 0;
            board->weight[rows][cols] = 0;
        }
    }
    board->weight[0][0] = 3;
    board->weight[0][2] = 3;
    board->weight[2][0] = 3;
    board->weight[2][2] = 3;

    board->weight[0][1] = 1;
    board->weight[1][0] = 1;
    board->weight[1][2] = 1;

    board->weight[2][1] = 1;
}

void PlaceBoard(Board *board, int status, int row, int col)
{
    assert(board);
    assert(row >= 0);
    assert(row < BOARD_ROWS);
    assert(col >= 0);
    assert(col < BOARD_COLS);

    board->board[row][col] = status;
}

int BoardWin(Board *board, int status)
{
    assert(board);

    return(
    ((board->board[0][0] == status) &&
    (board->board[0][1] == status) &&
    (board->board[0][2] == status)) ||

    ((board->board[1][0] == status) &&
    (board->board[1][1] == status) &&
    (board->board[1][2] == status)) ||

    ((board->board[2][0] == status) &&
    (board->board[2][1] == status) &&
    (board->board[2][2] == status)) ||

    ((board->board[0][0] == status) &&
    (board->board[1][0] == status) &&
    (board->board[2][0] == status)) ||

    ((board->board[0][1] == status) &&
    (board->board[1][1] == status) &&
    (board->board[2][1] == status)) ||

    ((board->board[0][2] == status) &&
    (board->board[1][2] == status) &&
    (board->board[2][2] == status)) ||

    ((board->board[0][0] == status) &&
    (board->board[1][1] == status) &&
    (board->board[2][2] == status)) ||

    ((board->board[0][2] == status) &&
    (board->board[1][1] == status) &&
    (board->board[2][0] == status)));
}
