#include <assert.h>

#include "unity.h"
#include "unity_fixture.h"

#include "ProductionCode.h"

TEST_GROUP(ProductionCode);

TEST_SETUP(ProductionCode)
{
}

TEST_TEAR_DOWN(ProductionCode)
{
}

TEST(ProductionCode, TestMakeBoard)
{
    Board *board = MakeBoard();
    TEST_ASSERT_NOT_NULL(board);
}

TEST(ProductionCode, TestInitBoard)
{
    Board *board = MakeBoard();
    InitBoard(board);
    for(int rows = 0; rows < BOARD_ROWS; rows++)
    {
        for(int cols = 0; cols < BOARD_COLS; cols++)
        {
            TEST_ASSERT(board->board[rows][cols] == 0);
        }
    }
}

TEST(ProductionCode, TestPlaceBoard)
{
    Board *board = MakeBoard();
    InitBoard(board);
    PlaceBoard(board, 1, 0, 0);
    TEST_ASSERT(board->board[0][0] == 1);
}

TEST(ProductionCode, TestWinBoard)
{
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 0);
    PlaceBoard(board, 1, 0, 1);
    PlaceBoard(board, 1, 0, 2);

    TEST_ASSERT_TRUE(BoardWin(board, 1));

    InitBoard(board);
    PlaceBoard(board, 1, 1, 0);
    PlaceBoard(board, 1, 1, 1);
    PlaceBoard(board, 1, 1, 2);

    TEST_ASSERT_TRUE(BoardWin(board, 1));
}
