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

TEST(ProductionCode, TestAboutToWinBoardRow0)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 0);
    PlaceBoard(board, 1, 0, 1);

    location = AboutToWin(board, 1);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 0) && (location->col == 2));
}

TEST(ProductionCode, TestAboutToWinBoardRow1)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 0);
    PlaceBoard(board, 1, 0, 2);

    location = AboutToWin(board, 1);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 0) && (location->col == 1));
}

TEST(ProductionCode, TestAboutToWinBoardRow2)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 1);
    PlaceBoard(board, 1, 0, 2);

    location = AboutToWin(board, 1);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 0) && (location->col == 0));
}

TEST(ProductionCode, TestAboutToWinBoardCol0)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 0);
    PlaceBoard(board, 1, 1, 0);

    location = AboutToWin(board, 1);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 2) && (location->col == 0));
}

TEST(ProductionCode, TestAboutToWinBoardCol1)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 0);
    PlaceBoard(board, 1, 2, 0);

    location = AboutToWin(board, 1);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 1) && (location->col == 0));
}

TEST(ProductionCode, TestAboutToWinBoardCol2)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 1, 0);
    PlaceBoard(board, 1, 2, 0);

    location = AboutToWin(board, 1);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 0) && (location->col == 0));
}

TEST(ProductionCode, TestAboutToWinBoardCross1)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 0);
    PlaceBoard(board, 1, 1, 1);

    location = AboutToWin(board, 1);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 2) && (location->col == 2));
}

TEST(ProductionCode, TestAboutToWinBoardCross2)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 0);
    PlaceBoard(board, 1, 2, 2);

    location = AboutToWin(board, 1);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 1) && (location->col == 1));
}

TEST(ProductionCode, TestAboutToWinBoardCross3)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 2);
    PlaceBoard(board, 1, 1, 1);

    location = AboutToWin(board, 1);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 2) && (location->col == 0));
}

TEST(ProductionCode, TestAboutToWinBoardCross4)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 2, 0);
    PlaceBoard(board, 1, 1, 1);

    location = AboutToWin(board, 1);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 0) && (location->col == 2));
}

TEST(ProductionCode, TestAboutToWinBoardCross5)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 2);
    PlaceBoard(board, 1, 2, 0);

    location = AboutToWin(board, 1);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 1) && (location->col == 1));
}
