#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(ProductionCode)
{
    RUN_TEST_CASE(ProductionCode, TestMakeBoard);
    RUN_TEST_CASE(ProductionCode, TestInitBoard);
    RUN_TEST_CASE(ProductionCode, TestPlaceBoardVacant);
    RUN_TEST_CASE(ProductionCode, TestPlaceBoardTaken1);
    RUN_TEST_CASE(ProductionCode, TestPlaceBoardTaken2);
    RUN_TEST_CASE(ProductionCode, TestWinBoard);
    RUN_TEST_CASE(ProductionCode, TestAboutToWinBoardRow0);
    RUN_TEST_CASE(ProductionCode, TestAboutToWinBoardRow1);
    RUN_TEST_CASE(ProductionCode, TestAboutToWinBoardRow2);
    RUN_TEST_CASE(ProductionCode, TestAboutToWinBoardCol0);
    RUN_TEST_CASE(ProductionCode, TestAboutToWinBoardCol1);
    RUN_TEST_CASE(ProductionCode, TestAboutToWinBoardCol2);
    RUN_TEST_CASE(ProductionCode, TestAboutToWinBoardCross1);
    RUN_TEST_CASE(ProductionCode, TestAboutToWinBoardCross2);
    RUN_TEST_CASE(ProductionCode, TestAboutToWinBoardCross3);
    RUN_TEST_CASE(ProductionCode, TestAboutToWinBoardCross4);
    RUN_TEST_CASE(ProductionCode, TestAboutToWinBoardCross5);
    RUN_TEST_CASE(ProductionCode, TestWeight1);
    RUN_TEST_CASE(ProductionCode, TestWeight2);
    RUN_TEST_CASE(ProductionCode, TestWeightAfterPlacement);
    RUN_TEST_CASE(ProductionCode, TestNextMove);
    RUN_TEST_CASE(ProductionCode, TestWinningMove);
    RUN_TEST_CASE(ProductionCode, TestMove1);
    RUN_TEST_CASE(ProductionCode, TestMove2);
    RUN_TEST_CASE(ProductionCode, TestPlay);
}
