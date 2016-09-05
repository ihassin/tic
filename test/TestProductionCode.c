#include <assert.h>

#include "unity.h"
#include "unity_fixture.h"

#include "board.h"

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

TEST(ProductionCode, TestPlaceBoardVacant)
{
    Board *board = MakeBoard();
    InitBoard(board);
    int retVal = PlaceBoard(board, 1, 0, 0);
    TEST_ASSERT_EQUAL_INT(1, retVal);
    TEST_ASSERT(board->board[0][0] == 1);
}

TEST(ProductionCode, TestPlaceBoardTaken1)
{
    Board *board = MakeBoard();
    InitBoard(board);
    board->board[0][0] = 1;
    int retVal = PlaceBoard(board, 1, 0, 0);
    TEST_ASSERT_EQUAL_INT(0, retVal);
}

TEST(ProductionCode, TestPlaceBoardTaken2)
{
    Board *board = MakeBoard();
    InitBoard(board);
    board->board[0][0] = 1;
    int retVal = PlaceBoard(board, 2, 0, 0);
    TEST_ASSERT_EQUAL_INT(0, retVal);
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

TEST(ProductionCode, TestAboutToWin)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 0);
    PlaceBoard(board, 1, 0, 1);
    PlaceBoard(board, 2, 0, 2);

    location = AboutToWin(board, 1);
    TEST_ASSERT_NULL(location);
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

TEST(ProductionCode, TestAboutToWinFail1)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 2, 0, 0);
    PlaceBoard(board, 2, 2, 0);
    PlaceBoard(board, 1, 0, 2);
    PlaceBoard(board, 1, 1, 0);
    PlaceBoard(board, 1, 1, 1);

    location = AboutToWin(board, 1);
    TEST_ASSERT_TRUE((location->row == 1) && (location->col == 2));
}

TEST(ProductionCode, TestAboutToWinFail2)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 2);
    PlaceBoard(board, 1, 1, 0);
    PlaceBoard(board, 1, 1, 1);

    PlaceBoard(board, 2, 0, 0);
    PlaceBoard(board, 2, 2, 0);

    location = AboutToWin(board, 2);
    TEST_ASSERT_NULL(location);
}

TEST(ProductionCode, TestAboutToWinFail3)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);

    PlaceBoard(board, 1, 0, 0);
    PlaceBoard(board, 1, 0, 2);

    PlaceBoard(board, 2, 0, 1);
    PlaceBoard(board, 2, 1, 1);

    location = AboutToWin(board, 2);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 2) && (location->col == 1));
}

TEST(ProductionCode, TestMove2Fail)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 2);
    PlaceBoard(board, 1, 1, 0);
    PlaceBoard(board, 1, 1, 1);

    PlaceBoard(board, 2, 0, 0);
    PlaceBoard(board, 2, 2, 0);

    location = Move(board, 2);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 1) && (location->col == 2));
}

TEST(ProductionCode, TestWeight1)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);

    location = GetWeight(board);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 1) && (location->col == 1));
}

TEST(ProductionCode, TestWeight2)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);

    for(int row = 0; row < BOARD_ROWS; row++)
    {
        for(int col = 0; col < BOARD_COLS; col++)
        {
            PlaceBoard(board, 1, row, col);
        }
    }

    location = GetWeight(board);
    TEST_ASSERT_NULL(location);
}

TEST(ProductionCode, TestWeightAfterPlacement)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 1, 1);

    location = GetWeight(board);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE(board->weight[1][1] == 0);
}

TEST(ProductionCode, TestNextMove)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 1, 1);

    location = GetWeight(board);
    TEST_ASSERT_NOT_NULL(location);
    TEST_ASSERT_TRUE((location->row == 0) && (location->col == 0));
}

TEST(ProductionCode, TestWinningMove)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 0);
    PlaceBoard(board, 1, 1, 0);

    location = AboutToWin(board, 1);
    PlaceBoard(board, 1, location->row, location->col);
    TEST_ASSERT_TRUE(BoardWin(board, 1));
}

TEST(ProductionCode, TestMove1)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 0);
    PlaceBoard(board, 1, 1, 0);

    location = Move(board, 1);
    TEST_ASSERT_TRUE((location->row == 2) && (location->col == 0));
    TEST_ASSERT_TRUE(BoardWin(board, 1));
}

TEST(ProductionCode, TestMove2)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);
    PlaceBoard(board, 1, 0, 0);
    PlaceBoard(board, 1, 1, 0);

    location = Move(board, 2);
    TEST_ASSERT_TRUE((location->row == 2) && (location->col == 0));
}

TEST(ProductionCode, TestMove3)
{
    Location *location = NULL;
    Board *board = MakeBoard();

    InitBoard(board);

    for(int row = 0; row < BOARD_ROWS; row++)
    {
        for(int col = 0; col < BOARD_COLS; col++)
        {
            PlaceBoard(board, 1, row, col);
        }
    }
    location = Move(board, 2);
    TEST_ASSERT_NULL(location);
}

TEST(ProductionCode, TestPlay1)
{
    int retVal = PlayProgrammatic(1);
    TEST_ASSERT_TRUE(retVal == 0 || retVal == 1 || retVal == 2);
}

TEST(ProductionCode, TestPlay2)
{
    int retVal = PlayProgrammatic(2);
    TEST_ASSERT_TRUE(retVal == 0 || retVal == 1 || retVal == 2);
}
