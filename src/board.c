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
    board->weight[0][1] = 2;
    board->weight[0][2] = 3;

    board->weight[1][0] = 2;
    board->weight[1][1] = 4;
    board->weight[1][2] = 2;

    board->weight[2][0] = 3;
    board->weight[2][1] = 2;
    board->weight[2][2] = 3;
}

Location *GetWeight(Board *board)
{
    int max_weight = 0;
    int last_row = -1;
    int last_col = -1;

    assert(board);
    for(int row = 0; row < BOARD_ROWS; row++)
    {
        for(int col = 0; col < BOARD_COLS; col++)
        {
            if(board->weight[row][col] > max_weight)
            {
                max_weight = board->weight[row][col];
                last_col = col;
                last_row = row;
            }
        }
    }
    Location *loc = malloc(sizeof(Location));
    loc->row = last_row;
    loc->col = last_col;
    return(loc);
}

void PlaceBoard(Board *board, int status, int row, int col)
{
    assert(board);
    assert(row >= 0);
    assert(row < BOARD_ROWS);
    assert(col >= 0);
    assert(col < BOARD_COLS);

    board->board[row][col] = status;
    board->weight[row][col] = 0;
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

    myCol = 0;
    int row = 0;
    int col = 0;
    int saved_row = 0;
    int saved_col = 0;

    while(row < BOARD_ROWS)
    {
        while(col < BOARD_COLS)
        {
            if(board->board[row][col] == status)
            {
                myCol++;
            } else if(board->board[row][col] == 0)
            {
                saved_row = row;
                saved_col = col;
            }
            row++;
            col++;
        }
    }

    if(myCol == 2)
    {
        Location *loc = malloc(sizeof(Location));
        loc->row = saved_row;
        loc->col = saved_col;
        return(loc);
    }

    myCol = 0;
    row = 0;
    col = BOARD_COLS - 1;
    saved_row = 0;
    saved_col = 0;

    while(row < BOARD_ROWS)
    {
        while(col >= 0)
        {
            if(board->board[row][col] == status)
            {
                myCol++;
            } else if(board->board[row][col] == 0)
            {
                saved_row = row;
                saved_col = col;
            }
            row++;
            col--;
        }
    }

    if(myCol == 2)
    {
        Location *loc = malloc(sizeof(Location));
        loc->row = saved_row;
        loc->col = saved_col;
        return(loc);
    }

    return(NULL);
}
