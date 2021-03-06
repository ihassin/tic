#include <assert.h>
#include "unity_fixture_malloc_overrides.h"

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

int BoardFull(Board *board)
{
    assert(board);

    for(int row = 0; row < BOARD_ROWS; row++)
    {
        for(int col = 0; col < BOARD_COLS; col++)
        {
            if(board->board[row][col] == 0)
            {
                return(0);
            }
        }
    }
    return(1);
}

int BoardWin(Board *board, int player)
{
    assert(board);

    return(
        ((board->board[0][0] == player) &&
        (board->board[0][1] == player) &&
        (board->board[0][2] == player)) ||

        ((board->board[1][0] == player) &&
        (board->board[1][1] == player) &&
        (board->board[1][2] == player)) ||

        ((board->board[2][0] == player) &&
        (board->board[2][1] == player) &&
        (board->board[2][2] == player)) ||

        ((board->board[0][0] == player) &&
        (board->board[1][0] == player) &&
        (board->board[2][0] == player)) ||

        ((board->board[0][1] == player) &&
        (board->board[1][1] == player) &&
        (board->board[2][1] == player)) ||

        ((board->board[0][2] == player) &&
        (board->board[1][2] == player) &&
        (board->board[2][2] == player)) ||

        ((board->board[0][0] == player) &&
        (board->board[1][1] == player) &&
        (board->board[2][2] == player)) ||

        ((board->board[0][2] == player) &&
        (board->board[1][1] == player) &&
        (board->board[2][0] == player)));
}

Location *AboutToWin(Board *board, int player)
{
    assert(board);

    int free = 0;
    int myCol = 0;

    for(int row = 0; row < BOARD_ROWS; row++)
    {
        myCol = 0;
        free = 0;
        for(int col = 0; col < BOARD_COLS; col++)
        {
            if(board->board[row][col] == player)
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
    }

    myCol = 0;
    free = 0;
    for(int col = 0; col < BOARD_COLS; col++)
    {
        myCol = 0;
        free = 0;
        for(int row = 0; row < BOARD_ROWS; row++)
        {
            if(board->board[row][col] == player)
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
            if(board->board[row][col] == player)
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
            if(board->board[row][col] == player)
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

Location *GetWeight(Board *board)
{
    assert(board);

    int max_weight = 0;
    int last_row = -1;
    int last_col = -1;

    for(int row = 0; row < BOARD_ROWS; row++)
    {
        for(int col = 0; col < BOARD_COLS; col++)
        {
            if(board->weight[row][col] > max_weight)
            {
                max_weight = board->weight[row][col];
                last_row = row;
                last_col = col;
            }
        }
    }
    if(last_row == -1 || last_col == -1)
    {
        return(NULL);
    }
    Location *loc = malloc(sizeof(Location));
    loc->row = last_row;
    loc->col = last_col;
    return(loc);
}

int PlaceBoard(Board *board, int player, int row, int col)
{
    assert(board);
    assert((row >= 0) && (row < BOARD_ROWS));
    assert((col >= 0) && (col < BOARD_COLS));

    if(board->board[row][col] == 0)
    {
        board->board[row][col] = player;
        board->weight[row][col] = 0;
        return(1);
    }
    return(0);
}

Location *Move(Board *board, int player)
{
    Location *location = AboutToWin(board, player);
    if(location) {
        if(PlaceBoard(board, player, location->row, location->col)) {
            return(location);
        }
        free(location);
    }

    location = AboutToWin(board, (player == 1) ? 2 : 1);
    if(location) {
        if(PlaceBoard(board, player, location->row, location->col)) {
            return(location);
        }
        free(location);
    }

    location = GetWeight(board);
    if (location) {
        if(PlaceBoard(board, player, location->row, location->col) == 1)
        {
            return(location);
        }
        free(location);
    }
    return(NULL);
}

int PlayProgrammatic(int player)
{
    assert(player == 1 || player == 2);

    Board *board = MakeBoard();

    InitBoard(board);

    while(!BoardFull(board)) {
        for(int idx = 1; idx <= 2; idx++) {
            if(BoardWin(board, idx)) {
                free(board);
                return(idx);
            }
        }
        Location *location = Move(board, (player == 1) ? 2 : 1);
        free(location);
        if(!location) {
            break;
        }
    }
    free(board);
    return(0);
}
