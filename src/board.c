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
    for(int row = 0; row < BOARD_ROWS; row++)
    {
        for(int col = 0; col < BOARD_COLS; col++)
        {
            board->board[row][col] = 0;
            board->weight[row][col] = 0;
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
    board->weight[1][1] = 4;
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

Location *AboutToWin(Board *board, int status)
{
    assert(board);

    int free = 0;
    int myCol = 0;

    for(int row = 0; row < BOARD_ROWS; row++)
    {
        for(int col = 0; col < BOARD_COLS; col++)
        {
            if(board->board[row][col] == status)
            {
                myCol++;
            } else if(board->board[row][col] == 0) {
                free++;
            }

            if((myCol == 2) && (free == 1))
            {
                Location *loc = malloc(sizeof(Location));
                loc->row = row;
                for(col = 0; col < BOARD_COLS; col++)
                {
                    if(board->board[row][col] == 0)
                    {
                        loc->col = col;
                    }
                }
                return(loc);
            }
        }
        myCol = 0;
        free = 0;
    }

    myCol = 0;
    free = 0;
    for(int col = 0; col < BOARD_COLS; col++)
    {
        for(int row = 0; row < BOARD_ROWS; row++)
        {
            if(board->board[row][col] == status)
            {
                myCol++;
            } else if(board->board[row][col] == 0) {
                free++;
            }

            if((myCol == 2) && (free == 1))
            {
                Location *loc = malloc(sizeof(Location));
                loc->col = col;
                for(row = 0; row < BOARD_ROWS; row++)
                {
                    if(board->board[row][col] == 0)
                    {
                        loc->row = row;
                    }
                }
                return(loc);
            }
        }
    }
    return(NULL);
}
